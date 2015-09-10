int i;
String myString;

void setup() {
    i = 0;
}

void loop() {
    myString += i;
    Particle.publish("count", myString);
    delay(10000);
    i++;
}
