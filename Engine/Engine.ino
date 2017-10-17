
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <string.h>

Adafruit_MotorShield motorShield = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);

char data = '0';            //Variable for storing received data
void left();
void right();
void down();
void up();


void setup() {
  motorShield.begin(); //start connection to motor shield

  Serial.begin(9600);   //Sets the baud for serial data transmission

  //set right and left motors to max speed
  rightMotor->setSpeed(255);
  leftMotor->setSpeed(255);
}

void loop() {

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
        default :
          leftMotor->run(RELEASE);
          rightMotor->run(RELEASE);
          break;
      }
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
