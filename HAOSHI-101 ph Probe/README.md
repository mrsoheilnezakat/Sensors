# PH meter with Haoshi-101 probe and DFRobot ph metere v2.0 and arduino nano 33 IOT

## Introduction
This project involves metering ph (by measuring voltage using ADC) using Haoshi-101 probe and DFRobot ph metere v2.0 connected to an arduino nano 33 IOT.
A pH probe measures how acidic or basic a liquid is by checking the voltage created between its special tip and the liquid. Here’s what happens step-by-step:

1. Inside the pH probe, there’s a special glass sensor with a known solution inside. When you dip the probe into a liquid, a tiny electric voltage (signal) is created due to the difference in acidity between the known solution inside the probe and the unknown liquid outside.
2. Before using the probe to measure an unknown liquid, we need to “teach” the pH meter what certain voltages mean. We do this by dipping the probe into liquids with known ph values. For example, we might use a pH 4 solution and a pH 7 solution. The meter sees these two points and records the voltages it measures at each pH.
3. By knowing the voltages at ph 4 and ph 5, the meter can draw a straight line between these two points. This line is called a regression line. Now, for any given voltage, the meter can guess the pH by seeing where the voltage fits on the line between pH 4 and pH 7.
4. Once calibrated, when you dip the probe into any other liquid, the meter reads the voltage, follows the line you created, and figures out the pH. If the voltage matches linear correlation , the meter can tell you the pH number of the unknown liquid.

[PH probe data sheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/pH%20Electrode%20Instruction%20Manua%E2%80%A6.pdf)

##Componnent needed
1. Arduino nano 33 IOT
2. Haoshi-101 probe
3. DFRobot ph metere v2.0
4. ADS1115 ADC Module 16Bit
5. Jumper wires

## Steps to setup

### Connect the Haoshi-101 probe to the MCU (arduino nano 33 IOT) as follows:
1. BNC cable (probe) → DFRobot ph meter v2.0
2. A (aanalog dataph meter v2.0) → A1 (ADS1115)
3. - (GND ph meter v2.0) → GND (ADS1115)
4. + (power ph meter v2.0) → VDD (ADS1115)
5. GND (ADS1115) → GND (arduino)
6. VDD (ADS1115) → 5V (arduino)
7. SDA (ADS1115) → A4 (arduino)
8. SCL (ADS1115) → A5 (arduino)

### Prepare arduino nano 33 IOT
1. Press and hold the button on arduino nano 33 IOT and connect it to a workstation that hasr arduino IDE installed.
2. From tools menu, select *board* and *port*

### Code:
Save the script on the arduino nano 33 IOT. Use the following C++ script to read data from the probesensor: [cpp code](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/main.cpp)



[Actual setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/HAOSHI-101%20ph%20Probe/images/diagram.png)

