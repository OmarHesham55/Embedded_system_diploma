/*
 * CA.h
 *
 *  Created on: Oct 20, 2022
 *      Author: omart
 */

#ifndef CA_H_
#define CA_H_

#include<stdio.h>
#include<stdlib.h>
#include"state.h"

typedef enum{
	CA_waiting,
	CA_driving
}CA_states;


state_define(CA_Waiting);
state_define(CA_Driving);

extern void (*CA_state_ptr)();

#endif /* CA_H_ */
