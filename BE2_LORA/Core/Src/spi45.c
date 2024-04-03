#include <spi45.h>
#include <string.h>
#include "stm32l4xx_hal.h"


void spi45_transmit(SPI_HandleTypeDef *hspi, uint8_t data, uint8_t size)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);  				//CS
	HAL_SPI_Transmit(hspi, &data, (uint16_t)size, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
}

void spi45_write_register(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t data)
{
	// taille = 2 octets toujours (datasheet)
	//((1 << 7) | reg) << 8) | data
	// bit de write + registre + data
	uint8_t buffer[2];
	buffer[0] = (1 << 7) | reg;
	buffer[1] = data;

	spi45_transmit(hspi, buffer[0], 2);
}
