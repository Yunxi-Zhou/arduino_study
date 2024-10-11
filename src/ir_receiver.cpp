#include <Arduino.h>
#include "ir_receiver.h"
#include "IRremote.h"

// declaration
const int receiverPin = 11;


// variable uses to store the last decodeRawData
uint32_t last_decodedRawData = 0;

// Function
void translateIR() {
    // check if it is a repeat IR code
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
        // set the current decodeRawData to the last decodeRawData
        IrReceiver.decodedIRData.decodedRawData = last_decodedRawData;
        Serial.println("REPEAT! ");
    } else {
        // output the IR code on the serial monitor
        Serial.print("IR code: 0x");
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    }
    // map the IR code to the remote key
    switch (IrReceiver.decodedIRData.decodedRawData) {
        case 0xBA45FF00: Serial.println("POWER"); break;
        case 0xB847FF00: Serial.println("FUNC/STOP"); break;
        case 0xB946FF00: Serial.println("VOL+"); break;
        case 0xBB44FF00: Serial.println("FAST BACK");    break;
        case 0xBF40FF00: Serial.println("PAUSE");    break;
        case 0xBC43FF00: Serial.println("FAST FORWARD");   break;
        case 0xF807FF00: Serial.println("DOWN");    break;
        case 0xEA15FF00: Serial.println("VOL-");    break;
        case 0xF609FF00: Serial.println("UP");    break;
        case 0xE619FF00: Serial.println("EQ");    break;
        case 0xF20DFF00: Serial.println("ST/REPT");    break;
        case 0xE916FF00: Serial.println("0");    break;
        case 0xF30CFF00: Serial.println("1");    break;
        case 0xE718FF00: Serial.println("2");    break;
        case 0xA15EFF00: Serial.println("3");    break;
        case 0xF708FF00: Serial.println("4");    break;
        case 0xE31CFF00: Serial.println("5");    break;
        case 0xA55AFF00: Serial.println("6");    break;
        case 0xBD42FF00: Serial.println("7");    break;
        case 0xAD52FF00: Serial.println("8");    break;
        case 0xB54AFF00: Serial.println("9");    break;
        default:
            Serial.println("Other button");
    }
    //store the last decodeRawData
    last_decodedRawData = IrReceiver.decodedIRData.decodedRawData;
    delay(500);
}

void set_ir() {
    Serial.begin(9600);
    Serial.println("IR Receiver Button Decode");
    IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);  // start the receiver
}

void loop_ir() {
    // have we received an IR signal?
    if (IrReceiver.decode()) {
        translateIR();
        IrReceiver.resume(); // receive the next value
    }
}