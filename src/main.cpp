#include <Arduino.h>

// Tetrix Prizm
#include <PRIZM.h>
PRIZM prizm;

// Prizm control state
#include "PRIZMState.h"
PRIZMState state;

// Direction
#define FWD 1
#define BKWD 0

// how many millis to wait between messages before stopping
#define PRIZM_TIMEOUT_MILLIS 100
int timeout = 0;

// reads a PRIZM state from the serial buffer
bool readStateSerial() {
    if(Serial.available() > 0) {
        String input = Serial.readStringUntil(';');
        input += ';';
        PRIZMState readState(input);
        state = readState;
        return true;
    }
    else {
        return false;
    }
}

// translates a PRIZM state into PRIZM commands
void handlePRIZMState(PRIZMState state) {
    prizm.setMotorPowers(state.getLeftMotor(), state.getRightMotor());
    prizm.setRedLED(state.getRedLed());
    prizm.setGreenLED(state.getGreenLed());
}

void setup()
{
    // start serial
    Serial.begin(115200);
    while(!Serial);
    Serial.setTimeout(10);

    // start prizm
    prizm.PrizmBegin();
    prizm.setRedLED(LOW);
    prizm.setGreenLED(LOW);
    prizm.setMotorInvert(2, 1); // Invert right motor

    
}


void loop()
{
    // read from serial, reset timeout on success
    if(readStateSerial()) {
        timeout = PRIZM_TIMEOUT_MILLIS;
    }

    // when timeout is reached, stop the bot
    if(timeout == 0) {
        state = PRIZMState(0,0,false,false);
    }
    if(timeout != 0) {timeout--;}

    // send the latest command to the bot
    handlePRIZMState(state);
    delay(1);
}