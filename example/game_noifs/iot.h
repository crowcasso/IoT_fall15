#include "application.h"

class IoT
{
    public:
        IoT();
        void displayInteger(String name, int value, int displayWaitTime);
        void countButtonPress(int, int *);
    
    private:
        // displayInteger
        int displayElapsedTime;
        int displayLastTime;
        
        // checkButtonPress
        int buttonState;
        int lastButtonState;
        int lastDebounceTime;
        const int debounceDelay = 50;
};
