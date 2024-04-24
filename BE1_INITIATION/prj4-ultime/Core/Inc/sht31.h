#ifndef SHT31_H
#define SHT31_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32l4xx_hal.h"		// l0 pour une carte L0, L1 poiur une carte L1 etc
#include "stm32l4xx_hal_i2c.h"	// pareil

// DEFINE
//#define COMMAND_MEASURE			 		0x2400	// lance une mesure : high-repeatability, no clock stretching
#define COMMAND_MEASURE					0x2c06
#define COMMAND_SOFT_RESET 				0x30A2	// permet de reset le capteur
#define COMMAND_HEATER_ENABLE			0x306D	// active le heater interne
#define COMMAND_HEATER_DISABLE			0x3066	// désactive le heater interne
#define COMMAND_READ_STATUS_REGISTER	0xF32D	// lit le registre d'état pour savoir où en est le capteur de la dernière commande envoyée
#define COMMAND_CLEAR_STATUS_REGISTER	0x3041	// met à 0 tout les bits du registre d'état

#define SHT31_ADDR	0x44

#ifndef TIMEOUT	// aucune idée
#define TIMEOUT		30
#endif

// FONCTIONS
bool SHT31_init(I2C_HandleTypeDef *handle);
float calcul_humidity(uint16_t SRH);
float calcul_temperature(uint16_t ST);
bool send_command(I2C_HandleTypeDef *handle, uint16_t command);
uint8_t calculate_crc(const uint8_t *data, size_t length);
bool SHT31_mesure_temp_hum(I2C_HandleTypeDef *handle, float temperature, float humidity);

#endif
