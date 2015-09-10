#include "ids.h"

#define SHANNON 0
#define INSULT_SHANNON "Insult Shannon"
#define INSULT_JOEL "Insult Joel"

String insults[] = {
    "You are like C. You have no class.",
    "Your commit is writing checks your merge can’t cash.",
    "You are like bad parity - a bit off.",
    "There’s no I in TEAM but there’s no BUGS without U.",
    "You are one bit short of a boolean.",
    "Just pipe it to /dev/null.",
    "Your data structures are so bad they are \"last in never out\".",
    "Shut up or I will bring you a world of JOptionPane.",
    "You are as useless as a JPEG to Helen Keller.",
    "Can you help me with my taxes?  You are obviously an accountant working on a second career.",
    "You code like a mechanical engineer.",
    "You need to stop coding and do something more your speed.  Like tech support.",
    "I don’t need help with my code.  I’ll call you when I need bubble sort.",
    "Your momma inspired garbage collection.  One look and I wanted her out of my memory.",
    "Theory is where nothing works, and everybody understands why. Practice is where everything works, and nobody understands why. You combine theory and practice: Nothing works, and nobody understands why.",
    "On our next project, you can be the \"idea guy\"."
};

void randomInsult() {
    delay(5000);
    int r = rand() % 16;
    if (SHANNON) {
        Spark.publish(INSULT_JOEL, insults[r]);
    } else {
        Spark.publish(INSULT_SHANNON, insults[r]);
    }
}

void insultHandler(const char *event, const char *data)
{
    delay(2000);
    
    String message = String(data);
    if (SHANNON) {
        Spark.publish("Joel says:", message);
    } else {
        Spark.publish("Shannon says:", message);
    }
    
    Particle.publish("response", "Well ...");
    randomInsult();
}

void setup() {
    if (SHANNON) {
        Spark.subscribe(INSULT_SHANNON, insultHandler, JOEL_ID);
        randomInsult();
    } else {
        Spark.subscribe(INSULT_JOEL, insultHandler, SHANNON_ID);
    }
}

void loop() {
    
}
