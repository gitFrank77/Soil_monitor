/*
 * utils.h
 *
 *  Created on: Oct 14, 2025
 *      Author: FrankAlcaraz
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_
#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "stm32f0xx.h"
#include "components.h"


#define LED_COUNT			2
#define SOIL_SENSOR_COUNT	2





struct myVtable_t;

typedef struct
{
	const struct myVtable_t * vptr;

	led_t led_alarms[LED_COUNT];
	cond_t conductivity_sensors[SOIL_SENSOR_COUNT];

	  //struct ShapeVtbl const *vptr;

}monitor_t ;

struct myVtable_t
{
	void (*fptr1)(monitor_t * const me);
	void (*fptr2)(monitor_t * const me);
};

void monitor_ctor(monitor_t * const me);

//typedef struct _monitor
//{
//
//	uint16_t look_up_raw_value;
//	uint16_t alert_trigger_value;
//	bool alert_status;
//
//}monitor_t;
//
//
//
//void set_alert(monitor_t * const me );
//void monitor_ctor(monitor_t * const me, uint16_t _alert_trigger_value, bool _alert_status);
//void assign_analog_value(monitor_t * const me, uint16_t raw_value);
//
//void toggle_alert(monitor_t * const me, GPIO_TypeDef *port, uint16_t pin);
#endif /* INC_UTILS_H_ */
