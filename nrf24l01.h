/* 
 * File:   nrf24l01.h
 * Author: paco
 *
 * Created on 9 de octubre de 2024, 06:35 PM
 */

#ifndef NRF24L01_H
#define	NRF24L01_H

#ifdef	__cplusplus
extern "C" {
#endif

//NRF24L01 Commands
#define NRF_R_REGISTER		0x00U
#define NRF_W_REGISTER		0x20U
#define NRF_R_RX_PAYLOAD	0x61U
#define NRF_W_TX_PAYLOAD	0xA0U
#define NRF_FLUSH_TX		0xE1U
#define NRF_FLUSH_RX		0xE2U
#define NRF_REUSE_TX_PL		0xE3U
#define NRF_R_RX_PL_WID		0x60U
#define NRF_W_ACK_PAYLOAD	0xA8U
#define NRF_W_TX_PAYLOAD_NO_ACK	0xB0U
#define NRF_NOP			0xFFU
	
#define NRF_W			NRF_W_REGISTER
	
//NRF Register MASK	
#define NRF_REG_MASK(addr)	(addr & 0x1FU)
#define NRF_ARC_MASK(arc)	(arc & 0x0FU)
#define NRF_CH_MASK(ch)		(ch & 0x7F)
#define NRF_STATUS_PIPE(st)	((st & 0x0EU) >> 1)
#define NRF_LOST_PACKETS(ob)	((ob & 0xF0) >> 4)
#define NRF_RETR_PACKETS(ob)	(ob & 0x0F)
	
//NRF24L01 Registers
#define NRF_CONFIG	0x00U
#define NRF_EN_AA	0x01U
#define NRF_EN_RXADDR	0x02U
#define NRF_SETUP_AW	0x03U
#define NRF_SETUP_RETR	0x04U
#define NRF_RF_CH	0x05U
#define NRF_RF_SETUP	0x06U
#define NRF_STATUS	0x07U
#define NRF_OBSERVE_TX	0x08U
#define NRF_RPD		0x09U
#define NRF_RX_ADDR_P0	0x0AU
#define NRF_RX_ADDR_P1	0x0BU
#define NRF_RX_ADDR_P2	0x0CU
#define NRF_RX_ADDR_P3	0x0DU
#define NRF_RX_ADDR_P4	0x0EU
#define NRF_RX_ADDR_P5	0x0FU
#define NRF_TX_ADDR	0x10U
#define NRF_RX_PW_P0	0x11U
#define NRF_RX_PW_P1	0x12U
#define NRF_RX_PW_P2	0x13U
#define NRF_RX_PW_P3	0x14U
#define NRF_RX_PW_P4	0x15U
#define NRF_RX_PW_P5	0x16U
#define NRF_FIFO_STATUS	0x17U
#define NRF_DYNPD	0x1CU
#define NRF_FEATURE	0x1DU
	
//NRF24L01 bits

//NRF_CONFIG
#define NRF_MASK_RX_DR	0x40U
#define NRF_MASK_TX_DS	0x20U
#define NRF_MASK_MAX_RT	0x10U
#define NRF_EN_CRC	0x08U
#define NRF_CRCO	0x04U
#define NRF_PWR_UP	0x02U
#define NRF_PRIM_RX	0x01U
	
//NRF_EN_AA
#define NRF_ENAA_P5	0x20U
#define NRF_ENAA_P4	0x10U
#define NRF_ENAA_P3	0x08U
#define NRF_ENAA_P2	0x04U
#define NRF_ENAA_P1	0x02U
#define NRF_ENAA_P0	0x01U
	
//NRF_EN_RXADDR
#define NRF_ERX_P5	0x20U
#define NRF_ERX_P4	0x10U
#define NRF_ERX_P3	0x08U
#define NRF_ERX_P2	0x04U
#define NRF_ERX_P1	0x02U
#define NRF_ERX_P0	0x01U
	
//NRF_SETUP_AW
#define NRF_AW_3BYTES	0x01U
#define NRF_AW_4BYTES	0x02U
#define NRF_AW_5BYTES	0x03U

//NRF_SETUP_RETR
#define NRF_ARD_250	0x00U
#define NRF_ARD_500	0x10U
#define NRF_ARD_750	0x20U
#define NRF_ARD_1000	0x30U
#define NRF_ARD_1250	0x40U
#define NRF_ARD_1500	0x50U
#define NRF_ARD_1750	0x60U
#define NRF_ARD_2000	0x70U
#define NRF_ARD_2250	0x80U
#define NRF_ARD_2500	0x90U
#define NRF_ARD_2750	0xA0U
#define NRF_ARD_3000	0xB0U
#define NRF_ARD_3250	0xC0U
#define NRF_ARD_3500	0xD0U
#define NRF_ARD_3750	0xE0U
#define NRF_ARD_4000	0xF0U
#define NRF_ARC_DIS	0x00U

//NRF_RF_SETUP
#define NRF_CONT_WAVE	0x80U
#define NRF_RF_DR_LOW	0x20U
#define NRF_PLL_LOCK	0x10U
#define NRF_RF_DR_HIGH	0x08U
#define NRF_RF_PWR_18DB	0x00U
#define NRF_RF_PWR_12DB	0x02U
#define NRF_RF_PWR_6DB	0x04U
#define NRF_RF_PWR_0DB	0x06U
	
//NRF_RF_STATUS
#define NRF_RX_DR	0x40U
#define NRF_TX_DS	0x20U
#define NRF_MAX_RT	0x10U
#define NRF_TX_FULL	0x01U
	
//NRF_RPD
#define NRF_RPD_B	0x01U
	
//NRF_FIFO_STATUS
#define NRF_TX_REUSE	0x40U
#define NRF_TX_FULL	0x20U
#define NRF_TX_EMPTY	0X10U
#define NRF_RX_FULL	0x02U
#define NRF_RX_EMPTY	0x01U
	
//NRF_DYNPD
#define NRF_DPL_P5	0x20U
#define NRF_DPL_P4	0x10U
#define NRF_DPL_P3	0x08U
#define NRF_DPL_P2	0x04U
#define NRF_DPL_P1	0x02U
#define NRF_DPL_P0	0x01U
	
//NRF_FEATURE
#define NRF_EN_DPL	0x04U
#define NRF_EN_ACK_PAY	0x02U
#define NRF_EN_DYN_ACK	0x01U


#ifdef	__cplusplus
}
#endif

#endif	/* NRF24L01_H */

