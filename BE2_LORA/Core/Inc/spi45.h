#ifndef SPI45_H_
#define SPI45_H_

#include "stm32l4xx_hal.h"
#include <stdint.h>

#define REG_RegOpMode 0x01
/*
typedef union {
	struct {
		uint8_t LongRangeMode: 		1;
		uint8_t AccessSharedReg: 	1;
		uint8_t reserved: 			2;
		uint8_t LowFrequencyModeOn: 1;
		uint8_t Mode: 				3;
	};
	uint8_t reg;
} regopmode;
*/


void spi45_transmit(SPI_HandleTypeDef *hspi, uint8_t data, uint8_t size);
void spi45_write_register(SPI_HandleTypeDef *hspi, uint8_t reg, uint8_t data);


#endif /* INC_SPI45_H_ */
