#include "iot.h"

// display timing variables
int displayElapsedTime = 0;
int displayLastTime = 0;

/* display the given integer every waitTime ms */
void displayInteger(String name, int value, int displayWaitTime) {
    int now = millis();
    displayElapsedTime += (now - displayLastTime);
    if (displayElapsedTime > displayWaitTime) {
        Particle.publish(name, String(value));
        displayElapsedTime = 0;
    }
    
    displayLastTime = now;
}

// debouncing
int buttonState = HIGH;
int lastButtonState = HIGH;
int lastDebounceTime = 0;
const int debounceDelay = 50;

/* use debouncing to count button presses */
void countButtonPress(int switchPin, int *count) {
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
