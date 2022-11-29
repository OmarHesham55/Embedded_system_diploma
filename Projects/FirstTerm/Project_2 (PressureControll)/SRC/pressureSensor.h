#ifndef __PRESSURESENSOR_H_
#define __PRESSURESENSOR_H_

#define normalPressure 20


void pressureInit();
void pressure_value();
void HighPressure_detected();
extern void (*ptrValue)();


#endif