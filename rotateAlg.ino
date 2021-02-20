//Purpose: rotate servo cw 180, ccw 90, cw 90, c
/*
 * Doug Whitton Jan 2021
 * Thiscode works with a standard servo motor 
 * It makes the servo arm rotate automatically back and forth 
 */

#include <Servo.h>

Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 9;       // Control pin for servo motor
int servoAngle = 0;     // variable for changing the angle of the servo 0 - 180

void setup() {
  Serial.begin(9600);                // initialize serial communications
  servoMotor.attach(servoPin);       // attaches the servo on pin 3 to the servo object
} 
 
void loop() {
  //stored angles in array index
  int index[] = {180,90,90,180};
  
  //rotates according to array index 
  //x dictates + or - direction
  int x = 1; 
  for(int i = 0; i<4; i=i+x){
    if (i==0||i==2) x=1; //for the first + third rotation, the direction is positive (clock wise)
    if (i==1||i==3) x=-1; //for the second + last rotation, the direction is negative (counterclock wise)

  //updates motor
 servoMotor.write(index[i]);
  Serial.println(index[i]);
}
}

//initial code provided from class 
//  int x =1;
//    for (int i = 0; i > -1; i = i + x){
//    servoMotor.write(i); 
//       
//    if (i==180) x=-1;
//    delay(10);                         // change the delay to speed up or slow down
//    Serial.println(i);   
//    } 
//  }

//   
//
