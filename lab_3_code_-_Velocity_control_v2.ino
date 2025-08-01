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
  return map(speed, 0, 200, 90, 180);
}

// Calculate delay proportional to distance/speed (in ms)
int travelTime(int distance, int speed) {
  // For simplicity, assume linear relation, scale factor 10 (adjust after testing)
  return (distance * 1000) / speed;
}

// Helper to move forward at speed
void moveForward(int speed) {
  int pwmVal = speedToPWM(speed);
  leftMotor.write(pwmVal);
  rightMotor.write(pwmVal);  // Both motors forward
}

// Halt function: stop motors and delay
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
  // A to B (distance 100) speed 100
  moveForward(100);
  delay(travelTime(100, 100));
  halt();
  turnRight();

  // B to C (distance 150) speed 150
  moveForward(150);
  delay(travelTime(150, 150));
  halt();
  turnLeft();

  // C to D (distance 200) speed 200
  moveForward(200);
  delay(travelTime(200, 200));
  halt();
  turnRight();

  // D to F (distance 80) speed 80
  moveForward(80);
  delay(travelTime(80, 80));
  halt();
  turnLeft();

  // F to R (distance 100) speed 100
  moveForward(100);
  delay(travelTime(100, 100));
  halt();
  turnRight();

  // R to G (distance 150) speed 150
  moveForward(150);
  delay(travelTime(150, 150));
  halt();
  turnLeft();

  // G to H (distance 200) speed 200
  moveForward(200);
  delay(travelTime(200, 200));
  halt();
  turnRight();

  // H to I (distance 100) speed 100
  moveForward(100);
  delay(travelTime(100, 100));
  halt();
  turnLeft();

  // I to J (distance 150) speed 150
  moveForward(150);
  delay(travelTime(150, 150));
  halt();
  turnLeft();

  // J to K (distance 200) speed 200
  moveForward(200);
  delay(travelTime(200, 200));

  halt();

  while (true) {
    // stop here forever
  }
}
