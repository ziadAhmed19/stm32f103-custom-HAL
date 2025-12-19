/*
 * GPIO_Register.h
 *
 *  Created on: Dec 18, 2025
 *      Author: ziad-ahmed
 *
 */

#ifndef MCAL_GPIO_GPIO_REGISTER_H_
#define MCAL_GPIO_GPIO_REGISTER_H_

// PORTA
#define GPIOA_CRL 	(*(volatile uint32_t*)(0x40010800 + 0x00))
#define GPIOA_CRH 	(*(volatile uint32_t*)(0x40010800 + 0x04))
#define GPIOA_IDR 	(*(volatile uint32_t*)(0x40010800 + 0x08))
#define GPIOA_ODR 	(*(volatile uint32_t*)(0x40010800 + 0x0C))
#define GPIOA_BSRR 	(*(volatile uint32_t*)(0x40010800 + 0x10))
#define GPIOA_BRR 	(*(volatile uint32_t*)(0x40010800 + 0x14))
#define GPIOA_LCKR 	(*(volatile uint32_t*)(0x40010800 + 0x18))

// PORTB
#define GPIOB_CRL 	(*(volatile uint32_t*)(0x40010C00 + 0x00))
#define GPIOB_CRH 	(*(volatile uint32_t*)(0x40010C00 + 0x04))
#define GPIOB_IDR 	(*(volatile uint32_t*)(0x40010C00 + 0x08))
#define GPIOB_ODR 	(*(volatile uint32_t*)(0x40010C00 + 0x0C))
#define GPIOB_BSRR 	(*(volatile uint32_t*)(0x40010C00 + 0x10))
#define GPIOB_BRR 	(*(volatile uint32_t*)(0x40010C00 + 0x14))
#define GPIOB_LCKR 	(*(volatile uint32_t*)(0x40010C00 + 0x18))

//PORTC

#define GPIOC_CRL 	(*(volatile uint32_t*)(0x40011000 + 0x00))
#define GPIOC_CRH 	(*(volatile uint32_t*)(0x40011000 + 0x04))
#define GPIOC_IDR 	(*(volatile uint32_t*)(0x40011000 + 0x08))
#define GPIOC_ODR 	(*(volatile uint32_t*)(0x40011000 + 0x0C))
#define GPIOC_BSRR 	(*(volatile uint32_t*)(0x40011000 + 0x10))
#define GPIOC_BRR 	(*(volatile uint32_t*)(0x40011000 + 0x14))
#define GPIOC_LCKR 	(*(volatile uint32_t*)(0x40011000 + 0x18))


#endif /* MCAL_GPIO_GPIO_REGISTER_H_ */
