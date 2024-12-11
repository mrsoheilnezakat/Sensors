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

### Prepare Pico-w 2022
1. Flash the Pico W by holding the button on the Pico-w and connect it to an RPi or workstation running Thonny. A storage device should become available on your device.
2. Copy the downloaded MicroPython [firmware](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/RPI_PICO_W-20241025-v1.24.0.uf2) into the storage, and the device will automatically restarted.
3. Select the device in Thonny.
4. Configure the interpreter from the Run menu, and select MicroPython.
5. Install the DHT library from Manage packages from the Tools menu.
Save the script on the Pico-w as main.py (so that it runs on Pico-w starts up).

### Code:
Use the following MicroPython code to read data from the sensor: [micro python script](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/main.py)

## Steps to Follow
Set Up the Hardware:
Connect the DHT22 sensor to the Pico W according to the wiring diagram.

Actual setup

Diagram

Install MicroPython on Pico W and Set Up the Script:


