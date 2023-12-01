#include <Servo.h>

Servo myservo;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT); 
  myservo.attach(9);
  Serial.begin(9600);
}

void loop()
{
int gasContent = analogRead(A0);
int waterContent= analogRead(A1);

Serial.print("Water Content =");
Serial.println(waterContent);
Serial.println("===============");
delay(1000);

Serial.print("Gas Content =");
Serial.println(gasContent);
Serial.println("==============");
delay(1000);

if (gasContent > 350){
digitalWrite(led2,HIGH);
delay(500);
digitalWrite(led2,LOW);
delay(1000);
}

else if (waterContent > 300){
digitalWrite(led3,HIGH);
delay(500);
digitalWrite(led3,LOW);
delay(1000);
myservo.write(180);
delay(500);
myservo.write(0);
delay(500);
}

else{
digitalWrite(led1,HIGH);
}

} 
