#include <Servo.h>

Servo leftMotor;   // Motor 1 - left wheel
Servo rightMotor;  // Motor 2 - right wheel
Servo steering;    // Motor 3 - steering servo
Servo auxMotor;    // Motor 4 - auxiliary (not used here)

// Define pins (change according to your wiring)
const int leftMotorPin = 3;
const int rightMotorPin = 5;
const int steeringPin = 6;
const int auxMotorPin = 9;

// Steering positions (adjust based on your servo calibration)
const int STEER_STRAIGHT = 90;
const int STEER_LEFT = 45;
const int STEER_RIGHT = 135;

// Fixed travel delay for distance x (in ms) - adjust based on your vehicle speed
const int DISTANCE_X_TIME = 3000;  // time to travel distance x
const int DISTANCE_2X_TIME = DISTANCE_X_TIME * 2;  // double distance

// Move forward at fixed speed
void moveForward() {
  leftMotor.write(180);   // full forward (adjust if needed)
  rightMotor.write(180);
}

// Stop motors and delay (halt)
void halt() {
  leftMotor.write(90);   // stop
  rightMotor.write(90);
  delay(3000);           // halt for 3 seconds
}

// Turn functions
void turnLeft() {
  steering.write(STEER_LEFT);
  delay(1000);
  steering.write(STEER_STRAIGHT);
}

void turnRight() {
  steering.write(STEER_RIGHT);
  delay(1000);
  steering.write(STEER_STRAIGHT);
}

void setup() {
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
  steering.attach(steeringPin);
  auxMotor.attach(auxMotorPin);

  steering.write(STEER_STRAIGHT);
  halt();
}

void loop() {
  // Move forward then turn right
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnRight();

  // Move forward then turn left
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnLeft();

  // Move forward then turn right
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnRight();

  // Move forward then turn left
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnLeft();

  // Move forward then turn left
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnLeft();

  // Move forward double distance then turn right
  moveForward();
  delay(DISTANCE_2X_TIME);
  halt();
  turnRight();

  // Move forward then turn left
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnLeft();

  // Move forward then turn right
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();
  turnRight();

  // Move forward then halt
  moveForward();
  delay(DISTANCE_X_TIME);
  halt();

  while (true) {
    // stop here forever
  }
}
