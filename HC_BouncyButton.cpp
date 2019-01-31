/***************************************************************************
  This is a library for debouncing buttons
 ***************************************************************************/

#include "Arduino.h"
#include "HC_BouncyButton.h"

/*
class BouncyButton {
  public:
    BouncyButton(uint8_t pin);
    BouncyButton(uint8_t pin, uint8_t debounceDelayMillis);
    bool getState();
    unsigned long getStateChangeMillis();
    uint8_t getPin();
    void init(bool setInputPullup=true);
    bool update();
	
  private:
    bool _state;
    unsigned long _stateChangeMillis;
    uint8_t _pin;
		
    bool _debounceLastState;
    unsigned long _debounceMillis;
    uint8_t _debounceDelayMillis;
};
*/

/***************************************************************************
 CONSTRUCTOR
 ***************************************************************************/
BouncyButton::BouncyButton(uint8_t pin) {
	_pin = pin;
	_debounceDelayMillis = HC_BOUNCY_BUTTON_DEFAULT_DEBOUNCE_DELAY;
}
BouncyButton::BouncyButton(uint8_t pin, uint8_t debounceDelayMillis) {
	_pin = pin;
	_debounceDelayMillis = debounceDelayMillis;
}

/***************************************************************************
 Property Getters
 ***************************************************************************/
bool BouncyButton::getState() {
	return _state;
}
unsigned long BouncyButton::getStateChangeMillis() {
	return _stateChangeMillis;
}
uint8_t BouncyButton::getPin() {
	return _pin;
}

/***************************************************************************
 Initialize the bounce data, good to call in setup(), right after setting pin modes.
 Expects that the button is not bouncing right now, so don't press buttons during boot.
 ***************************************************************************/
void BouncyButton::init(bool setInputPullup=true) {

  if (setInputPullup) {
    pinMode(_pin, INPUT_PULLUP);
  }
  
	// read the current state of the button, probably HIGH because you use internal pullups and it goes LOW when pressed, right?
	_debounceLastState = digitalRead(_pin);
	_state = _debounceLastState;
}

/***************************************************************************
 Read the current pin state, debounce it, and change the public state if needed.
 Returns true if the public/debounced state has changed, false otherwise.
 ***************************************************************************/
bool BouncyButton::update() {

	bool reading = digitalRead(_pin);
	
	if (reading!=_debounceLastState) {
		// there was a change since last time through the routine, we're bouncing
		_debounceMillis = millis();
		_debounceLastState=reading;
	}
	if ((millis()-_debounceMillis)>_debounceDelayMillis) {
		// it has been long enough with a stable reading, is this reading different than our public state?
		if (reading!=_state) {
			// stable reading with new state value, this is a button press (or release)
			_state=reading;
			// record the time the public state changed.  not used for debouncing, but client progs may be interested in how long its been since a change
			_stateChangeMillis=millis();
			
			return true;
		}
	}
	return false;
}

