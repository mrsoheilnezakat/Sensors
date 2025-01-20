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
3. Install following libraries: "Wire.h" & "SensirionI2cScd30.h" and add library by uploading [zip file of SensirionI2cScd30.h](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/arduino-i2c-scd30-master.zip)


### Code:
Write or paste [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/main.cpp) into the Arduino IDE’s coding space. First, verify the code by clicking the Check Mark button below the toolbar menu. Then, upload it to the Arduino by clicking the Right Arrow button. The script will be transferred to the Arduino Nano and will run whenever the Arduino is connected to a power source. The output will be displayed in the Serial Output window. You can open the serial output by selecting Serial Monitor from the Tools menu.

[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Grove%20-%20CO2%20%26%20Temperature%20%26%20Humidity%20Sensor%20(SCD30)/Images/Actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/diagram.png)

