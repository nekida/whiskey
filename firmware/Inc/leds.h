#ifndef __LEDS
#define __LEDS

#include "main.h"

void all_leds_on(void);
void all_leds_on_up_with_delay(uint16_t delay);
void all_leds_on_down_with_delay(uint16_t delay);
void all_leds_off(void);
void all_leds_off_up_with_delay(uint16_t delay);
void all_leds_off_down_with_delay(uint16_t delay);
void all_leds_switch(void);
void all_leds_switch_up_with_delay(uint16_t delay);
void all_leds_switch_down_with_delay(uint16_t delay);
void one_led_blink(uint8_t num_led, uint16_t delay);

#endif /* __LEDS */
