# Distance Measurement with A02YYUW Waterproof UART Ultrasonic and Arduino Nano 33 IoT

## Introduction
This project involves measuring distance using an A02YYUW Waterproof UART Ultrasonic Sensor connected to an Arduino Nano 33 IoT.

[Sensor datasheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/A02YYUW%20Waterproof%20Ultrasonic%20Sensor.pdf)


> **_Quick Run:_** simply connect the sensor to Arduino as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/Images/connection.jpeg). Connect Arduino via a micro usb to system that runs arduino IDE installed. select the board and port. Deploy the given code [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/main.cpp) and run it to measure Distance.

## Components Needed
1. Arduino Nano 33 IoT
2. A02YYUW Waterproof UART Ultrasonic Sensor
3. Jumper wires

## Steps to Set Up

### Connect the A02YYUW sensor to the MCU (Arduino Nano 33 IoT) as follows:
1. VCC (a02yyuw) → 3.3V (Arduino)
2. TX (a02yyuw) → PB22 (Arduino)
3. GND (a02yyuw) → GND (Arduino)
4. RX (a02yyuw) → PB23 (Arduino)

### Prepare Arduino Nano 33 IoT
1. Press and hold the button on the Arduino Nano 33 IoT and connect it to a workstation that has the Arduino IDE installed.
2. From Tools menu, select *board* and *port*

### Code:
Write or paste [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/main.cpp) into the Arduino IDE’s coding space. First, verify the code by clicking the Check Mark button below the toolbar menu. Then, upload it to the Arduino by clicking the Right Arrow button. The script will be transferred to the Arduino Nano and will run whenever the Arduino is connected to a power source. The output will be displayed in the Serial Output window. You can open the serial output by selecting Serial Monitor from the Tools menu.

[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/Images/connection.jpeg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/A02YYUW%20Waterproof%20UART/Images/Diagram.png)
