/* Get a Photon's MAC address -- J. Hollingsworth 

   modified from: https://community.particle.io/t/how-to-get-mac-address/1411/4 
   www.plastibots.com
*/

byte mac[6];
int LED = D7;

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    WiFi.macAddress(mac);
}

void loop () {
    Serial.print("MAC: ");
    Serial.print(mac[0],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.println(mac[5],HEX);

    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(1000);
}
