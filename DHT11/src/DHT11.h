
/*
	Get DHT11 temperature and humidity data
	Author: YXDZ
	Creation Date: 2022/8/25
	Version: V1.0
	github：https://github.com/YouXinElectronic/Around-the-Arduino
*/
#ifndef DHT11_h
#define DHT11_h


#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


class DHT11
{
private:
	uint8_t _DHT11_Pin;
	int Temperature,Humidity;
public:
	/*Constructor, define the pins used by DHT11*/
	DHT11(uint8_t DHT11_Pin);
	/*Read DHT11 once and store the data in the variables Temperature, Humidity*/
	void readDht11();
	/*Get temperature data and return*/
	int getTemperature();
	/*Get humidity data and return*/
	int getHumidity();
};


#endif


