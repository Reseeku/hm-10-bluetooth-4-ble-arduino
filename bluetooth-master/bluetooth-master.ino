#include <SoftwareSerial.h>

SoftwareSerial bluetooth_serial(10, 11);

void setup() {
  Serial.begin(9600);

  bluetooth_serial.begin(9600);

  bluetooth_serial.print("AT+NAMETheMaster");

  bluetooth_serial.print("AT+ROLE1"); // Set Master (Central)

  // Send AT+RADD? on Slave to discover (whit debugger code)...
  bluetooth_serial.print("AT+CON------------"); // Connect to Slave
}

void loop() {
  if (bluetooth_serial.available()) {
    String s = "";
    char c;
    while((c = bluetooth_serial.read()) != -1) {
      s += c;
      delay(5);
    }

    Serial.print("Some slave message: " +  s + "\n");
  }
}
