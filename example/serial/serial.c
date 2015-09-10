int i;

void setup() {
    Serial.begin(9600);
    
    i = 0;
}

void loop() {

    delay(5000);
    Serial.println(i);
    i++;

}
