#include "USBKeyboard.h"

const int SWITCH_PIN = 7;
const int MODE_PIN = A0;

const bool DEBUG = false;


void setup() {
    Keyboard.init();

    // Set pin to be input.
    pinMode(SWITCH_PIN, INPUT);

    // Set internal pull up resistor. 
    digitalWrite(SWITCH_PIN, 1);

    pinMode(MODE_PIN, INPUT);
    digitalWrite(MODE_PIN, 1);

}

bool lastPressed = false;

void loop() {
    uint8_t value = digitalRead(SWITCH_PIN);

    bool pressed = (value == 0);

    if (pressed && !lastPressed) {
        bool mode = digitalRead(MODE_PIN);

        Keyboard.sendKeyStroke(mode ? KEY_V : KEY_A, MOD_GUI_LEFT | MOD_SHIFT_LEFT);

        if (DEBUG) {
            Serial.print("Mode:");
            Serial.println(mode);
            Serial.println("Pressed");
        }

        delay(75); // de-bounce press
    } else if (!pressed && lastPressed) {
        if (DEBUG) {
            Serial.println("Released");
        }
        delay(75); // de-bounce release.
    }
    lastPressed = pressed;
}