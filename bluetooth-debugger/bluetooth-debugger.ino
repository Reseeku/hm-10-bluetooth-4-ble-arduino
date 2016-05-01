#include <SoftwareSerial.h>

SoftwareSerial bluetooth_serial(10, 11);

volatile boolean bluetooth_serial_rate_detected = false;

long serial_rates[] = {
  9600, 57600, 115200,
  19200, 38400, 4800, 2400, 1200, 230400
};

bool discover_bluetooth_serial_rate() {
  for (int i = 0; i < (sizeof(serial_rates)/sizeof(long)); i++) {
    Serial.print(".");
    
    long rate = serial_rates[i];
    
    bluetooth_serial.begin(rate);
    bluetooth_serial.write("AT");
    bluetooth_serial.flush();
    if (bluetooth_serial.readString() == "OK") {
      Serial.println("\nBluetooth Serial Rate detected: " + String(rate));
      return true;
    } else {
      bluetooth_serial.end();
    }
  }

  Serial.println("\nBluetooth Serial Rate not detected.");
  
  return false;
}


void setup() {
  Serial.begin(9600);
  
  bluetooth_serial_rate_detected = discover_bluetooth_serial_rate();
}

void loop() {
  if(bluetooth_serial_rate_detected) {
    if (bluetooth_serial.available()) {
      String s = "";
      char c;
      while((c = bluetooth_serial.read()) != -1) {
        s += c;
        delay(5);
      }
  
      Serial.println("Received: " + s);
    }
  
    if (Serial.available()) {
      String s = "";
      char c;
      while((c = Serial.read()) != -1) {
        s += c;
        delay(5);
      }
  
      Serial.println("Sent: " + s);
      
      bluetooth_serial.print(s);
    }
  }
}
