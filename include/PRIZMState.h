#pragma once

#ifndef PRIZMSTATE_H_
#define PRIZMSTATE_H_

#include <string.h>

class PRIZMState {

private:
    int leftMotorState;
    int rightMotorState;
    bool greenLedState;
    bool redLedState;

public:
    PRIZMState() {
        leftMotorState = 0;
        rightMotorState = 0;
        greenLedState = false;
        redLedState = false;
    }

    PRIZMState(String s) {
        leftMotorState = 0;
        rightMotorState = 0;
        greenLedState = false;
        redLedState = false;
        fromString(s);
    }

    PRIZMState(int leftMotor, int rightMotor, bool greenLed, bool redLed) {
        leftMotorState = leftMotor;
        rightMotorState = rightMotor;
        greenLedState = greenLed;
        redLedState = redLed;
    }

    String toString() {
        String out = "";
        out += "left:";
        out += String(leftMotorState);
        out += ",right:";
        out += String(rightMotorState);
        out += ",green:";
        out += String(greenLedState);
        out += ",red:";
        out += String(redLedState);
        out += ";";
        return out;
    }

    void fromString(String s) {
        String varBuffer = "";
        String valBuffer = "";
        bool valFlag = false;
        for(char c : s) {
            if(!valFlag) {
                if(c == ':') {
                    valFlag = !valFlag;
                    continue;
                }
                varBuffer += c;
            }
            else {
                if(c == ',' || c == ';') {
                    valFlag = !valFlag;

                    if(varBuffer == "left") {
                        leftMotorState = valBuffer.toInt();
                    }
                    else if(varBuffer == "right") {
                        rightMotorState = valBuffer.toInt();
                    }
                    else if(varBuffer == "green") {
                        greenLedState = valBuffer == "1";
                    }
                    else if(varBuffer == "red") {
                        redLedState = valBuffer == "1";
                    }

                    varBuffer = "";
                    valBuffer = "";

                    continue;
                }
                valBuffer += c;
            }
        }
    }

    int getLeftMotor() {
        return leftMotorState;
    }

    int getRightMotor() {
        return rightMotorState;
    }

    bool getGreenLed() {
        return greenLedState;
    }

    bool getRedLed() {
        return redLedState;
    }
};




#endif
