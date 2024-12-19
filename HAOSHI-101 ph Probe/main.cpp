#include <Wire.h>
#include <Adafruit_ADS1X15.h>

// Create an ADS1115 object
Adafruit_ADS1115 ads;

// ADS1115 gain setting
// Gain controls the ADC range:
//  GAIN_TWOTHIRDS = ±6.144V  (1 bit = 0.1875mV)
//  GAIN_ONE        = ±4.096V  (1 bit = 0.125mV)
//  GAIN_TWO        = ±2.048V
//  GAIN_FOUR       = ±1.024V
//  GAIN_EIGHT      = ±0.512V
//  GAIN_SIXTEEN    = ±0.256V
// Choose according to your expected input range. For a pH sensor typically 0-5V, use GAIN_TWOTHIRDS.
adsGain_t gain = GAIN_TWOTHIRDS;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Wait for Serial to become active on some boards

  // Initialize ADS1115
  if (!ads.begin()) {
    Serial.println("Failed to find ADS1115 chip");
    while (1);
  }
  ads.setGain(gain);

  Serial.println("ADS1115 pH reading example");
  Serial.println("Make sure pH probe is connected to A0 of ADS1115 and properly powered.");
}

void loop() {
  // Read ADC value from channel A1
  int16_t adc1 = ads.readADC_SingleEnded(1);
  Serial.print("ADCvalue:");
  Serial.println(adc1);
  float voltage = ads1115_to_voltage(adc1, gain);
  Serial.print("voltage:");
  Serial.println(voltage);
  //set voltage of measured soloution ph 6.8 as 1.54 and ads signal=8061
  float neutralVoltage = 1.5;


  //set voltage of measured soloution ph 4 as 2.05 and ads signal=10920
  float acidVoltage = 2.05;

  float slope = (6.8 - 4.0) / ((neutralVoltage - 1.5) / 3.0 - (acidVoltage - 1.5) / 3.0);
  Serial.print("");
  Serial.println(slope);
  float intercept = 6.8 - slope * (neutralVoltage - 1.5) / 3.0;
  Serial.print("Intercept:");
  Serial.println(intercept);

  float phValue = slope * (voltage - 1.5) / 3.0 + intercept;
  Serial.print("phValue:");
  Serial.println(phValue);
  /*// Depending on the gain setting, calculate the voltage
  float voltage = ads1115_to_voltage(adc1, gain);

  // Convert voltage to pH using calibration parameters
  float pH = calibrationSlope * voltage + calibrationOffset;

  Serial.print("Raw ADC: ");
  Serial.print(adc1);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 4);
  Serial.print(" V  pH: ");
  Serial.println(pH, 2);
*/
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
