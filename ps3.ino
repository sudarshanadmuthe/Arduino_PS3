/*

	PS3 DEMO "MadTux"

*/

#include <PS3USB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
/* You can create the instance of the class in two ways */
PS3USB PS3(&Usb); // This will just create the instance
//PS3USB PS3(&Usb,0x00,0x15,0x83,0x3D,0x0A,0x57);
bool printAngle;
uint8_t state = 0;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\n OSC did not start "));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started :: "));

   pinMode(46, OUTPUT);
pinMode(48, OUTPUT);
pinMode(50, OUTPUT);
pinMode(52, OUTPUT);
}
void loop() {
  Usb.Task();


      if(PS3.getAnalogHat(LeftHatY)==0)
      {
      		Serial.print(F("Left_up"));
      		digitalWrite(46,HIGH);
      }
      else
      {
        
	digitalWrite(46,LOW);
	digitalWrite(48,LOW);
	digitalWrite(50,LOW);
	digitalWrite(52,LOW);
      }
       if(PS3.getAnalogHat(LeftHatY)==255)
      {
      		Serial.print(F("left_down"));
      		digitalWrite(48,HIGH);
      
      }
      


      
      if(PS3.getAnalogHat(RightHatY)==0)
      {
      		Serial.print(F("Right_up"));
       		digitalWrite(50,HIGH);
      }

       if(PS3.getAnalogHat(RightHatY)==255)
      {
      		Serial.print(F("Right_down"));
       		digitalWrite(52,HIGH);
      }



}
