# hc-bouncy-button
Simple Arduino library for software debouncing digital button inputs.

HC Bouncy Button does not block while waiting for bouncing buttons to stabilize.

Method call will retun true whenever there has been a change in the debounced state.

## Usage

1. Clone or unzip to your Arduino/libraries directory.

2. Restart Arduino IDE.

3. View example in Arduino IDE using File -> Examples -> HedgeCourt Bouncy Button

## Details

1. In the global section of your sketch, instantiate a BouncyButton object, specifing the digital input pin to monitor.

2. In setup(), set the pin to INPUT or INPUT_PULLUP (recommended).

3. In setup(), call the button's init() method.

4. In loop(), frequently call the update() method.  It will only return true when a state change occurs and remains stable longer than the bounce threshold.  Recommend invoking this method every iteration of loop().

5. If there is an update to process, getState() will return whether the debounced state of the button is HIGH or LOW at this point in time.
