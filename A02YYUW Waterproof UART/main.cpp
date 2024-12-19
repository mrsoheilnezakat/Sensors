unsigned char data[4]={};
float distance;

void setup() {
  Serial.begin(57600);   // For output to the serial monitor
  Serial1.begin(9600);   // For communication with the serial device
}
void loop() {
  if (Serial1.available()) {
    if (Serial1.read() == 0xFF) {
      data[0] = 0xFF;
      while (Serial1.available() < 3);
      data[1] = Serial1.read();
      data[2] = Serial1.read();
      data[3] = Serial1.read();

      int sum = (data[0] + data[1] + data[2]) & 0x00FF;
      if (sum == data[3]) {
        distance = (data[1] << 8) + data[2];
        if (distance > 30) {
          Serial.print("distance=");
          Serial.print(distance / 10);
          Serial.println("cm");
        } else {
          Serial.println("Below the lower limit");
        }
      } else {
        Serial.println("ERROR");
      }
    }
  }
}
