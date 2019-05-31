#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>
SoftwareSerial s(4,5); //pin D1,D2

char auth[] = "45517a83047f4eb3adcd9d788e285d17"; //token dari Blynk
char ssid[] = " "; //isi dengan nama dari jaringan yang digunakan
char pass[] = " "; //isi dengan password dari jaringan yang digunakan

int data1, data2, data3, data4;
BLYNK_WRITE(V1)
{
  data1 = param.asInt(); 
}
BLYNK_WRITE(V2)
{
  data2 = param.asInt(); 
}
BLYNK_WRITE(V3)
{
  data3 = param.asInt(); 
}
BLYNK_WRITE(V4)
{
  data4 = param.asInt(); 
}
void setup() {
Blynk.begin(auth, ssid, pass);
Serial.begin(9600);
s.begin(9600);
}

void loop() {
 Blynk.run();
 StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();
    root["servo1"] = data1;
    root["servo2"] = data2;
    root["servo3"] = data3;
    root["servo4"] = data4;
    root.printTo(s);
}
