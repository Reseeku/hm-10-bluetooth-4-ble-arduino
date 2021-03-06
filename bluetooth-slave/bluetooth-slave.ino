#include <SoftwareSerial.h>

SoftwareSerial bluetooth_serial(10, 11);

void setup() {
  Serial.begin(9600);

  bluetooth_serial.begin(9600);

  bluetooth_serial.print("AT+NAMETheSlave");

  bluetooth_serial.print("AT+ROLE0"); // Set Slave (Peripheral)

  // Send AT+RADD? on Master to discover (whit debugger code)...
  bluetooth_serial.print("AT+CON------------"); // Connect to Master
}

void loop() {
  bluetooth_serial.print("Hi! I'm a slave...");

  delay(1000);
}
