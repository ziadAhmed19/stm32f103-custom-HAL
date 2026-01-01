/*
 * BitMath.h
 *
 *  Created on: Dec 17, 2025
 *      Author: ziad-ahmed
 */

#ifndef CONFIG_BITMATH_H_
#define CONFIG_BITMATH_H_

// DEFINES

// Single-Bit Manipulation
#define SET_BIT(REG,BIT) 		REG |=(1<<BIT)
#define CLR_BIT(REG,BIT) 		REG &=~(1<<BIT)
#define TGL_BIT(REG,BIT) 		REG ^=(1<<BIT)
#define GET_BIT(REG,BIT) 		((REG>>BIT)&0x01)

// Multi-Bit Manipulation
#define CLR_BITS(REG,MASK,POS)   REG &=~((MASK)<<(POS))
#define WRITE_BITS(REG,VAL,POS)    REG |=((VAL)<<(POS))

#define MODIFY_BITS(REG, MASK, VAL, POS)  do { \
    REG &=~((MASK)<<(POS));	\
    REG |=((VAL)<<(POS));	\
} while(0)



#endif /* CONFIG_BITMATH_H_ */
