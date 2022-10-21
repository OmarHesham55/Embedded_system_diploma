/*
 * state.h
 *
 *  Created on: Oct 20, 2022
 *      Author: omart
 */

#ifndef STATE_H_
#define STATE_H_

#define state_define(state_FUNC)  void state_##state_FUNC()
#define state(state_FUNC)          state_##state_FUNC



#endif /* STATE_H_ */
