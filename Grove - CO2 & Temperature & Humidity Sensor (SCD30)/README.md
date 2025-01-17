# Grove - CO2 & Temperature & Humidity Sensor (SCD30) v1.0 and Arduino Nano 33 IoT

## Introduction
This project involves monitoring carbon dioxide (CO₂) levels, temperature, and humidity using the Grove SCD30 sensor connected to an Arduino Nano 33 IoT via I2C communication.

[Sensor datasheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)%20v1.0.pdf)



> **_Quick Run:_** simply connect the sensor to Arduino as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/Images/Actual%20setup.jpg). Connect Arduino via a micro usb to system that runs arduino IDE installed. select the board and port. From manage library in tools menu, install following libraries: "Sensirion_Core.h" & "Wire.h" & ["SensirionI2cScd30.h"](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/arduino-i2c-scd30-master.zip). Deploy the given code [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/main.cpp) and run it to measure CO2 & Temperature & Humidity.


## Components needed
1. Arduino Nano 33 IoT
2. Grove - CO2 & Temperature & Humidity Sensor (SCD30)
3. Jumper wires

## Steps to setup

### Connect the Grove - Sensor (SCD30) to the MCU (Arduino Nano 33 IoT) as follows:
1. GND (Black) → GND (Arduino)
2. VCC (Red) → 5V (Arduino)
3. SDA (Gray) → A4 (Arduino)
4. SCL (Yeloow) → A5 (Arduino)

### Prepare Arduino Nano 33 IoT
1. Press and hold the button on the Arduino Nano 33 IoT and connect it to a workstation that has Arduino IDE installed.
2. From Tools menu, select *board* and *port*
3. Install following libraries: "Wire.h" & "SensirionI2cScd30.h" and add library by uploading [zip file of SensirionI2cScd30.h]()


### Code:
Save the script on the Arduino Nano 33 IoT. Use the following C++ script to read data from the probesensor: [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/main.cpp)



[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/Images/Actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/diagram.png)

