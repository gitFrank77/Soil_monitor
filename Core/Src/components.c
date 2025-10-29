/*
 * components.c
 *
 *  Created on: Oct 18, 2025
 *      Author: FrankAlcaraz
 */


#include "components.h"

/*LED component*/

//void set_led_state(led_t * const me, int _led_state)
//{
//	me->led_state = _led_state;
//}


void led_ctor(led_t * const me)
{
	me->led_state = OFF;

}




/* Conductivity sensor component*/

void cond_ctor(cond_t * const me)
{
	me->alarm_value_high = 0;
	me->alarm_value_low  = 0;
	me->raw_analog_value = 0;
	me->cond_state  = STANDBY;
}











