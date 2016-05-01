# HM-10: Arduino Bluetooth 4.0

#### Bluetooth Low Energy

[Datasheet](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/blob/master/datasheet.pdf) contains full documentation and the list of available `AT` commands.

* [Circuit Diagram](#circuit-diagram)
* [Debugging](#debugging)
* [Master / Slave Communication](#master--slave-communication)

## Circuit Diagram
Fritzing file: [prototype.fzz](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/raw/master/prototype.fzz)
![Arduino Uno and Arduino Nano Fritzing Prototype Demo](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/raw/master/images/prototype_bb.png)

## Debugging
Just upload the [bluetooth-debugger.ino](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/blob/master/bluetooth-debugger/bluetooth-debugger.ino) code to Arduino and open the Serial Monitor:
![Debugging](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/raw/master/images/debugger.png)

## Master / Slave Communication
Upload the [bluetooth-slave.ino](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/blob/master/bluetooth-slave/bluetooth-slave.ino) code to Arduino whit the `Slave` HM-10.

Upload the [bluetooth-master.ino](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/blob/master/bluetooth-master/bluetooth-master.ino) code to Arduino whit the `Master` HM-10 and open the Serial Monitor:
![Master / Slave](https://github.com/gbaptista/hm-10-bluetooth-4-ble-arduino/raw/master/images/master-slave.png)
