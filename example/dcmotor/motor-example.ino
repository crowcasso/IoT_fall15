const int motorPin = D0;

void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(D7, OUTPUT);    // debugging code
}

void loop() {
    // spin the motor for 5s
    digitalWrite(motorPin, HIGH);
    digitalWrite(D7, HIGH);     // debugging code
    delay(5000);
    
    // stop spinning the motor for 5s
    digitalWrite(motorPin, LOW);
    digitalWrite(D7, LOW);      // debugging code
    delay(5000);
}
