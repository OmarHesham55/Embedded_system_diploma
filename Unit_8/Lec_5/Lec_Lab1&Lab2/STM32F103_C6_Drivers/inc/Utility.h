/*
 * Utility.h
 *
 *  Created on: May 16, 2023
 *      Author: omart
 */


#include<stdint.h>
#ifndef INC_UTILITY_H_
#define INC_UTILITY_H_

#define PIN_NUM__0											((uint16_t)0x0001)
#define PIN_NUM__1											((uint16_t)0x0002)
#define PIN_NUM__2											((uint16_t)0x0004)
#define PIN_NUM__3											((uint16_t)0x0008)
#define PIN_NUM__4											((uint16_t)0x0010)
#define PIN_NUM__5											((uint16_t)0x0020)
#define PIN_NUM__6											((uint16_t)0x0040)
#define PIN_NUM__7											((uint16_t)0x0080)
#define PIN_NUM__8											((uint16_t)0x0100)
#define PIN_NUM__9											((uint16_t)0x0200)
#define PIN_NUM__10											((uint16_t)0x0400)
#define PIN_NUM__11											((uint16_t)0x0800)
#define PIN_NUM__12											((uint16_t)0x1000)
#define PIN_NUM__13											((uint16_t)0x2000)
#define PIN_NUM__14											((uint16_t)0x4000)
#define PIN_NUM__15											((uint16_t)0x8000)
#define PIN_NUM__ALL										((uint16_t)0xFFFF)


#define SET_PIN(REG,PIN)									REG|=(1 << PIN)
#define	RESET_PIN(REG,PIN)									REG&=~(1 << PIN)
#define TOGG_PIN(REG,PIN)									REG^=(1 << PIN)
#define READ_PIN(REG,PIN)								    (REG >> PIN) & 1

#endif /* INC_UTILITY_H_ */
