#include <HC_BouncyButton.h>

// Connect a switch or button between pin 5 and GND (internal pullup will be enabled so open switch = HIGH, closed switch=LOW)
#define BUTTON_PIN 5

// pin 13 is connected to onboard LED (HIGH=illuminated, LOW=off)
#define LED_PIN 13


// instantiate a BouncyButton object, access debounced button data through this object rather than reading the pin
// single parameter constructor uses a default debounce duration, see the .h file for the value.  optionally specify a 2nd
// parameter with the number of millis you want to bounce for.
BouncyButton btn=BouncyButton(BUTTON_PIN);


void setup() {
  // put your setup code here, to run once:

  // configure the button pin for input and enable the pullup resistor
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // initialize the BouncyButton (do this after setting the pinMode, not before)
  btn.init();

  // configure the LED for output so we can light it up and turn it off  
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // frequently call update() on your buttons, then read the state from the BouncyButton object.
  // it will only return true when the button's "public" value (that is, the value after bouncing is complete) changes.
  // you can choose to act on that change immediately in the loop(), or you can have other parts of your sketch examine
  // the BouncyButton object and react to the button state.
  if (btn.update()) {
    // there was a change on the button (debounced, so this is a real button change, not a transient bounce)
    
    // illuminate LED when pressed, so negate the button state
    digitalWrite(LED_PIN, !btn.getState());
  }
  
}
