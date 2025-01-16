###
### The below code is compatible with Pico-W 2022 (MicroPython) ###
###

# Import the machine module to control hardware components like pins and peripherals
import machine

# Import the time module to handle timing functions like delays
import time

# Import the network module to manage network connections (Wi-Fi)
import network

# Import the dht module to interact with DHT temperature and humidity sensors
import dht

# Import the socket module to create and manage network sockets for communication
import socket

# Add your Wi-Fi credentials
name = "****"          # Replace "****" with your Wi-Fi network name (SSID)
password = "****"      # Replace "****" with your Wi-Fi network password

# Initialize the WLAN interface in Station mode (connects to existing Wi-Fi)
wlan = network.WLAN(network.STA_IF)

# Activate the WLAN interface
wlan.active(True)

# Initialize the onboard LED pin as an output
led = machine.Pin('LED', machine.Pin.OUT)

# Scan for available Wi-Fi access points
ap = wlan.scan()

# Iterate through each found access point
for ap in ap:
    # Print details of each access point
    print(ap)

# Set GPIO pin 22 for connecting the DHT sensor
dht_pin = machine.Pin(22)

# Initialize the DHT22 sensor on the specified pin
dht_sensor = dht.DHT22(dht_pin)

# Define the Wi-Fi connection function
def connect():
    # Loop until the Pico-W is connected to Wi-Fi
    while not wlan.isconnected():
        # Print a message indicating an attempt to connect
        print('try to connect... ')
        # Attempt to connect to the specified Wi-Fi network
        wlan.connect(name, password)
        # Wait for 20 seconds before retrying
        time.sleep(20)
    
    # Check if the connection was successful
    if wlan.isconnected() == True:
        # Print confirmation message
        print('wifi is connected')
        # Print network configuration details
        print('Try to ping the device at', wlan.ifconfig())
        # Turn off the onboard LED to indicate successful connection
        led.off()
        # Wait for 2.5 seconds
        time.sleep(2.5)
        # Turn on the onboard LED
        led.on()
        # Wait for another 2.5 seconds
        time.sleep(2.5)
        # Retrieve the device's IP address
        ip = wlan.ifconfig()[0]
        # Print the IP address
        print(f'Connected on {ip}')
    # Return the IP address
    return ip

# Define the measurement function
def measure():
    # Trigger the DHT22 sensor to take a measurement
    dht_sensor.measure()
    # Read temperature and convert to string
    temperature_celsius = str(dht_sensor.temperature())
    # Read humidity and convert to string
    humidity_percent = str(dht_sensor.humidity())
    # Return temperature and humidity
    return temperature_celsius, humidity_percent

# Call the connect function to establish Wi-Fi connection
connect()

# Call the measure function and store temperature and humidity
tem, hum = measure()

# Print the temperature
print(tem)

# Print the humidity
print(hum)

# Get the address information for the server (listen on all interfaces, port 80)
addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]

# Create a new socket object
s = socket.socket()

# Set socket options to allow address reuse
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# Bind the socket to the specified address and port
s.bind(addr)

# Start listening for incoming connections (allow 1 connection at a time)
s.listen(1)

# Print the address and port the server is listening on
print('listening on:', addr)

# Try to handle incoming connections
try:
    # Run indefinitely
    while True:
        # Accept a new client connection
        cl, addr = s.accept()
        # Print the client's address
        print('client connected from:', addr)
        # Receive the client's request (up to 1024 bytes)
        request = cl.recv(1024)
        
        # Take a new measurement of temperature and humidity
        temp, humi = measure()
        
        # Create HTTP response in JSON format with temperature and humidity data
        response = (
            "HTTP/1.1 200 OK\r\n"                # HTTP status line indicating success
            "Content-Type: application/json\r\n\r\n"  # HTTP header specifying JSON content
            f'{{"temp": {temp}, "humi": {humi}}}'     # JSON payload with temperature and humidity
        )
        
        # Send the HTTP response back to the client
        cl.send(response)
        # Wait for 1 second
        time.sleep(1)
        # Close the client connection
        cl.close()
# Catch any exceptions that occur
except Exception as e:
    # Print any errors that occur
    print("Error: ", e)
    # Close the server socket
    s.close
