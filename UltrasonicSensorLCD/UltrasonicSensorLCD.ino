// include the library code:
#include <LiquidCrystal.h>

// define pins for ultrasonic sensor
#define trigPin 10
#define echoPin 13

// define pin for active buzzer
#define buzzerPin 6

// define floats for ultrasonic sensor use
float duration, distance;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up ultrasonic sensor i/o
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance = (duration / 2) * 0.0343;

  // clear the LCD and position cursor in upper-left corner
  lcd.clear();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    tone(buzzerPin, 261, 0.01);
    lcd.print("Out of range");
    Serial.println("Out of range");
  }
  else {
    noTone(buzzerPin);
    lcd.print("Dist: " + String(distance) + " cm");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  
  delay(500);
}
