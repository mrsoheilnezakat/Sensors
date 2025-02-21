#include "DFRobot_MultiGasSensor.h"

// Define whether to use I2C communication (enabled by default)
#define I2C_COMMUNICATION

#ifdef I2C_COMMUNICATION
  // Define the I2C address for the sensor
  #define I2C_ADDRESS 0x74
  // Create an instance of the gas sensor using I2C communication
  DFRobot_GAS_I2C gas(&Wire, I2C_ADDRESS);
#else
  // If not using I2C, select the correct communication type based on the board
  #if (!defined ARDUINO_ESP32_DEV) && (!defined __SAMD21G18A__)
    // For Arduino UNO, use SoftwareSerial to communicate with the sensor
    SoftwareSerial mySerial(2,3);  // RX on pin 2, TX on pin 3
    DFRobot_GAS_SoftWareUart gas(&mySerial);
  #else
    // For ESP32, use hardware serial (Serial2) for communication
    DFRobot_GAS_HardWareUart gas(&Serial2);
  #endif
#endif

void setup() {
  // Start serial communication to display data in the Serial Monitor
  Serial.begin(115200);

  // Try to initialize the gas sensor. If it fails, print an error message
  while(!gas.begin()) {
    Serial.println("NO Devices!" );  // Sensor not detected, retrying...
    delay(1000);  // Wait for 1 second before retrying
  }
  Serial.println("The device is connected successfully!");

  // Set the gas sensor to passive mode (it waits for commands to take readings)
  gas.changeAcquireMode(gas.PASSIVITY);
  delay(1000);  // Wait for settings to take effect

  // Disable temperature compensation (optional, depends on use case)
  gas.setTempCompensation(gas.OFF);
}

void loop() {
  // Print the type of detected gas
  Serial.print("Ambient ");
  Serial.print(gas.queryGasType());  // Query the sensor for the gas type
  Serial.print(" concentration is: ");
  
  // Print the gas concentration in %vol or PPM depending on the sensor type
  Serial.print(gas.readGasConcentrationPPM());
  Serial.println(" %vol");  // This unit is %vol for SEN0465, otherwise PPM

  // Print the temperature of the gas sensor's environment
  Serial.print("The board temperature is: ");
  Serial.print(gas.readTempC());  // Read the temperature in Celsius
  Serial.println(" ℃");
  Serial.println();  // Print a blank line for readability

  delay(1000);  // Wait for 1 second before taking the next reading
}
