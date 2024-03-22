#include <SoftwareSerial.h>
SoftwareSerial bt(3,2);
const int led1=8;
const int led2=7;
const int led3=5;
const int fan=9;

char msg;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(fan, OUTPUT);
  Serial.begin(9600);
  bt.begin(9600);
  Serial.println("Ready to connect\n Default password is 1234 or 0000");
}
void loop()
{
  msg=bt.read();

  if(bt.available()){
    Serial.println("Able to Connect");
  }

  Serial.println(msg);

  delay(100);

  if(msg == "F"){
    digitalWrite(fan, HIGH);
    delay(3000);
  }else if(msg == "O"){
    digitalWrite(fan, LOW);
  }
}
