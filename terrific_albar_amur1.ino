// C++ code
//

#include <LiquidCrystal.h>

int triggerPin = 12;
int echoPin = 13;
unsigned long distance;
unsigned int duration;

int redPin = 9;
int greenPin = 11;
int bluePin = 10;

LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
const int contrast = 2;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  analogWrite(contrast, 100);
  lcd.begin(16, 2);
}

void loop()
{
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  
  lcd.setCursor(0, 0);
  lcd.print("Distance: " + String(distance) + " cm");
  
  if (distance <= 100){
  	digitalWrite(redPin, 252);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Too Close         ");
  }
  
  if (distance >= 225) {
  	digitalWrite(redPin, 0);
    digitalWrite(greenPin, 252);
    digitalWrite(bluePin, 0);
    lcd.setCursor(0, 1);
    lcd.print("Good Distance away");
  }
  if (distance < 225 && distance > 100){
  	digitalWrite(redPin, 252);
    digitalWrite(greenPin, 252);
    digitalWrite(bluePin, 0);
	lcd.setCursor(0, 1);
    lcd.print("Go a bit further");
  }
  
}