#include <Servo.h>

Servo myServo;
const int servoPin = 9;
const int trigPin  = 7;
const int echoPin  = 6;

const int stepDeg = 4;
const int servoDelayMs = 150;
const unsigned int MAX_RANGE_CM = 400;

long readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1;
  long dist = duration / 29 / 2;
  if (dist > MAX_RANGE_CM) return -1;
  return dist;
}

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("{\"meta\":\"radar_v1\",\"unit\":\"cm\"}");
}

void loop() {
  for (int angle = 0; angle <= 180; angle += stepDeg) {
    myServo.write(angle);
    delay(servoDelayMs);
    long dist = readDistanceCM();
    printJSON(angle, dist);
  }
  for (int angle = 180; angle >= 0; angle -= stepDeg) {
    myServo.write(angle);
    delay(servoDelayMs);
    long dist = readDistanceCM();
    printJSON(angle, dist);
  }
}

void printJSON(int angle, long dist) {
  if (dist < 0)
    Serial.printf("{\"angle\":%d,\"dist\":null}\n", angle);
  else
    Serial.printf("{\"angle\":%d,\"dist\":%ld}\n", angle, dist);
}
