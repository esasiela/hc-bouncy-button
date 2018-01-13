/***************************************************************************
  This is a library for debouncing buttons
 ***************************************************************************/
#ifndef __HC_BOUNCY_BUTTON__
#define __HC_BOUNCY_BUTTON__

#include "Arduino.h"

#define HC_BOUNCY_BUTTON_DEFAULT_DEBOUNCE_DELAY 10
  
class BouncyButton {
  public:
    BouncyButton(int pin);
	BouncyButton(int pin, long debounceDelayMillis);
    bool getState();
	long getStateChangeMillis();
	int getPin();
	void init();
	bool update();
	
  private:
    bool _state;
	long _stateChangeMillis;
	int _pin;
		
	bool _debounceLastState;
	long _debounceMillis;
	long _debounceDelayMillis;
};

#endif

