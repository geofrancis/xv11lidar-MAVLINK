void READLIDAR() {
  bool got_packet;
  got_packet = lidar.processAvailable(&packet);
  if (got_packet) {
    lidarAngle = packet.angle_quad;
    for (int i = 0; i < 3; i++) {
      int trueangle = (lidarAngle * 4) + i;
      lidardistances[trueangle] = packet.distances[i];
      messageAngle = map(trueangle, 0, 359, 0, 72);
      distances[messageAngle] = lidardistances[trueangle];
    }
    if (packet.angle_quad = 89) {
      newscan = 1;
      p.neoPixelFill(255, 0, 0, true);
    }
  }
}
