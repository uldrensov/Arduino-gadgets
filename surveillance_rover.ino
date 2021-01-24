//ensure that TX and RX of the HM-10 are hooked up to arduino pins 2 and 3, respectively
//assumes the red wires of the two motors are hooked up to OUT1 and OUT4 of the L298N
//assume motor1 is on the left, and motor2 is on the right (top-down view, where the front of the car is the top)

#include <Dabble.h>


const int motor1PLUS = 6; //hooked up to IN1
const int motor1MINUS = 7; //hooked up to IN2
const int motor2PLUS = 8; //hooked up to IN3
const int motor2MINUS = 9; //hooked up to IN4
const int speed1 = 5;
const int speed2 = 10;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(motor1PLUS, OUTPUT);
  pinMode(motor1MINUS, OUTPUT);
  pinMode(motor2PLUS, OUTPUT);
  pinMode(motor2MINUS, OUTPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  
  Dabble.begin(9600);
}


void loop() {
  Dabble.processInput();

  //forward
  if (GamePad.isUpPressed()){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(motor1PLUS, HIGH);
    digitalWrite(motor1MINUS, LOW);
    digitalWrite(motor2PLUS, HIGH);
    digitalWrite(motor2MINUS, LOW);
  }
  //backward
  else if (GamePad.isDownPressed()){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(motor1PLUS, LOW);
    digitalWrite(motor1MINUS, HIGH);
    digitalWrite(motor2PLUS, LOW);
    digitalWrite(motor2MINUS, HIGH);
  }
  //right turn (clockwise)
  else if (GamePad.isRightPressed()){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(motor1PLUS, HIGH);
    digitalWrite(motor1MINUS, LOW);
    digitalWrite(motor2PLUS, LOW);
    digitalWrite(motor2MINUS, HIGH);
  }
  //left turn (anti-clockwise)
  else if (GamePad.isLeftPressed()){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(motor1PLUS, LOW);
    digitalWrite(motor1MINUS, HIGH);
    digitalWrite(motor2PLUS, HIGH);
    digitalWrite(motor2MINUS, LOW);
  }
  //neutral
  else{
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(motor1PLUS, LOW);
    digitalWrite(motor1MINUS, LOW);
    digitalWrite(motor2PLUS, LOW);
    digitalWrite(motor2MINUS, LOW);
  }
}
