
# DFROBOT - Factory Calibrated Electrochemical CO Sensor (0-1000 ppm, I2C & UART)

## Introduction
This project focuses on monitoring carbon monoxide (CO) levels using the DFRobot Gravity Gas Sensor with an Arduino Nano 33 IoT. The sensor communicates via I2C and supports both passive and initiative data acquisition modes, allowing real-time gas concentration and temperature readings.This project focuses on monitoring carbon monoxide (CO) levels using the DFRobot Gravity Gas Sensor with an Arduino Nano 33 IoT. The sensor communicates via I2C and supports both passive and initiative data acquisition modes, allowing real-time gas concentration and temperature readings.
[Sensor datasheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/CO%2C%20O2%2C%20NH3%2C%20H2S%2C%20NO2%2C%20HCL%2C%20H2%2C%20PH3%2C%20SO2%2C%20O3%2C%20CL2%2C%20HF%20Gas%20Sensor%20Wiki%20-%20DFRobot.pdf)



> **_Quick Run:_** simply connect the sensor to Arduino as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/Images/Actual%20Setup.jpeg). Connect Arduino via a micro usb to system that runs arduino IDE installed. select the board and port. From manage library in tools menu, install following library by importing zip file  ["DFRobot_MultiGasSensor.h"](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/DFRobot_MultiGasSensor-main.zip). Deploy the given code [cpp code (Passive)](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/main_Passive.cpp) for Passive mode or [cpp code (Initiative)](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/main_Initiative.cpp) for Initiative mode; and run it to measure carbon monoxide (CO).


## Components needed
1. Arduino Nano 33 IoT
2. Factory Calibrated Electrochemical CO Sensor (0-1000 ppm, I2C & UART)
3. Jumper wires

## Steps to setup

### Connect the Grove - Sensor (SCD30) to the MCU (Arduino Nano 33 IoT) as follows:
1. GND (Black) → GND (Arduino)
2. VCC (Red) → 5V (Arduino)
3. SDA (Green) → A4 (Arduino)
4. SCL (Blue) → A5 (Arduino)

### Prepare Arduino Nano 33 IoT
1. Press and hold the button on the Arduino Nano 33 IoT and connect it to a workstation that has Arduino IDE installed.
2. From Tools menu, select *board* and *port*
3. Install following libraries: "DFRobot_MultiGasSensor.h" by uploading [zip file of "DFRobot_MultiGasSensor.h"](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/DFRobot_MultiGasSensor-main.zip)


### Code:
Write or paste [cpp code (Passive)](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/main_Passive.cpp) for Passive mode or [cpp code (Initiative)](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/main_Initiative.cpp) for Initiative mode, into the Arduino IDE’s coding space. First, verify the code by clicking the Check Mark button below the toolbar menu. Then, upload it to the Arduino by clicking the Right Arrow button. The script will be transferred to the Arduino Nano and will run whenever the Arduino is connected to a power source. The output will be displayed in the Serial Output window. You can open the serial output by selecting Serial Monitor from the Tools menu.

> **_Important:_** The DFRobot Gravity Gas Sensor offers two operational modes: Initiative (Active Upload) Mode and Passivity (Passive Response) Mode.
1.  Initiative Mode: In this mode, the sensor automatically sends data every second without any prompt from the controller. This continuous data stream allows for real-time monitoring without additional commands.
2.  Passivity Mode: Here, the sensor waits for a request from the controller before sending data. The controller must send a specific command to retrieve the current gas concentration and other parameters.

```ruby
gas.changeAcquireMode(gas.INITIATIVE); // Sets the sensor to Initiative Mode
// or
gas.changeAcquireMode(gas.PASSIVITY);  // Sets the sensor to Passivity Mode
```

[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/Images/Actual%20Setup.jpe)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/Factory%20Calibrated%20Electrochemical%20CO%20Sensor/Images/Diagram.png)

