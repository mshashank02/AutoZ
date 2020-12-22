const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int led=13;
void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 7 as output
  pinMode(echoPin, INPUT);// initialising pin 6 as input
  pinMode(led,OUTPUT);

}

void loop() 
{
  long duration,  cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
 
  cm = microsecondsToCentimeters(duration); // calling method
  
 
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if (cm <=500)
  {digitalWrite(led,HIGH);
   delay(500);
   digitalWrite(led,LOW);
   delay(500);};
   

}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
