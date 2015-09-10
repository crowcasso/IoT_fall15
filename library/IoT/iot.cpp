#include "iot.h"

/* 
   A set of useful functions. 
   J. Hollingsworth

   v0.1 -- September 10, 2015
*/

IoT::IoT()
{
    // displayInteger
    displayElapsedTime = 0;
    displayLastTime = 0;
    
    // checkButtonPress
    buttonState = HIGH;
    lastButtonState = HIGH;
    lastDebounceTime = 0;
}

/* display the given integer every waitTime ms */
void IoT::displayInteger(String name, int value, int displayWaitTime) {
    int now = millis();
    displayElapsedTime += (now - displayLastTime);
    if (displayElapsedTime > displayWaitTime) {
        Particle.publish(name, String(value));
        displayElapsedTime = 0;
    }
    
    displayLastTime = now;
}

/* use debouncing to count button presses */
void IoT::countButtonPress(int switchPin, int *count) {
    // is the button HIGH (up) or LOW (down)
    int reading = digitalRead(switchPin);
    
    // is this a chance from last time we checked?
    if (reading != lastButtonState) {
        lastDebounceTime = 0;
    }
    
    // wait to check again debounceDelay ms later
    int now = millis();
    if ((now - lastDebounceTime) > debounceDelay) {
        
        /* is it new? */
        if (reading != buttonState) {
            buttonState = reading;
            
            // only count when its LOW (down)
            if (buttonState == LOW) {
                (*count)++;
            }
        }
    }
    
    // remember the current state
    lastButtonState = reading;
}
