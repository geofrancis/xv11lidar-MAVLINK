xv11lidar-MAVLINK 

#Adapter to convert a XV11 Lidar to Mavlink compatible with ardupilot.
#Its running on a STM32f4 blackpill but could be ported to esp32.
#requires https://github.com/br3ttb/Arduino-PID-Library

Flight controller RX pin connects to A2,

Lidar motor driver /transistor to B1

Lidar TX pin connects to A10

The Lidar board takes 3.3v or 5v depeding on the version so check first, I fried my first one.

on the flight controller:

set SERIALx_BAUD = 1500

Set SERIALx_PROTOCOL = 2

Set PRX1_TYPE = 2 for MAVLINK

Set PRX1_ORIENT =1 or it will be upside down.

https://youtu.be/SjgFwN74lNY

https://www.youtube.com/watch?v=aAFY8p1glmM


https://wiki.recessim.com/w/index.php?title=Xiaomi_Roborock_LIDAR


http://roboticsweekends.blogspot.com/2018/05/xv-11-sensor-hacking-info-none-this-is.html
<img width="640" alt="1280px-Pinout" src="https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/6802f6b8-282d-441b-8cfe-17312df8e5ca">
![515e9b0b5543d457c73260b0f479616fda892dd2](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/d950ff4e-e0f4-4bde-94fc-9804446b995f)

![2957934fb204f9bf70072a7a1e38acacebfa534f](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/8ada8f21-1385-4306-b6bb-5f9f68f1df73)
