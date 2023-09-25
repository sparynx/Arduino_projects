#include <Servo.h>
Servo myservo;
int pos = 0;    
boolean fire = false;

// L298N Motor Driver Pin Definitions
#define ENA 13   // Enable pin for motor A
#define IN1 4    // Input 1 pin for motor A
#define IN2 5    // Input 2 pin for motor A
#define ENB 11    // Enable pin for motor B
#define IN3 6    // Input 1 pin for motor B
#define IN4 7    // Input 2 pin for motor B

#define pump 12

int motorspeed = 100;

// Define the analog input pins for the IR sensors
const int irSensorPin1 = A0;
const int irSensorPin2 = A1;
const int irSensorPin3 = A2;

// Variables to store sensor readings
int sensorValue1;
int sensorValue2;
int sensorValue3;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

   // Set L298N Motor Driver pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(pump, OUTPUT);

   myservo.attach(10);
  myservo.write(90);
}
  void put_off_fire()
{
    delay (500);
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.print("stop ");
   digitalWrite(pump, HIGH); delay(500);
   Serial.print("pump is on ");
   for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
  myservo.write(pos); 
  delay(10);
  }
  digitalWrite(pump,LOW);
  myservo.write(90);
  fire=false;
}

void loop() {
  // Read sensor values
  sensorValue1 = digitalRead(irSensorPin1);
  sensorValue2 = digitalRead(irSensorPin2);
  sensorValue3 = digitalRead(irSensorPin3);

  // Print sensor values
  Serial.print("IR Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print("\tIR Sensor 2: ");
  Serial.print(sensorValue2);
  Serial.print("\tIR Sensor 3: ");
  Serial.println(sensorValue3);

  if (sensorValue1 == 1 && sensorValue2 == 1 &&sensorValue3 == 1 ){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.print("stop ");
  }
  else if (sensorValue1 == 0){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorspeed); 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorspeed  );
  Serial.print("forward ");
  delay(200);
  fire = true;
  }

  else if (sensorValue2 == 0){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorspeed); 
  Serial.print("left");
  delay(200);
  }

  else if(sensorValue3 == 0){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, motorspeed);
  Serial.print("right ");
  delay(200);
  }
  delay(300); //Slow down the speed of robot
     while (fire == true)
     {
      put_off_fire();
     }
}