#include <Servo.h>
Servo myservo;

#define pin_pwm 11
#define pin_yon 12
#define input1 10
#define input2 9
#define duzgidis_aktif 7
int pos;

void setup() 
{
 myservo.attach(2);
 pinMode(input1,INPUT);
 pinMode(input2,INPUT);
 pinMode(duzgidis_aktif,INPUT_PULLUP);
 pinMode(pin_pwm, OUTPUT);
 pinMode(pin_yon, OUTPUT);

 pos=90;
 myservo.write(pos);
}

void loop() 
{
  if(digitalRead(duzgidis_aktif)==LOW)
  {
   digitalWrite(pin_yon, 0);      
   analogWrite(pin_pwm, 85);
  }
  else
  {
   digitalWrite(pin_yon, 0);      
   analogWrite(pin_pwm, 0);
  }

  //SAGA DÖNÜS
  if(digitalRead(input1)==HIGH && digitalRead(input2)==LOW)
  {
    myservo.write(115);
  }
  //SOLA DÖNÜS
  if(digitalRead(input1)==LOW && digitalRead(input2)==HIGH)
  {
    myservo.write(65);
  }
  //DÜZ GİDİS
  if(digitalRead(input1)==LOW && digitalRead(input2)==LOW)
  {
    myservo.write(90);
  }
  
}
