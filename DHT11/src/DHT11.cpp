/*
	Get DHT11 temperature and humidity data
	Author: YXDZ
	Creation Date: 2022/8/25
	Version: V1.0
	github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#include "DHT11.h"


DHT11::DHT11(uint8_t DHT11_Pin)
{
	_DHT11_Pin = DHT11_Pin;
}

void DHT11::readDht11()
{
	uint8_t bits[5];
    uint8_t cnt = 7;
    uint8_t idx = 0;
    for (int i=0; i< 5; i++) bits[i] = 0;
	delay(200);
    pinMode(_DHT11_Pin, OUTPUT);
    digitalWrite(_DHT11_Pin, LOW);
    delay(18);
    digitalWrite(_DHT11_Pin, HIGH);
    delayMicroseconds(40);
	digitalWrite(_DHT11_Pin,LOW);
    pinMode(_DHT11_Pin, INPUT);
    unsigned int loopCnt = 10000;
	while(digitalRead(_DHT11_Pin) == LOW){
		if(loopCnt-- == 0)
		{
			break;
		}
	}
	loopCnt = 30000;
	while(digitalRead(_DHT11_Pin) == HIGH){
		if(loopCnt-- == 0){
			break;
		}
	}
	for(int i=0;i<40;i++){
		loopCnt = 10000;
		while(digitalRead(_DHT11_Pin) == LOW)
        {
			if(loopCnt-- == 0){
				break;
			}
		}
        unsigned long t = micros();
        while(digitalRead(_DHT11_Pin) == HIGH)
        {
			if(loopCnt-- == 0){
				break;
			}
		}
		if ((micros() - t) > 50) bits[idx] |= (1 << cnt);
        if (cnt == 0)
        {
            cnt = 7;   
            idx++;      
        }else{
			cnt--;
		} 
	}
    Humidity = bits[0]; 
    Temperature = bits[2]; 
}


int DHT11::getTemperature()
{
	return Temperature;
}

int DHT11::getHumidity()
{
	return Humidity;
}

