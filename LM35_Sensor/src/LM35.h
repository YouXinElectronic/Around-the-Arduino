#ifndef LM35_h
#define LM35_h

#include "Arduino.h"

enum Unity { 
	CELCIUS, 
	KELVIN,
	FAHRENHEIT
};

class LM35 {

	public:
		LM35(int analogPin);
		double getTemp();
		double getTemp(Unity unity);

	private:
		int _analogPin;

};

#endif