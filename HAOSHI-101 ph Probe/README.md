# pH meter with Haoshi-101 probe and DFRobot pH Meter v2.0 and Arduino Nano 33 IoT

## Introduction
This project involves measuring pH (by measuring voltage using ADC) using Haoshi-101 probe and DFRobot pH Meter v2.0 connected to an Arduino Nano 33 IoT.
A pH probe measures how acidic or basic a liquid is by measuring the voltage generated. between its special tip and the liquid. Here’s what happens step-by-step:

1. Inside the pH probe, there’s a special glass sensor with a known solution inside. When you dip the probe into a liquid, a tiny electric voltage (signal) is created due to the difference in acidity between the known solution inside the probe and the unknown liquid outside.
2. Before using the probe to measure an unknown liquid, we need to “teach” the pH meter what certain voltages mean. We do this by dipping the probe into liquids with known pH values. For example, we might use a pH 4 solution and a pH 7 solution. The meter sees these two points and records the voltages it measures at each pH.
3. By knowing the voltages at pH 4 and pH 7, the meter can draw a straight line between these two points. This line is called a regression line. Now, for any given voltage, the meter can guess the pH by seeing where the voltage fits on the line between pH 4 and pH 7.
4. Once calibrated, when you dip the probe into any other liquid, the meter reads the voltage, follows the line you created, and figures out the pH. If the voltage matches the linear correlation, the meter can tell you the pH number of the unknown liquid.

[pH probe datasheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/pH%20Electrode%20Instruction%20Manua%E2%80%A6.pdf)



> **_Quick Run:_** simply connect pH probe, DFRobot board, ADS115 and Arduino as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/actual%20setup.jpg). Connect Arduino via a micro usb to system that runs arduino IDE installed. select the board and port. From manage library in tools menu, install following libraries: Adafruit_ADS1X15.h & Wire.h. Deploy the given code and run it to measure a solution with pH 4 and then measure a solution with pH 7. Then replace the measured values which are voltage for pH4 and pH7 in the code. From now on, the code will measure any solution or liquid voltage and give you the pH value, by calculating a linear-regression.


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
Write or paste [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/main.cpp) into the Arduino IDE’s coding space. First, verify the code by clicking the Check Mark button below the toolbar menu. Then, upload it to the Arduino by clicking the Right Arrow button. The script will be transferred to the Arduino Nano and will run whenever the Arduino is connected to a power source. The output will be displayed in the Serial Output window. You can open the serial output by selecting Serial Monitor from the Tools menu.

[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/diagram.png)

