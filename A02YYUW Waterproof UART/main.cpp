// Declare an array named 'data' with 4 elements, all initialized to 0
// This array will store the bytes received from the distance sensor
unsigned char data[4] = {};

// Declare a floating-point variable to store the measured distance
float distance;

void setup() {
  // Initialize serial communication at 57600 baud rate
  // This is used to send messages to the Serial Monitor on your computer
  Serial.begin(57600);   // For output to the serial monitor
  
  // Initialize Serial1 communication at 9600 baud rate
  // Serial1 is used to communicate with the distance sensor
  Serial1.begin(9600);   // For communication with the serial device
}

void loop() {
  // Check if there is any data available to read from Serial1 (the distance sensor)
  if (Serial1.available()) {
    // Read one byte from Serial1 and check if it is 0xFF
    // 0xFF is used here as a start byte to indicate the beginning of a data frame
    if (Serial1.read() == 0xFF) {
      // If the start byte is detected, store it in data[0]
      data[0] = 0xFF;
      
      // Wait until at least 3 more bytes are available to read
      // These bytes contain the distance measurement and checksum
      while (Serial1.available() < 3);
      
      // Read the next three bytes and store them in the data array
      data[1] = Serial1.read(); // High byte of distance
      data[2] = Serial1.read(); // Low byte of distance
      data[3] = Serial1.read(); // Checksum byte

      // Calculate the checksum by adding the first three bytes and masking with 0x00FF
      // The checksum helps verify that the data received is correct
      int sum = (data[0] + data[1] + data[2]) & 0x00FF;
      
      // Compare the calculated checksum with the received checksum (data[3])
      if (sum == data[3]) {
        // If the checksum is correct, calculate the distance
        // (data[1] << 8) shifts the high byte to its proper position
        // Adding data[2] combines both bytes to form the full distance value
        distance = (data[1] << 8) + data[2];
        
        // Check if the distance is greater than 30 (to filter out very close objects)
        if (distance > 30) {
          // If the distance is valid, print it to the Serial Monitor
          // The distance is divided by 10 to convert it to centimeters
          Serial.print("distance=");
          Serial.print(distance / 10);
          Serial.println("cm");
        } else {
          // If the distance is too close, print a warning message
          Serial.println("Below the lower limit");
        }
      } else {
        // If the checksum does not match, print an error message
        // This indicates that the data received may be corrupted
        Serial.println("ERROR");
      }
    }
  }
  
  // Optional: Add a small delay to make the output more readable
  // delay(100); // Delay in milliseconds (e.g., 100 ms)
}
