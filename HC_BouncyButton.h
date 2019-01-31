/***************************************************************************
  This is a library for debouncing buttons
 ***************************************************************************/
#ifndef __HC_BOUNCY_BUTTON__
#define __HC_BOUNCY_BUTTON__

#include "Arduino.h"

#define HC_BOUNCY_BUTTON_DEFAULT_DEBOUNCE_DELAY 10
  
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

#endif

