# Distance Measurement with A02YYUW Waterproof UART Ultrasonic and Arduino Nano 33 IoT

## Introduction
This project involves measuring distance using an A02YYUW Waterproof UART Ultrasonic Sensor connected to an Arduino Nano 33 IoT.

## Components Needed
1. Arduino Nano 33 IoT
2. A02YYUW Waterproof UART Ultrasonic Sensor
3. Jumper wires

## Steps to Set Up

### Connect the A02YYUW sensor to the MCU (Arduino Nano 33 IoT) as follows:
1. VCC (a02yyuw) → 3.3V (arduino)
2. TX (a02yyuw) → PB22 (arduino)
3. GND (a02yyuw) → GND (arduino)
4. RX (a02yyuw) → PB23 (arduino)

### Prepare Arduino Nano 33 IoT
1. Press and hold the button on the Arduino Nano 33 IoT and connect it to a workstation that has the Arduino IDE installed.
2. From Tools menu, select *board* and *port*

### Code:
Use the following C++ code to read data from the sensor: [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/a02yyuw%20UART/measurment.cpp)



[Actual set up](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/a02yyuw%20UART/Images/connection.jpeg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Images/diagram.png)
