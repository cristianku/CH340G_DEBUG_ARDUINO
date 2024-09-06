#include <SoftwareSerial.h>

SoftwareSerial debugSerial(10, 11); // RX, TX on pins 10 and 11

void setup() {
  Serial.begin(9600);     // Default serial for USB communication
  debugSerial.begin(9600);   // Second serial for CH340G debugging
}

void loop() {

  if (Serial.available()) {
    // Read from USB and send to CH340G
    char data = Serial.read();
    debugSerial.print("debugging to CH340G: ");
    debugSerial.println(data);
  }
}
