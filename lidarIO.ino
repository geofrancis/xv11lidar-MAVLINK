
void READLIDAR() {
  lidar.applyMotorPID();
  lidarAngle = packet.angle_quad;
  messageAngle = map(lidarAngle, 0, 89, 0, 72);
  bool got_packet;
  got_packet = lidar.processAvailable(&packet);  
  if (got_packet)
  {
    distances[messageAngle] = (packet.distances[0] / 10);    
}


}
