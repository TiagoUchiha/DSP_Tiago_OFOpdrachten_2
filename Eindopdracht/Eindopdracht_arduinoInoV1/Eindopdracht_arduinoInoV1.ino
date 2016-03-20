//http://www.tautvidas.com/blog/2012/08/distance-sensing-with-ultrasonic-sensor-and-arduino/

#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int distance;
int motorAuto = 9;
int ledAuto = 10;
int led2Auto = 11;
int pwnValue;
bool debug = true;
long duration, cm;

void setup() {
  // put your setup code here, to run once:
  if (debug){
   Serial.begin(9600);
   pinMode(motorAuto, OUTPUT);
   pinMode(ledAuto, OUTPUT);
   pinMode(led2Auto, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
 unsigned int uS = sonar.ping();
 pinMode(ECHO_PIN,OUTPUT);
 digitalWrite(ECHO_PIN,LOW);
 pinMode(ECHO_PIN,INPUT);
 
 distance = (uS/US_ROUNDTRIP_CM);
 if(debug){
  Serial.println("Object found at: ");
  Serial.println(distance);
 }
 pwnValue = map(distance, 2 ,200, 0 , 255);
 analogWrite(motorAuto, pwnValue); 
 delay(100);
 
}


long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
