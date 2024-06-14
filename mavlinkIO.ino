void mavlink_send() {

  if (newscan = 1) {

  
    int sysid = 1;
    //< The component sending the message.
    int compid = 196;
    uint64_t time_usec = 0; /*< Time since system boot*/
    uint8_t sensor_type = 0;
    uint8_t increment = 5;
    uint16_t min_distance = 10;  /*< Minimum distance the sensor can measure in centimeters*/
    uint16_t max_distance = 650; /*< Maximum distance the sensor can measure in centimeters*/
    float increment_f = 0;
    float angle_offset = -10;
    uint8_t frame = 12;
    uint8_t system_type = MAV_TYPE_GENERIC;
    uint8_t autopilot_type = MAV_AUTOPILOT_INVALID;
    uint8_t system_mode = MAV_MODE_PREFLIGHT;  ///< Booting up
    uint32_t custom_mode = 30;                 ///< Custom mode, can be defined by user/adopter
    uint8_t system_state = MAV_STATE_STANDBY;  ///< System ready for flight

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
      newscan = 0;
      p.neoPixelFill(0, 0, 255, true);
    }
  }
}
