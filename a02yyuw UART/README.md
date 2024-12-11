# Distance Measurement with a02yyuw waterproof UART ultrasonic and arduino nano 33 IOT

## Introduction
This project involves measuring distance using a02yyuw waterproof UART ultrasonic sensor connected to an arduino nano 33 IOT.

##Componnent needed
1. Arduino nano 33 IOT
2. a02yyuw waterproof UART ultrasoni sensor
3. Jumper wires

## Steps to setup

### Connect the sensor (a02yyuw) to the MCU (arduino nano 33 IOT) as follows:
1. VCC (a02yyuw) → 3.3V (arduino)
2. TX (a02yyuw) → PB22 (arduino)
3. GND (a02yyuw) → GND (arduino)
4. RX (a02yyuw) → PB23 (arduino)

### Prepare arduino nano 33 IOT
1. Press and hold the button on arduino nano 33 IOT and connect it to a workstation that hasr arduino IDE installed.
2. From tools menu, select *board* and *port*

### Code:
Save the script on the arduino nano 33 IOT. Use the following C++ script to read data from the sensor: [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/a02yyuw%20UART/measurment.cpp)



[Actual setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/a02yyuw%20UART/Images/connection.jpeg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Images/diagram.png)
