#include "sht31.h"
#include <assert.h>

uint16_t uint8_to_16(uint8_t MSB, uint8_t LSB)
{
	uint16_t data;
	data = (uint16_t)MSB << 8;	// on récupère la partie MSB
	data |= LSB;		// on récupère la partie LSB

	return data;
}

uint8_t calculate_crc(const uint8_t *data, size_t length)	// XOR
{
	uint8_t crc = 0xff;

	for (size_t i = 0; i < length; i++) {
		crc ^= data[i];
		for (size_t j = 0; j < 8; j++) {
			if ((crc & 0x80u) != 0)
				crc = (uint8_t)((uint8_t)(crc << 1u) ^ 0x31u);
			else
				crc <<= 1u;
		}
	}
	return crc;
}

float calcul_humidity(uint16_t SRH)
{
	return 100 * (SRH / (float)65535);			// SRH est le mot binaire de l'humidité renvoyée par le capteur
}

float calcul_temperature(uint16_t ST)
{
	return -45 + 175 * (ST / (float)65535);	// ST est le mot binaire de la température renvoyée par le capteur
}


/// fonctions utiles ---------------------------------------------------
bool SHT31_init(I2C_HandleTypeDef *handle)
{
	assert(handle->Init.NoStretchMode == I2C_NOSTRETCH_DISABLE);
	// TODO: Assert i2c frequency is not too high

	uint8_t status_reg_and_checksum[3];
	if (HAL_I2C_Mem_Read(handle, SHT31_ADDR << 1u, COMMAND_READ_STATUS_REGISTER, 2, (uint8_t*)&status_reg_and_checksum,
					  sizeof(status_reg_and_checksum), TIMEOUT) != HAL_OK) {
		return false;
	}

	uint8_t calculated_crc = calculate_crc(status_reg_and_checksum, 2);

	if (calculated_crc != status_reg_and_checksum[2]) {
		return false;
	}

	return true;
}

bool send_command(I2C_HandleTypeDef *handle, uint16_t command)
{
	uint8_t command_buffer[2];						// on envoit les données en bloc de 8 bits, les commandes sont de taille 16 bits
	command_buffer[0] = (command & 0xff00) >> 8;	// on récupère la partie MSB
	command_buffer[1] = command & 0xff;				// on récupère la partie LSB

	if (HAL_I2C_Master_Transmit(handle, SHT31_ADDR << 1, command_buffer, sizeof(command_buffer), TIMEOUT) != HAL_OK)
		return false;
	return true;
}

bool SHT31_mesure_temp_hum(I2C_HandleTypeDef *handle, float temperature, float humidity)
{
	uint16_t ST, SRH;
	uint8_t buffer[6];	// on recoit 16 bits temp + checksum + 16 bits hum + checksum = 6 octets

	if (send_command(handle, COMMAND_MEASURE) != true)
		return false;

	HAL_Delay(1);	// on laisse le temps au capteur

	if (HAL_I2C_Master_Receive(handle, SHT31_ADDR << 1, buffer, 6, TIMEOUT) != HAL_OK)
		return false;

	uint8_t temperature_crc = calculate_crc(buffer, 2);
	uint8_t humidity_crc = calculate_crc(buffer + 3, 2);
	if (temperature_crc != buffer[2] || humidity_crc != buffer[5])
		return false;

	ST = uint8_to_16(buffer[0], buffer[1]);
	SRH = uint8_to_16(buffer[3], buffer[4]);

	temperature = calcul_temperature(ST);
	humidity = calcul_humidity(SRH);

	return true;
}


// à finir
/*uint8_t calculate_crc(uint8_t data)	// CRC-8 dallas/maxim
{
	uint8_t crc = 0xff;	// ibitialisation
	int zeros;
	int ones;
	//int remainder;

	for (int i = 0; i < 8; i++) {	// récupère le nombre de '1' dans l'octet
		ones += (data & 0x01) >> i;
	}
	zeros = 8 - ones;


	return crc + zeros + ones;
}
*/




