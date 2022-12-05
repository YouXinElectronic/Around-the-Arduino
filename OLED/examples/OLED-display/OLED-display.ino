/*
接线:
Arduino UNO
SDA -- A4
SCL -- A5
*/

#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup(void) {
  Serial.begin(9600);
  u8g2.begin();
  u8g2.enableUTF8Print();    // enable UTF8 support for the Arduino print() function
  u8g2.setFont(u8g2_font_ncenB18_tr);  
}

void loop(void) {
  u8g2.clear();
  u8g2.setCursor(23, 20);
  u8g2.print("Clover");
  u8g2.setCursor(18, 50);
  u8g2.print("Publish");
  u8g2.sendBuffer();
  delay(2000);
  u8g2.clear();
  u8g2.setCursor(15, 23);
  u8g2.print("HELLO");
  u8g2.setCursor(10, 50);
  u8g2.print("WORLD");
  u8g2.sendBuffer();
  delay(2000);
  

}
