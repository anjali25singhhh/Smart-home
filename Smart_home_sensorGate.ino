#include<Servo.h>
const int trigPin= 7;
const int echoPin=6;
const int buzzer=4;
const int sensorpin=A0;
const int threshold=400;
Servo servo;
void setup()
{
  Serial.begin(9600);
  pinMode(sensorpin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  servo.attach(9);
  servo.write(0);
  Serial.begin(9600);
  delay(1000);
}
void loop()
{
  int serialvalue=analogRead(A0);
  Serial.print("Sensor value: ");
  Serial.print(serialvalue);
  if(serialvalue>threshold)
  {
    digitalWrite(buzzer, HIGH);
    Serial.print("Gas leakage detected");
  }
  else
  {
    digitalWrite(buzzer, LOW);
    Serial.print("Normal");
  }
  delay(1000);
  long duration,distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration * 0.034 / 2;
  if(distance<15)
  {
      OpenDoor();
      CloseDoor();
  }
}
void OpenDoor()
{
  servo.write(60);
  delay(200);
  servo.write(100);
  delay(200);
  servo.write(160);
  delay(2000);
}
void CloseDoor()
{
  servo.write(160);
  delay(100);
  servo.write(90);
  delay(100); 
  servo.write(45);
  delay(100);
  servo.write(0);
  delay(1000);
}
