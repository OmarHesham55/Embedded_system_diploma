#include "driver.h"
#include "alarmMonitor.h"
#include "pressureSensor.h"

void (*ptrAlarm)();


void alarminit ()
{

	Set_Alarm_actuator(1);
}

void setAlarm(){
	ptrAlarm = startAlarm;
}

void startAlarm(){
	Set_Alarm_actuator(0);
	Delay(60000);
	Set_Alarm_actuator(1);
	ptrAlarm = stopAlarm;
}

void stopAlarm(){
	Set_Alarm_actuator(1);
}
