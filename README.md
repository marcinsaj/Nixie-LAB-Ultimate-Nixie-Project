# Nixie-LAB-Ultimate-Nixie-Project

Build a clock, counter, thermometer or any display with 2/4/6/8/10 nixie tubes.
You can use your favorite platform for this: Arduino, Raspberry Pi, Particle etc. Are you interested?
Imagine that you can use any nixie tube and not worry about the technical parameters: power requirements, current, and what is most troublesome and what you also do not have to worry about are different types of tubes with different pin layout is not a problem either. The device has been designed to make work with nixie tubes as easy as possible.
**Currently only Arduino is supported, work is underway to extend functionality.

* Assembly Requirements - <a href="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/raw/master/datasheet/Nixie-Lab-Assembly-Requirements.pdf">download</a>
* <a href="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/blob/master/datasheet/Nixie-Lab-Assembly-Instruction.md">Assembly Instruction - Images</a>
* Master/Slave Configuration - <a href="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/raw/master/datasheet/Nixie-Lab-Master-Slave-Jumper-Settings.pdf">download</a>
* Schematic - <a href="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/raw/master/datasheet/Nixie-Lab-Schematic.pdf">download</a>
* <a href="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/tree/master/examples/Arduino">Arduino Example Code</a>

<p align="center"><img src="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/blob/master/extras/nixie-lab-project-cover.jpg"></p>

The Nixie Lab master module contains: real time clock RTC module DS3231, sensor connector for DHT22 or DHT11, several configuration jumpers, connectors for Arduino board (Arduino Uno form factor). The device is compatible with  5V / 3.3V boards. Instead of the basic Arduino board, using specially designed adapters, the master module can be connected with e.g. Raspberry Pi, other Arduino boards Nano/Micro, Particle Photon / Argon / Xenon, Wemos D1 Mini, D1 Mini Pro, D32, D32 Pro. **Currently only Arduino is supported, work is underway to extend functionality.

<p align="center"><img src="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/blob/master/extras/nixie-lab-diagram.jpg"></p>

## Main Features
Each of the Nixie Lab modules can operate as a master (control) or as a slave (commands receiver). The modules can be connected in series in a 1 master and up to 4 slaves configuration. Each module has connectors for two nixie sockets. Currently, there are 25 different tube sockets available for over a hundred different tubes and several new sockets are being prepared. Sockets no. 20, 23, 24 only version A – these sockets are specially designed to this device and dedicated for multi segment tubes e.g. B7971, B8971 etc. In the case of a larger number of tubes or tubes with higher power consumption e.g. B7971, a additional Nixie Power Supply module can be connected to each slave module.

<p align="center"><img src="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/blob/master/extras/nixie-lab-master-slave.png"></p>

The control module must be the first module in a series of devices (first from the left). Other modules can only be connected to the right of the control module. It is possible to combine a total of 5 modules, which allows you to control 10 nixie tubes. If necessary, a separate Nixie Power Supply can be added to each Nixie Lab module.

## Compatible Sockets
All sockets have the same pin layout which allows easy replacement of the sockets for different nixie tubes without having to change the control program code (e.g. Arduino code). Each of the sockets (connected to the device) provides the valid power supply parameters for the compatible nixie tubes (supply voltage and current). You don’t have to worry about that either.
**<a href="https://github.com/marcinsaj/Nixie-Tube-Sockets">Show me Compatible Sockets</a>**

<p align="center"><img src="https://github.com/marcinsaj/Nixie-LAB-Ultimate-Nixie-Project/blob/master/extras/nixie-lab-8-5-nixie-tubes-2.jpg"></p>
