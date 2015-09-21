/*
    Counting button presses (pullup switch) using debouncing.
    J. Hollingsworth
    
    Modified from https://www.arduino.cc/en/Tutorial/Debounce
*/

const int switchPin = D3;

// display timing variables
const int waitTime = 2000; // 2s
int elapsedTime = 0;
int lastTime = 0;

// the variable
int count = 0;

// debouncing
int buttonState = HIGH;
int lastButtonState = HIGH;
int lastDebounceTime = 0;
const int debounceDelay = 50;

/* setup the circuit */
void setup() {
    pinMode(switchPin, INPUT_PULLUP);
}

/* main loop */
void loop() {
    //badMethod();
    goodMethod();
    displayInteger("count", count);
}

/* try to count button presses when the switchPint reads LOW */
void badMethod() {
    if (digitalRead(switchPin) == LOW) {  // button is pressed
        count++;
    }
}

/* use debouncing to count button presses */
void goodMethod() {
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
                count++;
            }
        }
    }
    
    // remember the current state
    lastButtonState = reading;
}

/* display the given integer every waitTime ms */
void displayInteger(String name, int value) {
    int now = millis();
    elapsedTime += (now - lastTime);
    if (elapsedTime > waitTime) {
        Spark.publish(name, String(value));
        elapsedTime = 0;
    }
    
    lastTime = now;
}
