#include "nrf24l01.h"
#include "spi1.h"

void NRF_Command(uint8_t command)
{
	SPI1_Write(command);
}

uint8_t NRF_ReadReg(uint8_t reg)
{
	SPI1_Write(NRF_REG_MASK(reg));
	return SPI1_Read();
}

uint8_t NRF_ReadStatus()
{
	return SPI1_Read();
}

void NRF_WriteReg(uint8_t reg, uint8_t val)
{
	SPI1_Write(NRF_REG_MASK(reg) | NRF_W);
	SPI1_Write(val);
}

void NRF_ReadReg_Buf(uint8_t reg, uint8_t *buf, uint8_t size)
{
	SPI1_Write(NRF_REG_MASK(reg));
	for(uint8_t i =0; i < size; i++)
		buf[i] = SPI1_Read();
}

void NRF_WriteReg_Buf(uint8_t reg, uint8_t *buf, uint8_t size)
{
	SPI1_Write(NRF_REG_MASK(reg));
	for(uint8_t i =0; i < size; i++)
		SPI1_Write(buf[i]);
}

void NRF_WritePayload(uint8_t *buf, uint8_t size)
{
	SPI1_Write(NRF_W_TX_PAYLOAD);
	for(uint8_t i =0; i < size; i++)
		SPI1_Write(buf[i]);
}

void NRF_ReadPayload(uint8_t *buf, uint8_t size)
{
	SPI1_Write(NRF_R_RX_PAYLOAD);
	for(uint8_t i =0; i < size; i++)
		buf[i] = SPI1_Read();
}