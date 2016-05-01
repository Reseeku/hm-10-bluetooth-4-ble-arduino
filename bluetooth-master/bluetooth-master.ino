#include <SoftwareSerial.h>

SoftwareSerial bluetooth_serial(10, 11);

void setup() {
  Serial.begin(9600);

  bluetooth_serial.begin(9600);

  bluetooth_serial.print("AT+NAMESR-Master");

  bluetooth_serial.print("AT+ROLE1"); // Set Master (Central)

  bluetooth_serial.print("AT+CONXXXXXXXXXXXX"); // Connect to Slave
}

void loop() {
  if (bluetooth_serial.available()) {
    String s = "";
    char c;
    while((c = bluetooth_serial.read()) != -1) {
      s += c;
    }

    Serial.print('Some slave message: ' +  s);
  }
}
