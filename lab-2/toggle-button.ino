/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

const int buttonPin = 2,
          ledPin    = 13;

int buttonState     = 0,
    prevButtonState = 0,
    lightState      = 0;

unsigned long prevTime = 0,
              interval = 250UL;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the new state of the button
  buttonState = digitalRead(buttonPin);

  // if the button wasn't already pressed,
  // but it is now:
  if (!prevButtonState && buttonState)
  {
    // if waited long enough for 'debouncing'
    // ie. the difference in the last time the state was changed
    //     to the current time is greater than the defined duration
    if((millis() - prevTime) > interval)
    {
      // toggle the light
      lightState = !lightState;

      // get the new time after toggle
      prevTime = millis();
    }
    // write new light state to pin
    digitalWrite(ledPin, lightState);
  }
  // set the previous state variable to the previous button state
  prevButtonState = buttonState;
}
