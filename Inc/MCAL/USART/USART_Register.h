/*
 * USART_Register.h
 *
 *  Created on: Jan 19, 2026
 *      Author: ziad-ahmed
 */

#ifndef MCAL_USART_USART_REGISTER_H_
#define MCAL_USART_USART_REGISTER_H_

// Base Addresses

#define USART2_BASE_ADDR 0x40004400
#define USART3_BASE_ADDR 0x40004800

// USART2

#define USART2_SR	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x00))
#define USART2_DR	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x04))
#define USART2_BRR	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x08))
#define USART2_CR1	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x0C))
#define USART2_CR2	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x10))
#define USART2_CR3	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x14))
#define USART2_GTPR	(*(volatile uint32_t*)(USART2_BASE_ADDR + 0x18))

// USART3

#define USART3_SR	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x00))
#define USART3_DR	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x04))
#define USART3_BRR	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x08))
#define USART3_CR1	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x0C))
#define USART3_CR2	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x10))
#define USART3_CR3	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x14))
#define USART3_GTPR	(*(volatile uint32_t*)(USART3_BASE_ADDR + 0x18))


#endif /* MCAL_USART_USART_REGISTER_H_ */
