#include <Arduino.h>
#include <Wire.h>
#include "LibChuck.h"


void Nunchuk::init() // initialisation sequence
{
	Wire.begin();
	Wire.beginTransmission(0x52);
	Wire.write(0x40);
	Wire.write(0x00);
	Wire.endTransmission();
}
void Nunchuk::handshake() // as its name suggests
{
	Wire.beginTransmission(0x52);    
	Wire.write(0x00); 
	Wire.endTransmission();
}
void Nunchuk::upDate() // update for new informations
{
	int i=0;
	byte bufr[6];
	Wire.requestFrom(0x52,6);
	
	while(Wire.available())
	{
		bufr[i]=Wire.read();
		i++;
	}

	// from http://wiibrew.org/wiki/Wiimote/Extension_Controllers/Guitar_Hero_(Wii)_Guitars,
	Nunchuk::boutonM = !((bufr[4]>>4)&1); // button -
	Nunchuk::boutonP = !((bufr[4]>>2)&1); // button +

	Nunchuk::boutonY = !((bufr[5]>>3)&1); // button yellow
	Nunchuk::boutonR = !((bufr[5]>>6)&1); // button red
	Nunchuk::boutonG = !((bufr[5]>>4)&1); // button green
	Nunchuk::boutonB = !((bufr[5]>>5)&1); // button blue
	Nunchuk::boutonO = !((bufr[5]>>7)&1); // button orange

	Nunchuk::handshake(); 
	delay(100);
}


