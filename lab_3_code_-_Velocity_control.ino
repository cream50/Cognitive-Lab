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

// Speed control: map speeds to servo PWM values (calibrate as needed)
int speedToPWM(int speed) {
  // Map speed 0-200 to PWM 90-180 (example)
  return map(speed, 0, 200, 90, 180);
}

// Helper to move forward at speed
void moveForward(int speed) {
  int pwmVal = speedToPWM(speed);
  leftMotor.write(pwmVal);
  rightMotor.write(180 - pwmVal);  // reverse for right wheel if needed
}

// Halt function: stop motors and delay
void halt() {
  leftMotor.write(90);   // 90 = stop for continuous rotation servos
  rightMotor.write(90);
  delay(3000);           // halt for 3 seconds
}

// Turn functions
void turnLeft() {
  steering.write(STEER_LEFT);
  delay(1000);  // wait 1 sec for turn completion, adjust timing as needed
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

  // Initialize
  steering.write(STEER_STRAIGHT);
  halt();
}

void loop() {
  // Start from A to B at speed 100
  moveForward(100);
  delay(2000);   // estimated time to reach B, adjust as per distance & speed
  halt();
  turnRight();

  // B to C at speed 150
  moveForward(150);
  delay(2000);
  halt();
  turnLeft();

  // C to D at speed 200
  moveForward(200);
  delay(2000);
  halt();
  turnRight();

  // D to F at speed 80
  moveForward(80);
  delay(2000);
  halt();
  turnLeft();

  // F to R at speed 100
  moveForward(100);
  delay(2000);
  halt();
  turnRight();

  // R to G at speed 150
  moveForward(150);
  delay(2000);
  halt();
  turnLeft();

  // G to H at speed 200
  moveForward(200);
  delay(2000);
  halt();
  turnRight();

  // H to I at speed 100
  moveForward(100);
  delay(2000);
  halt();
  turnLeft();

  // I to J at speed 150
  moveForward(150);
  delay(2000);
  halt();
  turnLeft();

  // J to K at speed 200
  moveForward(200);
  delay(2000);

  // Stop after whole path
  halt();

  // Do nothing after finishing the path
  while (1) {
    // idle loop
  }
}
