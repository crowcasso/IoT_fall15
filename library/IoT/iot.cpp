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
    buttonState = HIGH;  // assumption
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
int IoT::countButtonPress(int switchPin, int *count) {
    
    int isPressed = 0;
    
    // is the button HIGH (up) or LOW (down)
    int reading = digitalRead(switchPin);
    
    // is this a chance from last time we checked?
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
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
                isPressed = 1;
            }
        }
    }
    
    // remember the current state
    lastButtonState = reading;
    
    return isPressed;
}
