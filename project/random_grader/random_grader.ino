// The random grader -
// Shannon Duvall
// It will run once when you turn it on and 
// then to get it to run again you should
// hit the reset button on the Photon.

const int BELL = D1;
const int SERVO = D0;
const int HIGHEST_SPEED = 10;
// This is a number from 0 to 180,
// giving the position of the servo.
int currentPos = 0;
// I only want it to run once, 
// Not forever in the loop.
boolean done = false;
Servo myservo;

void setup() {
    RGB.control(true);
    srand(millis());
    pinMode(BELL, OUTPUT);
    myservo.attach(SERVO);
}

void loop() {
    // I have to turn the bell off in the loop
    // -- not quite sure why.
    noTone(BELL);
    if(!done){
        // Green color on the RGB indicates it's running
        // This helped me in debugging.
        RGB.color(0,255,0);
        grade();
        // Red for when it's done.
        RGB.color(255,0,0);
        done = true;
    }
}

// The random grading algorithm:
// 1.  Sweep back and forth a random number 
// of times, getting slower as it goes.
// 2.  Jerk to random positions a random number
// of times, really fast.
// 3. Play the bell indicating grading is over.
void grade(){
    // Randomly sweep between 2 & 4 times
    const int LOW_SWEEP_BOUND = 2;
    const int HIGH_SWEEP_BOUND= 4;
    int numOfSweeps = (rand() % (HIGH_SWEEP_BOUND-LOW_SWEEP_BOUND+1)) + LOW_SWEEP_BOUND;
    // Randomly jerk between 4 and 8 times
    const int LOW_JERK_BOUND = 4;
    const int HIGH_JERK_BOUND = 8;
    int numOfJerks = (rand() % (HIGH_JERK_BOUND - LOW_JERK_BOUND+1)) + LOW_JERK_BOUND;
    
    int speed = HIGHEST_SPEED;
    // sweep back and forth, getting slower
    for(int i = 1; i<= numOfSweeps; i++){
        goTo(180,speed--);
        goTo(0,speed--);
    }
    
    // jerk randomly
    for(int i = 1; i<= numOfJerks; i++){
        int angle = (rand()%180);
        goTo(angle,HIGHEST_SPEED);
    }
    const int NOTE = 1000;
    const int DELAY = 500;
    tone(BELL,NOTE);
    delay(DELAY);
    noTone(BELL);
    delay(DELAY);
}


// This function moves the servo smoothly to the given 
// position at the given speed, which is in 
// general 0 to HIGH_SPEED
void goTo(int position, int speed){
    int incrementDelay = HIGHEST_SPEED + 5 -speed;
    // Is my angle going up or down?
    // If I could use Java 8 I could refactor this.
    if(currentPos > position){
        for(int angle = currentPos; angle >= position; angle--){
            myservo.write(angle);
            delay(incrementDelay);
        }
    }
    else{
        for(int angle = currentPos; angle < position; angle++){
            myservo.write(angle);
            delay(incrementDelay);
        }
    }
    // Update the current position.
    currentPos = position;
}
