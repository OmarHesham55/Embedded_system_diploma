#include "driver.h"
#include "alarmActuator.h"
#include "alarmMonitor.h"


void StartAlarm(){
	Set_Alarm_actuator(0);
	Delay(6000000);
	Set_Alarm_actuator(1);
}

void StopAlarm(void){
	Set_Alarm_actuator(1);
}