/* Morse Code Flasher -- J. Hollingsworth */

String letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

String message = "hello world";

const int ledPin = D7;
const int switchPin = D3;

#define DOT_DELAY 200
#define DASH_DELAY 400
#define BETWEEN_DOT_DASH_DELAY 200
#define AFTER_CHARACTER_DELAY 200
#define AFTER_WORD_DELAY 1400

/* display a dot*/
void dot() {
    digitalWrite(ledPin, HIGH);
    delay(DOT_DELAY);
    digitalWrite(ledPin, LOW);
}

/* display a dash */
void dash() {
    digitalWrite(ledPin, HIGH);
    delay(DASH_DELAY);
    digitalWrite(ledPin, LOW);
}

/* display a charcter */
void displayLetter(char ch) {
    Serial.print(String(ch) + ": ");
    if (ch >= 'a' && ch <= 'z') {
        String code = letters[ch - 'a'];
        for (int i = 0; i < code.length(); i++) {
            if (code.charAt(i) == '.') {
                Serial.print(".");
                dot();
            } else {
                Serial.print("-");
                dash();
            }
        
            delay(BETWEEN_DOT_DASH_DELAY);
        }
    }
    Serial.println();
}


void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT_PULLUP);
}

void loop() {

    if (digitalRead(switchPin) == LOW) {
        message.toLowerCase();
        Serial.println("message: " + message);
        for (int i = 0; i < message.length(); i++) {
            char ch = message.charAt(i);
            displayLetter(ch);
            delay(AFTER_CHARACTER_DELAY);
        }
        
        delay(AFTER_WORD_DELAY);
    }
}
