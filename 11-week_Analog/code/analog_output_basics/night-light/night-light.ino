//Night Light
//Interaction, 2019

/*Based on code By John Keefe, January 2016
 http://keefe.cc/night-light

 Based on example code created by David Cuartielles
 modified 30 Aug 2011 by Tom Igoe
 http://www.arduino.cc/en/Tutorial/AnalogInput

 This code is in the public domain.
 */

int analog0; // A variable to hold analog input. Analog input will always be a range of numbers between 0~1023
int ledPin = 13; //select pin for LED
//first read the Serial.println to find your dark point
int darkPoint = 600;// if the sensor value is less than this, the room is "dark"

void setup(){
  // no pinmode needed for analog
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Start communication for Serial Monitor
}

void loop(){
  analog0 = analogRead(0); // Read input from the specified analog pin.

  // if the sensorValue is less than the darkPoint
  // power the LED:
  if (analog0 < darkPoint) {
    digitalWrite(ledPin, HIGH);
  }

  // if the sensorValue is greater than or equal to the
  // darkPoint, don't power the LED:
  if (analog0 >= darkPoint) {
    digitalWrite(ledPin, LOW);
  }

  Serial.println(analog0); // Send number to the Serial Monitor
  delay(100); // Always use a small delay after printing messages

}
