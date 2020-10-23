#include <Servo.h>

const int trigPin = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of Ultrasonic Sensor
Servo pointer;


void setup() {
  // put your setup code here, to run once:
  pointer.attach(12);
  
  pinMode(trigPin, OUTPUT); //ultrasonic sensor setup
  pinMode(echoPin, INPUT);

  //setup for led
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration,cm;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin , HIGH);
  cm = microsecondsToCentimeters(duration);
  
  int amount = lightUpAmount(cm);
  lightUp(amount);
  moveServo(cm);
  delay(250);
}

long microsecondsToCentimeters(long microseconds) {
   return (microseconds/2) / 29.1;
}

int lightUpAmount(int cm){ //determines how many LED to light up
  if(cm < 5) return 8;
  if(cm >= 5 && cm < 7) return 7;
  if(cm >= 7 && cm < 10) return 6;
  if(cm >= 10 && cm < 15) return 5;
  if(cm >= 15 && cm < 17) return 4;
  if(cm >= 17 && cm < 20) return 3;
  if(cm >= 20 && cm < 25) return 2;
  if(cm >= 25) return 1;
}

void lightUp(int amount){ //light up LEDs
  Serial.println("lighting");
  Serial.println(amount);
  for(int i = 0; i < 8; i++){ //loop through all LEDs
     if(i < amount){
      digitalWrite(i + 2, HIGH);
     }else{
      digitalWrite(i + 2, LOW);
     }
  }
}

void moveServo(int cm){
  int angle = map(cm, 2, 15, 15, 100);
  pointer.write(angle);
}
