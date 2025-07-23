#include "HX711.h"
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Servo motor
Servo myservo;

// Blynk Credentials
#define BLYNK_TEMPLATE_ID "TMPL3cqPEVGX5"
#define BLYNK_TEMPLATE_NAME "dustbin"
#define BLYNK_AUTH_TOKEN "pncKwBBXEi5eL3Ysk7GhbIxIt-fUeA6n"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "project12345";       // Enter your WiFi name
char pass[] = "project12345";       // Enter your WiFi password

// Sensor Pins
const int LOADCELL_DOUT_PIN = D1;
const int LOADCELL_SCK_PIN = D2;
int fire = D0;
int gas = A0;
int trigPin = D6;
int echoPin = D7;
int vibration = D8;

HX711 scale;

void setup() {
  Serial.begin(9600);

  pinMode(fire, INPUT);
  pinMode(gas, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vibration, INPUT);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  myservo.attach(D5);

  Serial.println("System Initialized. Monitoring sensors...");

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  long reading = scale.read() - 160135;
  Serial.print("HX711 reading: ");
  Serial.println(reading);

  int fireState = digitalRead(fire);
  int gasState = digitalRead(gas);

  // Ultrasonic Distance Measurement
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  distance = map(distance, 15, 0, 0, 100); // Percent full

  // Fire Detection
  if (fireState == HIGH) {
    Serial.println("Fire detected!");
  } else {
    Serial.println("No fire detected.");
  }

  // Gas Detection
  if (gasState == HIGH) {
    Serial.println("Gas detected!");
  } else {
    Serial.println("No gas detected.");
  }

  // Distance Check
  if (distance <= 10) {
    Serial.print("Object detected at a distance of: ");
    Serial.print(distance);
    Serial.println(" cm. Too close!");
  } else {
    Serial.print("Distance measured: ");
    Serial.print(distance);
    Serial.println(" cm.");
  }

  delay(1000);

  // Vibration Detection
  for (int i = 0; i < 500; i++) {
    if (digitalRead(vibration) == HIGH) {
      myservo.write(0);
      delay(3000);
      myservo.write(180);
      delay(1000);

      // Send data to Blynk
      Blynk.virtualWrite(V0, fireState);
      delay(2000);
      Blynk.virtualWrite(V1, gasState);
      delay(2000);
      Blynk.virtualWrite(V2, distance);
      delay(2000);
      Blynk.virtualWrite(V3, reading);
    }
    delay(10);
  }
}
