# Grove - CO2 & Temperature & Humidity Sensor (SCD30) v1.0 and Arduino Nano 33 IoT

## Introduction
This project involves monitoring carbon dioxide (CO₂) levels, temperature, and humidity using the Grove SCD30 sensor connected to an Arduino Nano 33 IoT via I2C communication.

[Sensor datasheet](hhttps://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)%20v1.0.pdf)



> **_Quick Run:_** simply connect the sensor to Arduino as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/actual%20setup.jpg). Connect Arduino via a micro usb to system that runs arduino IDE installed. select the board and port. From manage library in tools menu, install following libraries: "Sensirioncore.h" & "Wire.h" & "SensirionI2cScd30.h". Deploy the given code and run it to measure CO2 & Temperature & Humidity.


## Components needed
1. Arduino Nano 33 IoT
2. Haoshi-101 probe
3. DFRobot pH Meter v2.0
4. ADS1115 ADC Module 16Bit
5. Jumper wires

## Steps to setup

### Connect the Haoshi-101 probe to the MCU (Arduino Nano 33 IoT) as follows:
1. BNC cable (probe) → DFRobot pH Meter v2.0
2. 'A' pin (analog data pH meter v2.0) → A1 (ADS1115)
3. '-' pin (GND pH meter v2.0) → GND (ADS1115)
4. '+' pin (power pH meter v2.0) → VDD (ADS1115)
5. GND (ADS1115) → GND (Arduino)
6. VDD (ADS1115) → 5V (Arduino)
7. SDA (ADS1115) → A4 (Arduino)
8. SCL (ADS1115) → A5 (Arduino)

### Prepare Arduino Nano 33 IoT
1. Press and hold the button on the Arduino Nano 33 IoT and connect it to a workstation that has Arduino IDE installed.
2. From Tools menu, select *board* and *port*
3. Install following libraries: Adafruit_ADS1X15.h & Wire.h

### Code:
Save the script on the Arduino Nano 33 IoT. Use the following C++ script to read data from the probesensor: [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/main.cpp)



[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/diagram.png)

