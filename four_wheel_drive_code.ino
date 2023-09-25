int in1 = 7; 
int in2 = 6; 
int in3 = 5;
int in4 = 4;

void setup() { 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
} 

void TurnMotorA(){
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
} 

void TurnOFFA(){
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
} 

void loop() { 
  TurnMotorA(); 
  delay(3000); 
  TurnOFFA();
  delay(2000); 
}