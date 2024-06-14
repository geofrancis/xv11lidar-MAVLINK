
void READLIDAR() {
  if (packet.angle_quad != lidarAngle) {
    lidarAngle = packet.angle_quad;
    messageAngle = map(lidarAngle, 0, 89, 0, 72);
    bool got_packet;
    got_packet = lidar.processAvailable(&packet);
    lidar.applyMotorPID();
    if (got_packet) {
      distances[messageAngle] = (packet.distances[0] / 10);
    }
  }
}
