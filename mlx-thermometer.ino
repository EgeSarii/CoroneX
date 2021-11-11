#include <Wire.h>
#include <Adafruit_MLX90614.h>

/*
  Related components: HC-SR04 distance sensor
                      MLX90614 Infra-red thermometer
*/

//Distance sensor pins
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04


//defines variables
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

//Very straight-forward process:
//Serial-port 9600 communication with Raspberry Pi about distance cross-checked human temperature feedback.

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT for HC-SR04
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT for HC-SR04
  mlx.begin();  //starts infrared thermometer
}

void loop() {
  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //This distance value represents distance between object(person) and the distance sensor in terms of centimeter. 
  //We only send the information of human temperature if the person is in range, otherwise 0

  if(distance <=6){ 
    Serial.println(mlx.readObjectTempC()); 
  }
  else{
    Serial.println(0);
  }
  delay(500);
}
