# Temperature and Humidity Measurement with DHT22 (AM2302) Module and Raspberry Pi Pico W

## Introduction
This project involves measuring temperature and humidity using a DHT22 (AM2302) module sensor connected to a Raspberry Pi Pico W.

[Sensor datasheet](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Digital%2Bhumidity%2Band%2Btemperature%2Bsensor%2BAM2302.pdf)

> **_Quick Run:_** simply connect the sensor to Pi Pico W as shown in [Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Images/actual%20setup.jpg). Connect Pi Pico w via a micro usb to system that runs Thonny IDE installed while holding the button on Pi Pico W. The Pi Pico W get flashed and a directory will be shown to you. So now you have to paste the [micropython firmware](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/RPI_PICO_W-20241025-v1.24.0.uf2) into the directory. The Pi Pico W get restarted, select the port in Thonny IDE and from the Tools menu, Manage Packages install DHT library. Deploy the given code [micro python script](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/main.py) and run it to measure Temperature & Humidity.

## Components Needed
1. Pico-W 2022
2. DHT22 (AM2302) module
3. Jumper wires

## Steps to setup

### Connect the sensor (DHT22) to the MCU (Pico W) as follows:
1. VCC (DHT22) → 3.3V (Pico W)
2. Data (DHT22) → GPIO22 (Pico W)
3. GND (DHT22) → GND (Pico W)
**Optional**: Add a 10 kΩ pull-up resistor between the Data line and VCC.

### Prepare Pico-w 2022
1. Press and hold the button on the Pico W and connect it to a Raspberry Pi or workstation running Thonny. A storage device should become available on your device.
2. Copy the downloaded MicroPython [firmware](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/RPI_PICO_W-20241025-v1.24.0.uf2) into the storage, and the device will automatically restart.
3. Select the device in Thonny.
4. Configure the interpreter from the Run menu, and select MicroPython.
5. Install the DHT library from the Tools menu, Manage Packages.

### Code:
Write or paste [micro python script](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/main.py) into Thonny’s coding space, then click Save. When you do this, a window will open asking where to save your file. You can either save it locally on “This computer” and later move the code to the Raspberry Pi Pico W via Thonny’s Files section, or save it directly to your Pico if it is connected. Once you run the code, the output will appear in Thonny’s Shell window.





[Actual Setup](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Images/actual%20setup.jpg)

[Diagram](https://github.com/mrsoheilnezakat/Sensors/blob/main_branch/DHT22%20(AM2302)%20Module/Images/diagram.png)
