
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <string.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);

char data = '0';            //Variable for storing received data
int ledPin = 8;                 // LED connected to digital pin 13
void left();
void right();
void down();
void up();
void triangle();
void square();
void circle();
void crossX();


void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  leftMotor->setSpeed(255);
  Serial.begin(9600);   //Sets the baud for serial data transmission
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output

  //leftMotor->run(FORWARD);
   digitalWrite(ledPin, HIGH);   // sets the LED on
         // Serial.print("Hello World");          //Print Value inside data in Serial monitor

  rightMotor->setSpeed(255);
  //rightMotor->run(FORWARD);

}

void loop() {

    //delay(1000);                  // waits for a second

      //Serial.write(data);          //Print Value inside data in Serial monitor

  if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");

      switch(data){
        case '1': left(); break;
        case '2': up(); break;
        case '3': right();break;
        case '4': down(); break;
        case '5': square(); break;
        case '6': triangle(); break;
        case '7': circle();break;
        case '8': crossX(); break;
        default :     leftMotor->run(RELEASE);
                      rightMotor->run(RELEASE);
                      break;
      }
//      if(data == "1")              // Checks whether value of data is equal to 1
//         digitalWrite(ledPin, HIGH);   //If value is 1 then LED turns ON
//      else if(data == "0")         //  Checks whether value of data is equal to 0
//         digitalWrite(ledPin, LOW);    //If value is 0 then LED turns OFF
   }
}

void left(){
    leftMotor->run(BACKWARD);
    rightMotor->run(FORWARD);
  }

void right(){
    rightMotor->run(BACKWARD);
    leftMotor->run(FORWARD);
}
void down(){
      rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);
}
void up(){
     rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
}
void triangle(){}
void square(){}
void circle(){}
void crossX(){}
