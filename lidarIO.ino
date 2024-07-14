
void READLIDAR() {
  
  lidarAngle = packet.angle_quad;
  messageAngle = map(lidarAngle, 0, 89, 0, 72);
  bool got_packet;
  got_packet = lidar.processAvailable(&packet);  
  if (got_packet)
  {
    distances[messageAngle] = (packet.distances[0] / 10);    
}
    if (packet.angle_quad = 89) {
      newscan = 1;
      serialprintdiag();
      p.neoPixelFill(255, 0, 0, true);
    }
}
