#define BUMP_AMOUNT 1
#define MAX_ANGLE 179
#define MIN_ANGLE 0
#define DELAY_TIME 10

// one Servo object
Servo myServo;

int angle = 0;
int bump = BUMP_AMOUNT;

void setup() {
    // servo control line is attached to D0
    myServo.attach(D0);
}

void loop() {
    // set the servo's position
    myServo.write(angle);
    
    // bump the angle
    angle = angle + bump;
    
    // did we bump too far?
    if (angle > MAX_ANGLE) {
        angle = MAX_ANGLE;
        bump = bump * -1;   // flip the direction
    } else if (angle < MIN_ANGLE) {
        angle = MIN_ANGLE;
        bump = bump * -1;   // flip the direction
    }
    
    // pause some small amount of time
    delay(DELAY_TIME);
}
