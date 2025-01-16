// Include the Wire library for I2C communication
#include <Wire.h>

// Include the library specific to the Sensirion SCD30 sensor
#include "SensirionI2cScd30.h"

// Create an object named 'scd30' from the SensirionI2cScd30 class
// This object will be used to interact with the SCD30 sensor
SensirionI2cScd30 scd30;

// Define the I2C address for the SCD30 sensor
// I2C devices have unique addresses; the default for SCD30 is 0x61
#define SCD30_I2C_ADDRESS 0x61

// The setup function runs once when the Arduino starts
void setup() {
  // Start serial communication at a baud rate of 115200 bits per second
  // This allows the Arduino to send messages to your computer for debugging
  Serial.begin(115200);
  
  // Wait until the serial port is connected
  // This is useful if you're using a USB connection to the computer
  while (!Serial) {
    ; // Do nothing and keep waiting
  }

  // Initialize I2C communication
  // I2C is a protocol that allows multiple devices to communicate using two wires (SDA and SCL)
  Wire.begin();

  // Initialize the SCD30 sensor with the I2C communication and its address
  // This sets up the sensor so we can start using it
  scd30.begin(Wire, SCD30_I2C_ADDRESS);

  // Start the sensor's periodic measurement mode
  // The parameter 1013 represents the ambient pressure in mBar (standard atmospheric pressure)
  // This helps the sensor to calibrate its readings based on current pressure
  if (scd30.startPeriodicMeasurement(1013) != NO_ERROR) {
    // If starting the measurement fails, print an error message
    Serial.println("Failed to start periodic measurement!");
    // Enter an infinite loop to stop the program
    while (1);
  }

  // If everything is successful, print a confirmation message
  Serial.println("SCD30 Sensor Initialized and Measurement Started Successfully!");
}

// The loop function runs repeatedly after setup() finishes
void loop() {
  // Declare variables to store sensor data
  uint16_t dataReadyFlag; // Flag to check if new data is ready
  float co2 = 0.0;        // Variable to store CO2 concentration in ppm
  float temperature = 0.0; // Variable to store temperature in °C
  float humidity = 0.0;    // Variable to store humidity in %RH

  // Check if new data is available from the sensor
  // getDataReady sets dataReadyFlag to 1 if data is ready, otherwise 0
  if (scd30.getDataReady(dataReadyFlag) == NO_ERROR) {
    // If dataReadyFlag is true (1), new data is available
    if (dataReadyFlag) {
      // Read the measurement data from the sensor
      // This fills the co2, temperature, and humidity variables with new values
      if (scd30.readMeasurementData(co2, temperature, humidity) == NO_ERROR) {
        // If reading data is successful, print the values to the Serial Monitor

        // Print CO2 concentration
        Serial.print("CO2: ");
        Serial.print(co2);
        Serial.println(" ppm"); // ppm stands for parts per million

        // Print Temperature
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C"); // Degrees Celsius

        // Print Humidity
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %RH"); // Relative Humidity

        // Print a separator line for readability
        Serial.println("---------------------------");
      } else {
        // If reading measurement data fails, print an error message
        Serial.println("Failed to read measurement data!");
      }
    }
  } else {
    // If getting the data ready flag fails, print an error message
    Serial.println("Failed to get data ready flag!");
  }

  // Optional: Wait for 1 second before the next loop
  // This prevents the Serial Monitor from being flooded with messages too quickly
  delay(1000); // Delay in milliseconds (1000 ms = 1 second)
}
