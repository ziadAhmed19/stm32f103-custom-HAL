/*
 * RCC_Register.h
 *
 *  Created on: Jan 18, 2026
 *      Author: ziad-ahmed
 */

#ifndef MCAL_RCC_RCC_REGISTER_H_
#define MCAL_RCC_RCC_REGISTER_H_

#define RCC_CR 			(*(volatile uint32_t*)(0x40021000 + 0x00))
#define RCC_CFGR 		(*(volatile uint32_t*)(0x40021000 + 0x04))
#define RCC_CIR 		(*(volatile uint32_t*)(0x40021000 + 0x08))
#define RCC_APB2RSTR 	(*(volatile uint32_t*)(0x40021000 + 0x0C))
#define RCC_APB1RSTR 	(*(volatile uint32_t*)(0x40021000 + 0x10))
#define RCC_AHBENR 		(*(volatile uint32_t*)(0x40021000 + 0x14))
#define RCC_APB2ENR 	(*(volatile uint32_t*)(0x40021000 + 0x18))
#define RCC_APB1ENR 	(*(volatile uint32_t*)(0x40021000 + 0x1C))
#define RCC_BDCR 		(*(volatile uint32_t*)(0x40021000 + 0x20))









#endif /* MCAL_RCC_RCC_REGISTER_H_ */
