# Table of contents
  * [Hardware requirements](#hardware-requirements)
  * [Software requirements](#software-requirements)
  * [Circuit diagram](#circuit-diagram)
  * [Set up.](#set-up-steps)
  * [Future releases](#future-releases)
  * [Test](#test)

# Volume control with Arduino
The goal of the project is to be able to control the volumne of your pc using ultrasonic distance sensors and an Arduino controller. The only thing that we would have to do is just approach the hand over one of the sensors and the volume will increase/decrease.

## Hardware requirements
1. Arduino UNO R3 (1)
2. Protoboard (1)
3. Wires (approximately 15)
4. HC-SR04 Ultra Sonic Sensors(2)

## Software requirements
1. Arduino 1.8.10 (https://www.arduino.cc/en/software)
2. Python 3 (https://www.python.org/downloads/)
3. Python libraries: serial, re, ctypes, comtypes, pycaw

## Circuit diagram

![](/ultrasonic_controller/circuit_diagram.png)

## Set up steps.
Due to the middle complexity of the project, I assume that you understand the basics of Python and Arduino, so I will avoid the part of software installation.

1. Follow the circuit diagram to build the circuit.
2. Send the ultrasonic_controller.ino to the Arduino device.
3. Run the serial_read.py script.
4. Now the program is working, if you approach the hand over one of the ultrasonic sensors the main volume of your pc will increase/decrease depending the sensor you approached.

## Future releases

This is a simple version of a more complex project that I am planning. The idea is to control the pc options without the buttons, just using ultrasonic sensors to catch key gestures. In addition, the project needs the Arduino to be connected to the PC, so, it could be more useful if it is wireless. 

1. Implement more options to be changed with gestures.
2. Implement a wireless method which allows the device to work without a direct connection to the PC.


## Test
Windows 10, Python 3.7.4
