# Object Detection Indicators

This projects detects and indicates the proximity of an object using multiple LEDs, a servo, and an ultrasonic sensor

## Materials

- Breadboard
- 8 LEDS
- 8 220ohm resistors
- Arduino Uno
- Servo motor
- Ultrasonic sensror
- Around 20 jumper wires

## Design

![design image](https://github.com/angelina-tsuboi/Object_Detector_Arduino/blob/main/images/design.png)

## How It Works

An ultrasonic sensor utliizes sonar (high-frequency sound) in order to get the distance between itself and the object. Firstly, the transmitter (trigPin) of the sensor releases a signal. When the signal is reflected off of a object, the transmitter (echoPin) recieves it back. By using the time it takes to recieve the signal back from the reflected object, we can calculate the distance between the sensor and the object. Once we get the distance, we can use this information to light up our LEDs and alter the angle of the servo motor.

## Completed Project

![project photo](https://github.com/angelina-tsuboi/Object_Detector_Arduino/blob/main/images/photo.jpg)