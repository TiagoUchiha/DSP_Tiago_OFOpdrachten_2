//https://www.arduino.cc/en/Tutorial/Debounce
int potMeter = A0;
int button = 2;
//int button3 = 10;
//int button2 = 11;
int potMeterValue, potMeterValueMapped, buttonValue, buttonValue2, buttonValue3;
int buttonState, lastButtonState = LOW;
long lastDebounceTime = 0, debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(57600);
   pinMode(potMeter, OUTPUT);
   //pinMode(button, INPUT);
  // pinMode(button2, OUTPUT);
 //  pinMode(button3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 potMeterValue = analogRead(potMeter);
// potMeterValueMapped = map(potMeterValue, 0, 1023, 0, 255);
// Serial.println("Potmeter ");
 Serial.println(potMeterValue);
 /* buttonValue = digitalRead(button);
 if (buttonValue != lastButtonState){
  lastDebounceTime = millis();
 }

 if((millis() - lastDebounceTime) > debounceDelay){
  if (buttonValue != buttonState){
    buttonState = buttonValue;
  }
 }
 Serial.println("Button ");
 Serial.println(buttonValue);
 buttonValue2 = digitalRead(button2);
 buttonValue3 = digitalRead(button3); */
 delay(1000);
}
