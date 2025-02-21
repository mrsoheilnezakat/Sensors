#include "DFRobot_MultiGasSensor.h"

// Define whether to use I2C communication (enabled by default)
#define I2C_COMMUNICATION

#ifdef I2C_COMMUNICATION
  // Define the default I2C address for the gas sensor
  #define I2C_ADDRESS 0x74
  // Create an instance of the gas sensor using I2C communication
  DFRobot_GAS_I2C gas(&Wire, I2C_ADDRESS);
#else
  // If not using I2C, select the correct communication type based on the board
  #if (!defined ARDUINO_ESP32_DEV) && (!defined __SAMD21G18A__)
    // For Arduino UNO, use SoftwareSerial for sensor communication
    SoftwareSerial mySerial(2, 3);  // RX on pin 2, TX on pin 3
    DFRobot_GAS_SoftWareUart gas(&mySerial);
  #else
    // For ESP32, use hardware serial (Serial2) for communication
    DFRobot_GAS_HardWareUart gas(&Serial2);
  #endif
#endif

void setup() {
  // Start serial communication for debugging output
  Serial.begin(115200);

  // Try to initialize the gas sensor, retry if not detected
  while (!gas.begin()) {
    Serial.println("NO Devices!");  // Error message if no sensor detected
    delay(1000);  // Wait 1 second before retrying
  }

  // Disable temperature compensation (optional based on application needs)
  gas.setTempCompensation(gas.OFF);

  // Set the gas sensor to active mode (automatically sends data when available)
  gas.changeAcquireMode(gas.INITIATIVE);
  delay(1000);  // Wait for settings to apply
}

void loop() {
  // Check if new gas concentration data is available from the sensor
  if (true == gas.dataIsAvailable()) {
    Serial.println("========================");
    
    // Print detected gas type
    Serial.print("Gas Type: ");
    Serial.println(AllDataAnalysis.gastype);
    Serial.println("------------------------");
    
    // Print gas concentration value
    Serial.print("Gas Concentration: ");
    Serial.print(AllDataAnalysis.gasconcentration);
    
    // Determine if gas concentration should be shown in %VOL or PPM
    if (AllDataAnalysis.gastype.equals("O2"))
      Serial.println(" %VOL");  // Oxygen concentration is measured in %VOL
    else
      Serial.println(" PPM");  // Other gases are measured in PPM
    
    Serial.println("------------------------");
    
    // Print the temperature of the sensor environment
    Serial.print("Temperature: ");
    Serial.print(AllDataAnalysis.temp);
    Serial.println(" ℃");
    
    Serial.println("========================");
  }
  delay(1000);  // Wait 1 second before checking again
}
