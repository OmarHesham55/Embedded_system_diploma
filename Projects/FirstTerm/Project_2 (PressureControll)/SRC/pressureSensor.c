#include "pressureSensor.h"
#include "driver.h"
#include "alarmMonitor.h"

int Pval = 0;
void (*ptrValue)();

void pressureInit(void){
	getPressureVal(0);
}
void pressure_value(){
	int Pval = getPressureVal();
	if(Pval >= normalPressure){
		ptrValue = HighPressure_detected;
	}else{
		ptrValue = pressure_value;
	}

}


void HighPressure_detected(){
	setAlarm();
}