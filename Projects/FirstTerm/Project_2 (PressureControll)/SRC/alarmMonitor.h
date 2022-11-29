#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "pressureSensor.h"

typedef enum{
	OFF,
	ON
}alarmStatus;

void setAlarm();
void startAlarm();
void stopAlarm();
void alarminit ();

extern void (*ptrAlarm)();

#endif