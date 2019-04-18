# Gesture-Controlled-Computer-Operation
## This project will contain the following components:
1. Project Documentation
2. Arduino Code
3. Python Code
4. List of Libraries involved

# Introduction to the project:
This project is an amalgamation of Arduino and Python platforms. Arduino is considered as one of the most powerful and compatible electronics prototyping platforms. On the other hand, Python is the most advanced and widely used open source platform for high-end programming. The interaction bridge built between Arduino and Python gives the privilege to understand the distance of the hand from the sensor to reflect the respective operation in the computer.
This project incorporates twelve different operations in the computer on different applications which are pre-installed. To perform these operations, we require 2 Ultrasonic sensors, each sensor has its own set of distance ranges and operations to perform. The moment any object or hand interferes the waves of the sensor, the Arduino program calculates the distance at which the interference has been encountered and hands over to Python for finding out which operation to perform in the computer based on the value of the distance. 
Out of the twelve operations, seven operations are being performed on the VLC Media Player, 3 operations on the Chrome Web Browser, one operation for recording a live video from the webcam installed in the laptop and finally to shut down the laptop.
