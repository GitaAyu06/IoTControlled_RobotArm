#include <Servo.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(2,3);

int A; //Initialized variable to store recieved data
int B;
int C;
int D;
Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  Serial.begin(9600);
  s.begin(9600);
  while(!Serial) continue;
  s1.attach(PA6);     //definisi pin PWM yang digunakan pada STM32
  s2.attach(PA7);
  s3.attach(PB0);
  s4.attach(PB1);
  
  
}

void loop() {
StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  
  Serial.print("Servo1: "); //print untuk lihat nilai sudut servo yg dikirim dari NodeMCU
  int A=root["servo1"];
  Serial.println(A);
  s1.write(A);             //servo bawah
  
  Serial.print("Servo2: "); //print untuk lihat nilai sudut servo yg dikirim dari NodeMCU
  int B=root["servo2"];
  Serial.println(B);
  s2.write(B);            //servo kanan
  
  Serial.print("Servo3: "); //print untuk lihat nilai sudut servo yg dikirim dari NodeMCU
  int C=root["servo3"];
  Serial.println(C);
  s3.write(C);            //servo kiri
  
  Serial.print("Servo4: "); //print untuk lihat nilai sudut servo yg dikirim dari NodeMCU
  int D=root["servo4"];
  Serial.println(D);
  s4.write(D);           //servo gripper
}
