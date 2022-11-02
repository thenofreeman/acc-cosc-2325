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

const int buttonPin       = 2,
          ledPin          = 13,
          numLightStates  = 4;

int buttonState      = 0,
    prevButtonState  = 0,
    lightState       = 0;

const int RED_PIN   = 9,
          GREEN_PIN = 10,
          BLUE_PIN  = 11;

unsigned long prevTime = 0;
const unsigned long interval = 250UL;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// replaces 3 lines of digital writes with one
// only works when global pin values are present
void digitalWriteRGB (const int& rValue, 
                      const int& gValue, 
                      const int& bValue)
{
  digitalWrite(RED_PIN, rValue);
  digitalWrite(GREEN_PIN, gValue);
  digitalWrite(BLUE_PIN, bValue);
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
      lightState = ++lightState % numLightStates;

      // get the new time after toggle
      prevTime = millis();
    }
    // write new light state to pin
    switch (lightState)
    {
      case 0: // red
        digitalWriteRGB(HIGH, LOW, LOW);
        break;
      case 1: // green
        digitalWriteRGB(LOW, HIGH, LOW);
        break;
      case 2: // blue
        digitalWriteRGB(LOW, LOW, HIGH);
        break;
      case 3: // off
        digitalWriteRGB(LOW, LOW, LOW);
        break;
      default:
        digitalWriteRGB(LOW, LOW, LOW);
        break;
    }
  }
  // set the previous state variable to the previous button state
  prevButtonState = buttonState;
}
