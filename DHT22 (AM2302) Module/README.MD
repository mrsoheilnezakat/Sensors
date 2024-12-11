# Temperature and Humidity Measurement with DHT22 (AM2302) Module and Pico-W 2022

## Introduction
This project involves measuring temperature and humidity using a DHT22 (AM2302) Module sensor connected to a Pico-W 2022.

## Components Needed
1. Pico-W 2022
2. DHT22 (AM2302) Module
3. Jumper Wires

## Steps to setup

### Connect the sensor (DHT22) to the MCU (pico-w) as follows:
1. VCC (DHT22) → 3.3V (Pico W)
2. Data (DHT22) → GPIO22 (Pico W)
3. GND (DHT22) → GND (Pico W)
**Optional**: Add a 10 kΩ pull-up resistor between the Data line and VCC.

### Code:
Use the following MicroPython code to read data from the sensor: [micro python script](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/main.py)

## Steps to Follow
Set Up the Hardware:
Connect the DHT22 sensor to the Pico W according to the wiring diagram.

Actual setup

Diagram

Install MicroPython on Pico W and Set Up the Script:
Flash the Pico W by holding the button on the Pico and connect it to an RPi or workstation running Thonny. A storage device should be available on your device.
Copy the downloaded MicroPython firmware into the storage, and the device will automatically restart. (Always download from the Raspberry Pi website, ensuring it’s the latest version and specifically for your microcontroller.)
Select the device in Thonny.
Configure the interpreter from the Run menu, and select MicroPython.
Install the DHT library from Manage packages in the Tools menu.
Save the script on the Pico W as main.py (so that it runs on Pico startup).

