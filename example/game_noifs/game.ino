#include "iot.h"

/*
    Game of Button -- Sample Multistate Game Loop
    J. Hollingsworth
*/

const int switchPin = D3;
int count = 0;

typedef enum {START, PLAY, FINISH} game_state_t;
game_state_t gameState;

void (*stateFunction[])() = {
  startState,
  playState,
  finishState
};


IoT iot;

/* setup the circuit */
void setup() {
    pinMode(switchPin, INPUT_PULLUP);
    gameState = START;
    splashMessage();
}

void splashMessage() {
    Particle.publish("Game of Button", "Welcome to the game!");
    delay(3000);
    Particle.publish("Game of Button", "Press the button to start.");
}

void startState() {
    count = 0;
    iot.countButtonPress(switchPin, &count);
    if (count >= 1) {
        Particle.publish("Game of Button", "Press the button many times.");
        gameState = PLAY;
    }
}

void playState() {
    iot.countButtonPress(switchPin, &count);
    //iot.displayInteger("count", count, 2000);
    if (count > 10) {
        gameState = FINISH;
    }
}

void finishState() {
        Particle.publish("Game of Button", "Congrats you pressed the button " + String(count) + " times");
        delay(3000);
        splashMessage();
        gameState = START;
}

/* main loop */
void loop() {
   stateFunction[gameState]();
}
