#include "leds.h"
#include "main.h"

const struct {GPIO_TypeDef *port; uint16_t pin;} leds[] = {
	{led0_GPIO_Port, led0_Pin}, {led1_GPIO_Port, led1_Pin}, {led2_GPIO_Port, led2_Pin}, {led3_GPIO_Port, led3_Pin}, {led4_GPIO_Port, led4_Pin},
	{led5_GPIO_Port, led5_Pin}, {led6_GPIO_Port, led6_Pin}, {led7_GPIO_Port, led7_Pin}, {led8_GPIO_Port, led8_Pin}, {led9_GPIO_Port, led9_Pin},
	{led10_GPIO_Port, led10_Pin}
};

void all_leds_on(void)
{
	int i;
	
	for(i = 0; i < 11; i++)
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
}

void all_leds_on_up_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 0; i < 11; i++)
	{
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
		HAL_Delay(delay);
	}
}

void all_leds_on_down_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 10; i >= 0; i--)
	{
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
		HAL_Delay(delay);
	}
}

void all_leds_off(void)
{
	int i;
	
	for(i = 0; i < 11; i++)
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_RESET);
}

void all_leds_off_up_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 0; i < 11; i++)
	{
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_RESET);
		HAL_Delay(delay);
	}
}

void all_leds_off_down_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 10; i >= 0; i--)
	{
		HAL_GPIO_WritePin(leds[i].port, leds[i].pin, 	GPIO_PIN_RESET);
		HAL_Delay(delay);
	}
}

void all_leds_switch(void)
{
	int i;
	
	for(i = 0; i < 11; i++)
		HAL_GPIO_TogglePin(leds[i].port, leds[i].pin);		
}

void all_leds_switch_up_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 0; i < 11; i++)
	{
		HAL_GPIO_TogglePin(leds[i].port, leds[i].pin);		
		HAL_Delay(delay);
	}
}

void all_leds_switch_down_with_delay(uint16_t delay)
{
	int i;
	
	for(i = 10; i >= 0; i--)
	{
		HAL_GPIO_TogglePin(leds[i].port, leds[i].pin);		
		HAL_Delay(delay);
	}
}

void one_led_blink(uint8_t num_led, uint16_t delay)
{
	HAL_GPIO_WritePin(leds[num_led].port, leds[num_led].pin, GPIO_PIN_SET);
	HAL_Delay(delay);
	HAL_GPIO_WritePin(leds[num_led].port, leds[num_led].pin, GPIO_PIN_RESET);
	HAL_Delay(delay);
}
