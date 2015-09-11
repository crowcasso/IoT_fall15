/* 
    Motion Detection using the Infrared PIR sensor
    J. Hollingsworth 
    
    https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/using-a-pir
    http://community.particle.io/t/notification-for-infrared-pir-motion-sensor-module/15363/2
*/
   
int pirPin = D0;
int lastMotion = LOW;

void setup() {
    Serial.begin(9600);
    pinMode(pirPin, INPUT);
    
    // give a small amount of time to settle
    Serial.println("Warming Up ... ");
    delay(1000);
    Serial.println("Ready!");
}

void loop() {
    int reading = digitalRead(pirPin);
    
    if (reading != lastMotion) {
        if (reading == HIGH) {
            // toggled by new motion
            Serial.println("Motion detected.");
        } else {
            // no new motion
            Serial.println("No motion detected.");
        }
    }
    
    lastMotion = reading;
    delay(50);
}
