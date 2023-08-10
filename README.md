xv11lidar-MAVLINK 

Adapter to convert a XV11 Lidar to Mavlink compatible with ardupilot. It has been tested on a STM32 blackpill,

ts running on a STM32 blackpill but could be ported to esp32.

Flight controller RX pin connects to A2,

Lidar motor driver /transistor to B1

Lidar Data connects to A10

The Lidar board takes 3.3v or 5v depeding on the version so check first, I killed my first one lol

on the flight controller:

set SERIALx_BAUD = 1500

Set SERIALx_PROTOCOL = 2

Set PRX1_TYPE = 2 for MAVLINK

Set PRX1_ORIENT =1 or it will be upside down.
