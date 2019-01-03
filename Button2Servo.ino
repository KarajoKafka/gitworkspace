#include <Servo.h>
int led = 3; //LED_BUILTIN;
int brightness = 0;
Servo serv1;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  serv1.attach(3);                  //servo attached to pwn
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A0);//for button 1
  int sensorValue1 = analogRead(A1);//for button 2
  int delayT = 300;                 //time to leave cervo on
  int stopT = 1400;                 //microseconds to stop at
  if ((sensorValue0 <= 10) & (sensorValue1 <= 10)){ //if button 1 and 2 are not pushed
    //analogWrite(led, 512); 
    serv1.writeMicroseconds(stopT); //don't do anything
  }
  if ((sensorValue0 <= 10) & (sensorValue1 > 200)){ //if button 2 is pushed
//    analogWrite(led, 100); 
    serv1.writeMicroseconds(1000);  //rotate clockwise
    delay(delayT);                  //wait for correct degrees rotated
    serv1.writeMicroseconds(stopT); //stop
  }
  if ((sensorValue0 > 200) & (sensorValue1 <= 10)){ //if button 1 is pushed
//    analogWrite(led, 1000); 
    serv1.writeMicroseconds(1635);  //rotate counterclockwise
    delay(delayT);                  //wait for correct degrees rotated
    serv1.writeMicroseconds(stopT); //stop
  }
  Serial.println((String) sensorValue0 + " " + (String) sensorValue1);
  delay(30);
}

