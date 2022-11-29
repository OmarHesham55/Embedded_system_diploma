#include <stdint.h>
#include <stdio.h>

#include "driver.h"
// #include "alarmActuator.h"
// #include "pressureController.h"
#include "pressureSensor.h"
#include "alarmMonitor.h"

int Pval;

void setup()
{
	ptrValue=pressure_value;
	ptrAlarm=stopAlarm;

}

int main (){
	GPIO_INITIALIZATION();
	alarminit();
	setup();
	while (1)
	{
		pressure_value();
		ptrValue();
		ptrAlarm();
		Delay(40000);
	}

}
