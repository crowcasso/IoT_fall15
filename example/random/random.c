
#define MAX 32

void setup() {
    // seed the random number generator
    srand(millis());
}

void loop() {
    // get and show a random integer
    int r = rand() % MAX;
    Serial.println(r);
    
    delay(1000);
}
