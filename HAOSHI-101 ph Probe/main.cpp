#include <Wire.h>
#include <Adafruit_ADS1X15.h>

// Create an ADS1115 object
Adafruit_ADS1115 ads;

// Setting the gain for the ADS1115 ADC (Analog-to-Digital Converter).
// The gain determines the input voltage range the ADC can measure and the resolution of each bit.
// Each gain option corresponds to a specific voltage range and resolution:
//  - GAIN_TWOTHIRDS = ±6.144V (1 bit = 0.1875mV, suitable for signals up to 6.144V)
//  - GAIN_ONE        = ±4.096V (1 bit = 0.125mV, suitable for signals up to 4.096V)
//  - GAIN_TWO        = ±2.048V
//  - GAIN_FOUR       = ±1.024V
//  - GAIN_EIGHT      = ±0.512V
//  - GAIN_SIXTEEN    = ±0.256V
// 
// Choose a gain value based on the expected voltage range of your input signal:
// For example, a pH sensor typically outputs a voltage in the range of 0-5V.
// In this case, GAIN_TWOTHIRDS (±6.144V) is appropriate as it covers the 0-5V range.
// If the input range is smaller, you can select a higher gain to increase the resolution.

adsGain_t gain = GAIN_TWOTHIRDS;

void setup() {
  // The setup function runs once when the Arduino starts or resets.
  // This is where you initialize the serial communication, the ADS1115, and any other required settings.
  Serial.begin(115200);
  // Start the serial communication at a baud rate of 115200.
  // This allows the Arduino to send data to your computer for debugging or displaying information.
  while (!Serial) { delay(10); } // Wait for Serial to become active on some boards
  // Wait for the Serial connection to become active on boards like the Arduino Leonardo or Micro.
  // Other boards may not require this, but it ensures the serial monitor is ready before proceeding.

  // Initialize ADS1115
  if (!ads.begin()) {
     // Check if the ADS1115 is connected and functioning properly.
    // The ads.begin() method initializes communication with the ADS1115 chip.
    Serial.println("Failed to find ADS1115 chip");
    // If the ADS1115 is not found, print an error message to the serial monitor.
    while (1);
    // Halt the program if the ADS1115 initialization fails, preventing further errors.
  }
  ads.setGain(gain);
  // Set the gain configuration for the ADS1115 ADC.
  // The gain determines the voltage range the ADC can measure. 
  // (In this case, it uses the `gain` variable defined earlier in the program.)

  Serial.println("ADS1115 pH reading example");
  // Print a startup message to indicate that the program is running.

  Serial.println("Make sure pH probe is connected to A0 of ADS1115 and properly powered.");
  // Provide a helpful reminder to ensure the pH probe is connected correctly for accurate readings.
}

void loop() {
  // This function runs repeatedly in the Arduino environment.
  // It handles reading the ADC, calculating the pH, and printing the results.

  // Read ADC value from channel A1
  int16_t adc1 = ads.readADC_SingleEnded(1);
  // Read the raw 16-bit ADC value from channel A1 of the ADS1115.

  Serial.print("ADCvalue:");
  Serial.println(adc1);
  // Print the raw ADC value to the serial monitor for debugging or observation.

  float voltage = ads1115_to_voltage(adc1, gain);
  // Convert the raw ADC value to voltage based on the selected gain setting.

  Serial.print("voltage:");
  Serial.println(voltage);
  // Print the calculated voltage to the serial monitor.

  // Set voltage of measured solution with pH 6.8 as 1.54V (example value for calibration).
  float neutralVoltage = 1.5;

  // Set voltage of measured solution with pH 4 as 2.05V (example value for calibration).
  float acidVoltage = 2.05;

  // Calculate the slope for the pH scale based on calibration voltages.
  // The slope defines how much the pH changes for a given change in voltage.
  float slope = (6.8 - 4.0) / ((neutralVoltage - 1.5) / 3.0 - (acidVoltage - 1.5) / 3.0);

  Serial.print("Slope:");
  Serial.println(slope);
  // Print the calculated slope to the serial monitor.

  float intercept = 6.8 - slope * (neutralVoltage - 1.5) / 3.0;
  // Calculate the intercept for the linear equation to determine pH values.
  // This ensures the calibration point for pH 6.8 matches the specified neutral voltage.

  Serial.print("Intercept:");
  Serial.println(intercept);
  // Print the calculated intercept to the serial monitor.

  float phValue = slope * (voltage - 1.5) / 3.0 + intercept;
  // Use the slope and intercept to calculate the pH value for the measured voltage.

  Serial.print("phValue:");
  Serial.println(phValue);
  // Print the calculated pH value to the serial monitor.

  // Delay for a while before the next reading (50 seconds in this case).
  delay(50000);
}


// Function to convert raw ADC reading to voltage, based on the configured gain.
float ads1115_to_voltage(int16_t adcValue, adsGain_t gain) {
  float fsRange; // Full-scale range in volts based on gain
  float lsb;     // Least Significant Bit weight

  switch (gain) {
    case GAIN_TWOTHIRDS: fsRange = 6.144; break;
    case GAIN_ONE:        fsRange = 4.096; break;
    case GAIN_TWO:        fsRange = 2.048; break;
    case GAIN_FOUR:       fsRange = 1.024; break;
    case GAIN_EIGHT:      fsRange = 0.512; break;
    case GAIN_SIXTEEN:    fsRange = 0.256; break;
    default:              fsRange = 6.144; break; // Default to the largest range
  }

  // The ADS1115 is a 16-bit ADC, but it's signed. The positive range for the configured gain
  // runs from 0 to +32767 and negative from -32768 to 0 if used in differential mode.
  // For single-ended readings, you only get 0 to +32767 as a positive range.
  lsb = fsRange / 32767.0;
  
  return adcValue * lsb; 
}
