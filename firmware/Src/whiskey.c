#include "whiskey.h"
#include "main.h"
#include "leds.h"
#include <stdlib.h>

void func_regular(void)
{
	all_leds_on();
}

void func_off(void)
{
	all_leds_off();
}

void func_blink_all(uint16_t delay_time)
{
	all_leds_switch();
	HAL_Delay(delay_time);
}

void func_up_down_on__all_off(uint16_t delay_time)
{
	all_leds_on_up_with_delay(delay_time);
	all_leds_off();
	HAL_Delay(delay_time);
}

void func_down_up_on__all_off(uint16_t delay_time)
{
	all_leds_on_down_with_delay(delay_time);
	all_leds_off();
	HAL_Delay(delay_time);
}

void func_up_down_on__up_down_off(uint16_t delay_time)
{
	all_leds_on_up_with_delay(delay_time);
	all_leds_off_up_with_delay(delay_time);
}

void func_down_up_on__down_up_off(uint16_t delay_time)
{
	all_leds_on_down_with_delay(delay_time);
	all_leds_off_down_with_delay(delay_time);
}

void func_up_down_on__down_up_off(uint16_t delay_time)
{
	all_leds_on_up_with_delay(delay_time);
	all_leds_off_down_with_delay(delay_time);
}

void func_down_up_on__up_down_off(uint16_t delay_time)
{
	all_leds_on_down_with_delay(delay_time);
	all_leds_off_up_with_delay(delay_time);
}

void func_chaos(uint16_t delay_range)
{
	uint8_t 	rndm_pin;
	uint16_t 	rndm_delay;
	
	rndm_pin 		=	rand() % 11;
	rndm_delay	= rand() % delay_range;
	
	one_led_blink(rndm_pin, rndm_delay);
}

void func_round_up(uint16_t delay_time)
{
	all_leds_on_up_with_delay(delay_time);
	all_leds_off_up_with_delay(delay_time);
	HAL_Delay(delay_time);
	all_leds_on_down_with_delay(delay_time);
	all_leds_off_down_with_delay(delay_time);
	HAL_Delay(delay_time);
}

void func_round_down(uint16_t delay_time)
{
	all_leds_on_down_with_delay(delay_time);
	all_leds_off_down_with_delay(delay_time);
	HAL_Delay(delay_time);
	all_leds_on_up_with_delay(delay_time);
	all_leds_off_up_with_delay(delay_time);
	HAL_Delay(delay_time);
}
