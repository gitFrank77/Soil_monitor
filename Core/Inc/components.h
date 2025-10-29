/*
 * components.h
 *
 *  Created on: Oct 18, 2025
 *      Author: FrankAlcaraz
 */

#ifndef INC_COMPONENTS_H_
#define INC_COMPONENTS_H_

#include <stdint.h>

/*LED component*/

typedef enum
{
	OFF = 0,
	ON,
	STANDBY,
	READING,
	ALARM_TOG,
	ALARM_SET

}component_state_t;

struct _led; //forward declaration

typedef struct _led
{
	component_state_t led_state;
//	struct _led const *vptr; // assign to get value method

}led_t;

void led_ctor(led_t * const me);
void set_led_state(led_t * const me, int _led_state);

/* Conductivity sensor component*/
struct _cond_t; //forward declaration
typedef struct _cond
{
	uint16_t raw_analog_value;
	uint16_t alarm_value_high;
	uint16_t alarm_value_low;
	component_state_t cond_state;

}cond_t;

void cond_ctor(cond_t * const me);

#endif /* INC_COMPONENTS_H_ */
