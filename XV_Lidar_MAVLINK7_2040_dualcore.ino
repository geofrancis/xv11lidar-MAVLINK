#include <xv11lidar.h>
#include "mavlink/common/mavlink.h"  // Mavlink interface
#include "mavlink/common/mavlink_msg_obstacle_distance.h"

#include <NeoPixelConnect.h>
NeoPixelConnect p(16, 1, pio0, 0);


const int PWM_PIN = 7;
const int RPM = 250;
#define FCbaud 1000000

unsigned long previousMillis = 0;
const long interval = 200;

int newscan = 1;


uint16_t lidardistances[360];
uint16_t lidarangles[360];

int lidarAngle = 0;
int messageAngle = 0;
uint16_t distances[72];
int target = 0;
unsigned char data_buffer[4] = { 0 };
int adjusted = 0;
int distance = 0;
int range = 0;
unsigned char CS;
uint8_t Index;
byte received;


char serial_buffer[15];

XV11Lidar lidar(Serial1, PWM_PIN);
XV11Packet packet;

void setup() {
  lidar.setup(RPM);
  Serial.begin(115200);                             // USB
  Serial2.begin(115200);                            // FC
  memset(distances, UINT16_MAX, sizeof(distances));  // Filling the distances array with UINT16_MAX

}


void loop() {
READLIDAR();
lidar.applyMotorPID();
}

void setup1() {}

void loop1() {
mavlink_send();
serialprintdiag();

}



void serialprintdiag() {
  //serial print will slow down the board, disable if not using.
Serial.print("angle ");
Serial.print(messageAngle);
Serial.print("distance ");
Serial.println((packet.distances[0]));
}


