# INEL4206-Team-Cualquiera

Teammates:
Edmarie Santana Camacho,
Perla N. Colón Marrero, 
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


Node Red Implementation:

To implement Node Red, we acquired a domain name (istheacon.space). Using Lightsail, a web server service provided by AWS (Amazon Web Services), we 
were able to use a Virtual Machine with the Ubuntu operating system. Then this was used to host Node Red, to receive the MQTT data of the ESP32 and 
display it on a Node Red-generated web page.

The display web page with the table (Temp vs Time) can be accessed through the domain “istheacon.space:1880/ui”. The acronym UI stands for user 
interface, this is where the user will be able to access in real time the temperature readings. As you may notice in Figure 5, there is a noticeable 
change between reading, this is because it was placed in room temperature first and then in the fridge. This to prove that the temperature sensor is working correctly.

Node Red Documentation:

- Aedes MQTT broker: enables MQTT node functionality. 
- MQTT-in Node: receives MQTT data from the ESP32 via the Lightsail Virtual Machine.
- Function Nodes (Function 1, Function 2, Function 3): take msg.payload as input and use it as a parameter for a JavaScript function. These functions convert the MQTT voltage data of the ESP32 into temperature values using the data from Figure 1. Function 1 reformats the converted data to fit the 
table node, Function 2 reformats the converted data to fit the graph node, and Function 3 debugs.
- Table: presents the input data as a table on the web page.
- Graph node: uses the input data as the y axis in a graph (the x axis is time by default).
- Debug Node: displays the input data in the debugger tab of Node Red.
- Inject Node: injects information to the display web page.
- Template Node: prints the msg string for the display.
- Get/temp Node: displays msg to webpage with readings.
