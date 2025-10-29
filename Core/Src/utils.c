/*
 * utils.c
 *
 *  Created on: Oct 14, 2025
 *      Author: FrankAlcaraz
 */


#include "utils.h"
#include "components.h"
#include <assert.h>

#define LED0_SOIL_DRY	3000
#define LED1_SOIL_DRY	3000



static void set_alert1(monitor_t * const me );
static void set_alert2(monitor_t * const me );

void monitor_ctor(monitor_t * const me)
{
	//note: always define vtable itself as static const
	static const struct myVtable_t  _vtbl= {

			&set_alert1,
			&set_alert2
	};

	me->vptr = &_vtbl;

	for( size_t i= 0 ; i < LED_COUNT; i++)
	{
		led_ctor(&me->led_alarms[i]);
	}



	for( size_t i= 0 ; i < SOIL_SENSOR_COUNT; i++)
	{
		cond_ctor(&me->conductivity_sensors[i]);
	}

}


/* "virtual" methods */

static void set_alert1(monitor_t * const me )
	{
		if( (SOIL_SENSOR_COUNT >0) && (LED_COUNT >0) )
		{
			//sufficient moisture ( analog value decreases)
			if ( (me->conductivity_sensors[0].raw_analog_value) <= LED0_SOIL_DRY  )
			{
				me->led_alarms[0].led_state = ALARM_SET; // solid LED sig.
			}

			//insufficient moisture
			if ( (me->conductivity_sensors[0].raw_analog_value) >= LED0_SOIL_DRY  )
			{
				me->led_alarms[0].led_state = ALARM_TOG; // toggle LED sig.
			}


		}

		else if ( LED_COUNT <= 0)
		{
			me->led_alarms[0].led_state = OFF;
		}

	}



static void set_alert2(monitor_t * const me )
	{

	if( (SOIL_SENSOR_COUNT >0) && (LED_COUNT >0) )
	{
		//sufficient moisture ( analog value decreases)
		if ( (me->conductivity_sensors[1].raw_analog_value) <= LED1_SOIL_DRY  )
		{
			me->led_alarms[1].led_state = ALARM_SET; // solid LED sig.
		}

		//insufficient moisture
		if ( (me->conductivity_sensors[1].raw_analog_value) >= LED1_SOIL_DRY  )
		{
			me->led_alarms[1].led_state = ALARM_TOG; // toggle LED sig.
		}


	}

	else if ( LED_COUNT <= 0)
	{
		me->led_alarms[1].led_state = OFF;
	}
	}









//void monitor_ctor(monitor_t * const me, uint16_t _alert_trigger_value, bool _alert_status)
//{
//	me->look_up_raw_value = 0;
//	me->alert_trigger_value = _alert_trigger_value;
//	me->alert_status =false;
//}
//
//
//void set_alert(monitor_t * const me )
//{
//	if( me->look_up_raw_value <= me->alert_trigger_value)
//	{
//		me->alert_status = true; // threshold reached allow alert led to blink
//	}
//
//	else
//	{
//		me->alert_status = false; // alert led off
//	}
//
//}
//
//
//void assign_analog_value(monitor_t * const me, uint16_t raw_value)
//{
//	me->look_up_raw_value = raw_value;
//}
//
//
//
//void toggle_alert(monitor_t * const me, GPIO_TypeDef *port, uint16_t pin)
//{
//	if ( me->alert_status == true)
//	{
//		HAL_GPIO_TogglePin(port, pin);
//	}
//	   else
//	   {
//		   HAL_GPIO_WritePin(port, pin,GPIO_PIN_RESET);
//	   }
//}
