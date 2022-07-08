/*
 controlling DC motor speed and direction in order to make a shaker for piezoelectric energy harvesting
 */
 
int ENA = 9;
int in1 = 8;
int in2 = 7;

// speed control potentiometer
int SpeedControl = A0;

// Motor speed value starts at zero
int MotorSpeed = 0;

void setup()
{
  // set the motor control pins to output
  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}
void demo()
{
  // This function will run the motor in both directions at a speed which is defined by potentiometer
  // turn on the motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Read the value from potentiometer
  MotorSpeed = analogRead(SpeedControl);
  
  // convert to range of 0-255
  MotorSpeed = map(MotorSpeed, 0, 1023, 0, 255);
  
  // set the motor speed
  analogWrite(ENA,225);
  delay(20);
  
  // change motor direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(36);

   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(17);
  
  // turn off the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(680);
}


void loop(){

  demo();
  delay(0);

  
  }
