/*
  Control the LED light on and off through the NEC coded remote controller. Press the key 1 to light up and the key 0 to light up
  Author: YXDZ
  Creation Date: 2022/8/28
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino

  The program calls the author's Arduino-IRremote library. The official provides a lot of examples. The following code only calls a small part of the function. The library function is very powerful. You can visit the author's github for more information.
  Library author github: https://github.com/Arduino-IRremote
*/
#include <IRremote.hpp>

#define DECODE_NEC
#define IR_RECEIVE_PIN    2

#define LED_PIN 3
#define LED_Bright digitalWrite(LED_PIN,LOW)
#define LED_Extinguish digitalWrite(LED_PIN,HIGH)

void setup() {
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    printActiveIRProtocols(&Serial);
    Serial.begin(115200);

    pinMode(LED_PIN,OUTPUT);
    LED_Extinguish;
}

void loop() {

  if (IrReceiver.decode()) {
    Serial.println();
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
    
    if (IrReceiver.decodedIRData.address == 0) {
      if (IrReceiver.decodedIRData.command == 0x45) {
      LED_Bright;
      }
      else if (IrReceiver.decodedIRData.command == 0x19) {
      LED_Extinguish;
      }
    }
  }
}
