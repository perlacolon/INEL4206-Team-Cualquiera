#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "driver/adc.h"

// MQTT domain
const char* mqtt_server = "istheacon.space";

// MQTT Var in Node Red
const char* topic = "temp";

// WiFi SSID
const char* ssid = "perlaaron"; 
// WiFi Pasword
const char* password = "7jbrgxGNxxmy";  

// LED pin in circ (entradas y salidas)
const int led = 2;

WiFiClient espClient; //conecta al wifi con esp32
PubSubClient client(espClient); //conecta esp32 con nodered
long lastMsg = 0; // 64 bits
char msg[50];

float temperature = 0;

const int sensor = 32;

void setup() {

  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

 pinMode(sensor, INPUT);   
 pinMode(led, OUTPUT);

 adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
 adc1_config_width(ADC_WIDTH_BIT_12); // default
}

void setup_wifi() {
  delay(10);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.println("Domain: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();


  if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
   if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    
    float voltage = (float) adc1_get_raw(ADC1_CHANNEL_4) / 4096 * 3.3; //getrawdata
    float temperature = (voltage - 0.5) * 100; //celsius 
    temperature = temperature * 1.8 + 32; //farenheit (si se comenta, los grados seran celcios)

    char tempString[8];
    dtostrf(temperature, 1, 2, tempString); // float to string
    Serial.print("Temperature: ");
    Serial.print(tempString);
    Serial.println("°F"); // cambiar por grados C
    
    client.publish("temp", tempString);
  
  }

  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}