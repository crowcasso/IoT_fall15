// need to include the iot header file
#include "iot.h"

// create an IoT object
IoT iot;

// circuit setup
int switchPin = D3;

// counting buton presses
int count = 0;

void setup() {
    pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
    // count button presses
    iot.countButtonPress(switchPin, &count);
    /* need to pass which pin to watch and 
       the address of the variable to increment */
    
    // every 2s display the count
    iot.displayInteger("count", count, 2000);
    /* need to pass the name, value, and how 
       often to print 
       
       this function is non-blocking -- it will 
       only print if it has not printed in the
       given number of milliseconds */
}
