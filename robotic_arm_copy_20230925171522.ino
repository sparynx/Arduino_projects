#include <Servo.h>

Servo servoMotor;  // Create a servo object

int servoPin = 9;  // Define the pin for the servo motor

int angle = 0;     // Initialize the initial angle for the servo motor
int increment = 1; // Angle increment for movement
int delayTime = 15; // Delay between angle increments (adjust as needed)

void setup() {
  servoMotor.attach(servoPin);  // Attaches the servo on pin 9 to the servo object
}

void loop() {
  // Sweep the servo motor back and forth
  for (angle = 0; angle <= 180; angle += increment) {
    servoMotor.write(angle); // Set the servo angle
    delay(delayTime);        // Delay for smoother motion
  }
  
  for (angle = 180; angle >= 0; angle -= increment) {
    servoMotor.write(angle); // Set the servo angle
    delay(delayTime);        // Delay for smoother motion
  }
}