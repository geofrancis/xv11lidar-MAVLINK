





# xv11lidar-MAVLINK

Adapter to convert a XV11 Lidar or SDJQR01RR SDJQR02RR SDJQR03RR Xiaomi LIDAR  to Mavlink compatible with ardupilot.    

Install PID, XVLidar,(and RGB if using RP-2040) libraries into your arduino Library, place mavlink folder into the same folder as the ino file.      
**The Lidar board takes 3.3v or 5v depeding on the version so check first**, I fried my first one.    

Most XV lidars are 3.3v only and from all current reports the Xiaomi lidars are all 5v.

https://discuss.ardupilot.org/t/15-360-degree-xv-proximity-lidar/104887


## Hardware 

For STM32f4 blackpill:

A2 to Flight controller RX pin
B1 to Lidar motor driver / transistor   
A10 to Lidar TX pin 

For RP-2040 :

4 to Flight controller RX pin     
7 to Lidar motor driver / transistor   
1 to Lidar TX pin    

with RGB version   
LED should be RED on startup then turn GREEN when data is recevied from the lidar.
       

on the flight controller:

set SERIALx_BAUD         = 1500    
Set SERIALx_PROTOCOL     = 2     
Set PRX1_TYPE            = 2 for MAVLINK            
Set PRX1_ORIENT          = 1 or it will be upside down.

OA_TYPE = 1, this will enabe avoid in auto mode and show objects on the mission planner map       
SRx_ADSB = 5, this is how many objects it will send to the ground station per second, you wont see anything on mission planner if its set to zero. this is set on your telemetry port not the lidar.   

https://youtu.be/SjgFwN74lNY

https://www.youtube.com/watch?v=aAFY8p1glmM


https://wiki.recessim.com/w/index.php?title=Xiaomi_Roborock_LIDAR


http://roboticsweekends.blogspot.com/2018/05/xv-11-sensor-hacking-info-none-this-is.html
<img width="640" alt="1280px-Pinout" src="https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/6802f6b8-282d-441b-8cfe-17312df8e5ca">
![515e9b0b5543d457c73260b0f479616fda892dd2](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/d950ff4e-e0f4-4bde-94fc-9804446b995f)

![2957934fb204f9bf70072a7a1e38acacebfa534f](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/8ada8f21-1385-4306-b6bb-5f9f68f1df73)


![rp-2040](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/a983a05c-c033-47e9-bf40-95a06872bcf1)





![7a87b5a434f85a66fca53b3627ca306bbf0bb7d1](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/6acebec4-f0ae-4b1a-96b7-893702f288e5)

![12f4eae8dd3faafbb94ae3ee7e76aba5812fc239](https://github.com/geofrancis/xv11lidar-MAVLINK/assets/5570278/c621cd6c-f3a8-4c0e-bdbb-5bff881c27f2)
