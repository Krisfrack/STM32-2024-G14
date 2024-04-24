#include "dht21.h"

void mesure_dht21()
{
	uint32_t init_time = tic;

	// start
	HAL_GPIO_WritePin(GPIOD, PIN8, LOW);
	while(init_time - tic <= 10); // attend au moins 800us
	HAL_GPIO_WritePin(GPIOD, PIN8, HIGH);

	//
}
