#include <Servo.h>
#include <Ultrasonic.h>
Servo myservo;
Ultrasonic ultrasonic(5,8);
int ledPinRed = 13;
int ledPinGreen = 12;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPinRed, OUTPUT);
pinMode(ledPinGreen, OUTPUT);
pinMode(3, OUTPUT);
myservo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(ultrasonic.read(INC));
Serial.println(" INCH");
if(ultrasonic.read(INC) <= 5){
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinRed, LOW);  
  delay(15);
  myservo.write(180);              
  }
  else {
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, HIGH);
  delay(15);
  myservo.write(0); 
  }
delay(500);
}
