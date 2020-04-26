/**
 * Template for Arduino .ino file generation for swarm nodes.
 * 
 * All variables prefixed with a dollar sign ('$') should 
 * be provided by the code generator.
 * 
 * Written by Lizzy Presland
 * April 2020
 */

#include <SoftwareSerial.h>     // board-to-board communication

// Declare pin numbers for serial communication between boards,
// and initialize the serial line object.
// In this example, we use pins 0 and 1 for the Elegoo Uno R3 per datasheet
#define RX 0
#define TX 1
SoftwareSerial comms(RX, TX);

// Declare variables for manual cycling of board's label.
// NOTE: manual cycling behavior is for demonstration purposes only.
const int BUTTON_PIN = 7;

const uint8_t MAX_LABELS = 3;   // TODO: define in code generator

const uint8_t labels[MAX_LABELS] = {
    // TODO: add sorted label list from rule generation here
    0,
    1,
    2,
};
uint8_t CURR_LABEL_INDEX = 0;

// Persist the initial singleton label here; update as state changes
uint8_t CURR_LABEL = 0;     // Should be initialized by code generator

// Declare a map of currLabel: nextLabel schemas.
struct label_changes {
    const int older;
    const int newer;
};

struct rule {
    label_changes pairs[2];
};

const int RULE_COUNT = 2;       // TODO: define in code generator

rule ruleset[RULE_COUNT] = {
    // TODO: Add rules here in code generator
    { pairs: { { older: 0, newer: 1 }, { older: 0, newer: 1 }, }, },
    { pairs: { { older: 1, newer: 2 }, { older: 1, newer: 2 }, }, },
};

// Declare a digital pin to be used to detect a mating event.
uint8_t EVENT_PIN = 4;

// Declare RGB LED pins for light status
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

bool ledOn = false;

bool READY = true;

void setup() {
    // setup code for node

    // Set up serial connections
    Serial.begin(9600);
    comms.begin(4800);

    // Set up RGB pins
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    // Set up button pin
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    // main code for node

    // Simulate immediate disconnect of connection events which are 
    // not part of the rule set.
    if (!READY) {
        // Disconnect event is incomplete; cycle again.
        if (digitalRead(EVENT_PIN) == HIGH) return;
        // Otherwise, set READY to true
        READY = true;
    }
    
    // Check to see if button for board was pressed; 
    // if so; label needs to be cycled.
    if (digitalRead(BUTTON_PIN) == HIGH) {
        cycleLabel();
    }

    // Check activity state of connection pin
    if (digitalRead(EVENT_PIN) == HIGH) {
        // Set LED green for now...
        color(0, 255, 0);
        // TODO: if connection pin lights up, proceed with board-to-board serial 
        // read/write
    } else {
        // set LED color to blue (inactive)
        color(0, 0, 255);
    }
}

void performStateChange() {
    // Send state label to other board 
    comms.print(char(CURR_LABEL));
    Serial.println("Current label is: " + String(CURR_LABEL));
    // Read other cube face value, activate LEDs
    if (comms.available()) {
        int incomingValue = comms.read();
        Serial.println("Read neighbor label is: " + String(incomingValue));
        // TODO: Check map for values; perform label transition if 
        // two nodes are valid, and require connection break (reset) 
        // if nodes do not belong in valid rule.
        /*
        int rule_index = findLabel(CURR_LABEL, incomingValue);
        if (rule_index != -1) {
            CURR_LABEL = ruleset[rule_index]
        } else {
            disconnect();
        }
        */
    }
}

void disconnect() {
    Serial.print("Simulating node disconnect -- ");
    Serial.println("remove input pin connection to pin " + String(EVENT_PIN));
    READY = false;
}

void cycleLabel() {
    // Set LED, print label cycling initiated
    color(255, 0, 255);
    Serial.println("Cycling label for this node.");
    Serial.print("Old label: " + String(CURR_LABEL));
    // Increment label index and update internal state of node
    CURR_LABEL_INDEX = (CURR_LABEL_INDEX + 1) % MAX_LABELS;
    CURR_LABEL = labels[CURR_LABEL_INDEX];
    Serial.println(" New label: " + String(CURR_LABEL));
    // Give user a chance to release button before next loop()
    delay(200);
}

void color(unsigned char r, unsigned char g, unsigned char b) {    
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}
