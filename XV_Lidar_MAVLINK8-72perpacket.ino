#include <xv11lidar.h>
#include "mavlink/common/mavlink.h"        // Mavlink interface
#include "mavlink/common/mavlink_msg_obstacle_distance.h"

#include <NeoPixelConnect.h>
NeoPixelConnect p(16, 1, pio0, 0);


const int PWM_PIN = 7;
const int RPM = 250;
#define FCbaud 1000000

unsigned long previousMillis = 0;
const long interval = 200;

int lidarAngle = 0;
int messageAngle = 0;
uint16_t distances[72];
int target = 0;
unsigned char data_buffer[4] = {0};
int adjusted = 0;
int distance = 0;
int range = 0;
unsigned char CS;
uint8_t Index;
byte received;

UART Serial2(4, 5, 0, 0);

char serial_buffer[15];

XV11Lidar lidar(Serial1, PWM_PIN );
XV11Packet packet;

void setup()
{
  lidar.setup(RPM);
  Serial.begin(1500000); // USB
  Serial2.begin(1500000); // FC
  memset(distances, UINT16_MAX, sizeof(distances)); // Filling the distances array with UINT16_MAX
  p.neoPixelFill(255, 0, 0, true);
}
int16_t Dist = 0;    // Distance to object in centimeters

void loop()
{
   for (int x = 0 ; x < 90 ; x++)
  {
  bool got_packet;
  got_packet = lidar.processAvailable(&packet);
  if (got_packet){
  lidarAngle = packet.angle_quad;
  messageAngle = map(lidarAngle, 0, 89, 0, 72);
  distances[messageAngle] = (packet.distances[0] / 10);
  lidar.applyMotorPID();
  }
  }
 
    
    p.neoPixelFill(0, 0, 255, true);
    int sysid = 1;
    int compid = 196;
    uint64_t time_usec = 0; /*< Time since system boot*/
    uint8_t sensor_type = 0;
    uint8_t increment = 5;
    uint16_t min_distance = 10; /*< Minimum distance the sensor can measure in centimeters*/
    uint16_t max_distance = 650; /*< Maximum distance the sensor can measure in centimeters*/
    float increment_f = 0;
    float angle_offset = -10;
    uint8_t frame = 12;
    uint8_t system_type = MAV_TYPE_GENERIC;
    uint8_t autopilot_type = MAV_AUTOPILOT_INVALID;
    uint8_t system_mode = MAV_MODE_PREFLIGHT; ///< Booting up
    uint32_t custom_mode = 30;                 ///< Custom mode, can be defined by user/adopter
    uint8_t system_state = MAV_STATE_STANDBY; ///< System ready for flight

    // Initialize the required buffers
    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    int type = MAV_TYPE_GROUND_ROVER;
    // Pack the message

    mavlink_msg_obstacle_distance_pack(sysid, compid, &msg, time_usec, sensor_type, distances, increment, min_distance, max_distance, increment_f, angle_offset, frame);
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    Serial2.write(buf, len);


    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      p.neoPixelFill(0, 255, 0, true);
      mavlink_msg_heartbeat_pack(1, 196, &msg, type, autopilot_type, system_mode, custom_mode, system_state);
      len = mavlink_msg_to_send_buffer(buf, &msg);
      Serial2.write(buf, len);

     
    }
  


  //serial print will slow down the board, disable if not using.
  //  Serial.print("angle ");
  //  Serial.print(lidarAngle);
  //  Serial.print("distance ");
  //  Serial.println((packet.distances[0]));
  //  Serial.println(distances[messageAngle/res]);
}
