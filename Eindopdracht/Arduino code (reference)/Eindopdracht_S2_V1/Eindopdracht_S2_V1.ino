//http://www.tautvidas.com/blog/2012/08/distance-sensing-with-ultrasonic-sensor-and-arduino/
//https://bitbucket.org/teckel12/arduino-new-tone/wiki/Home

#include <NewPing.h>
#include <NewTone.h>


#define TRIGGER_PIN 5
#define ECHO_PIN 4
#define MAX_DISTANCE 100

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int distance;
int motorAuto = 9;
int ledAuto = 7;
int led2Auto = 6;
int speaker = 10;
int pwnValue;
bool debug = true;
long duration, cm;
int val = 0;

int melody[] = { 262, 196};

void setup() {
  // put your setup code here, to run once:
  if (debug){
   Serial.begin(9600);
   pinMode(motorAuto, OUTPUT);
   pinMode(ledAuto, OUTPUT);
   pinMode(led2Auto, OUTPUT);
   calibrate();
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
 unsigned int uS = sonar.ping();
 pinMode(ECHO_PIN,OUTPUT);
 digitalWrite(ECHO_PIN,LOW);
 pinMode(ECHO_PIN,INPUT);
 
 distance = (uS/US_ROUNDTRIP_CM);
 int val_buffer = distance;
 if (distance < 500){
  val += (val_buffer - val)/4;
 }

 
 if(debug){
  Serial.println("Object found at: ");
  Serial.println(val);
 }
 pwnValue = map(val, 2 ,500, 0 , 255);
 analogWrite(motorAuto, pwnValue); 
 if(pwnValue < 50) {
  digitalWrite(ledAuto,HIGH);
  digitalWrite(led2Auto,HIGH);
//  for (int thisNote = 0; thisNote < 2; thisNote++) { // Loop through the notes in the array.
  //  NewTone(speaker, melody[thisNote], 4); // Play thisNote for noteDuration.
   // delay(4 * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
 // }
 }
 else {
  digitalWrite(ledAuto,LOW);
  digitalWrite(led2Auto,LOW);
  noNewTone(speaker); 
 }
  delay(100);
 
}

void calibrate()
{
  long val_cali = 0;
  for (int i = 0; i < 10; i++)
  {
    unsigned int uS = sonar.ping();
    distance = (uS/US_ROUNDTRIP_CM);
    int val_buffer = distance;
    if (val_buffer < 500) // als binnen de 5m, dat kan de sensor, blokkeert onzinwaarden en ruis
      val_cali += val_buffer;
  }
  val = val_cali / 10;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
