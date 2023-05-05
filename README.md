# INEL4206-Team-Cualquiera

Teammates:
Edmarie Santana Camacho
Perla N. Colón Marrero 
Jonhuel A. De León Hernandez


Introduction:
To carry out the project, an ESP32 microprocessor and an analog temperature sensor(LMT84) were used to read the ambient temperature. 
One of the main goals was to demonstrate IoT knowledge by sending an HTTP request from the ESP32 microprocessor to a cloud instance 
running on Node-Red. From the programming area, the C language was used, with the implementation of the MQTT library, which allows 
sensor data to be sent to a web server provided by Amazon Web Service. Node-Red was used next to the server to display the ambient 
temperature in real time via a Siri shortcut or from the correct domain with the creation of a web page. An LED light was implemented 
in the circuit together with ESP32 and the temperature sensor to demonstrate that the system runs without the need to be connected to 
the computer (it runs standalone, with battery, and without USB).


The Logical View Architecture:

From a logical architecture perspective, the system used sensors, transmissions, and data processing. To achieve this, we work with 
communication and cloud server components. The use of temperature sensors was implemented with an ESP32 device. After the sensors measure 
the temperature values, the data is transmitted, sending it to a central computer in the cloud, where it can be stored in a database, using 
wireless communication technologies such as WiFi. Users must be able to access the system through a website or through a voice assistant such 
as Siri, which allows them to interact with the system to learn temperature measurements.


The Process View Architecture: 

The system process architecture view was split to create a better structure and ease the project process. As a first step, all the necessary 
tools to carry out the project were installed; Software, Hardware, Arduino IDE, MQTT, GitHub, Amazon Web Service, etc. Then, an execution plan 
was created, along with an Architecture and Design Document.


The Physical View Architecture:

- ESP32 Board: This is the main hardware component of the system that collects temperature data from the sensor and communicates it to 
  the cloud server via the Internet.
- Temperature Sensor: This is the hardware component that measures the temperature of the room.
- Computer: It is used to generate and manage the software implemented in the project.
- Battery (the power supply): provides power to the ESP32 board and the temperature sensor.
- LED Light: This hardware component shows the operation of the system without the need to be connected to the computer (it runs independently, 
  with the battery, and without the need for USB)
  

Software Design: 

All the code used for this project was implemented using the Arduino IDE and C language. The C language libraries used include: (#include <WiFi.h>) 
connects the ESP32 to the Wifi, (#include <PubSubClient.h>) is an MQTT library to link the ESP32 data and Node Red via the AWS web server, 
(#include <Wire.h>) allows to communicate with I2C/TWI (sensors) devices, and (#include “driver/adc.h”) provides functions to correct for differences 
in measured voltages caused by variation of ADC reference voltages (Vref) between chips.


