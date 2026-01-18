/*
 * GPIO_Program.c
 *
 *  Created on: Dec 13, 2025
 *      Author: ziad-ahmed
 *
 */
#include 	"GPIO_Interface.h"
#include 	"GPIO_Private.h"

/*
 * Step 1: Choose CRL or CRH and calculate bit position
 * Step 2: Clear the 4 bits MODE and CNF to this pin
 * Step 3: Set the Configuration
 */
stm_err_t GPIO_INPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, INPUT_CNF eCnf) {

	// Error Checking
    if (nPin > 15)
    	return STM_ERR_INVALID_SIZE;

    volatile uint32_t* pConfigReg;
    volatile uint32_t* pODR_Reg;
    uint8_t nBitPos;
    // STEP 1
    if (nPin < 8) {
    	// Setting the POS
        nBitPos = nPin * 4;
        // Port Selection
        switch(ePort) {
            case PORTA:
            	pConfigReg 	= &GPIOA_CRL;
            	pODR_Reg	= &GPIOA_ODR;
            	break;

            case PORTB:
            	pConfigReg 	= &GPIOB_CRL;
            	pODR_Reg	= &GPIOB_ODR;
            	break;

            case PORTC:
            	pConfigReg 	= &GPIOC_CRL;
            	pODR_Reg	= &GPIOC_ODR;
            	break;

            default:
            	return STM_ERR_INVALID_ARG;
        }
    }

    else {
    	// Setting the POS
        nBitPos = (nPin - 8) * 4;
        // Port Selection
        switch(ePort) {
            case PORTA:
            	pConfigReg 	= &GPIOA_CRH;
            	pODR_Reg	= &GPIOA_ODR;
            	break;

            case PORTB:
            	pConfigReg 	= &GPIOB_CRH;
            	pODR_Reg	= &GPIOB_ODR;
            	break;

            case PORTC:
            	pConfigReg 	= &GPIOC_CRH;
            	pODR_Reg	= &GPIOC_ODR;
            	break;

            default:
            	return STM_ERR_INVALID_ARG;
        }
    }
    // STEP 2
    CLR_BITS(*pConfigReg,0xF,nBitPos);
    // STEP 3
    uint8_t nConfigValue;
    switch(eCnf) {
        case FLOATING:
        	nConfigValue = 0b0100;
        	break;

        case PULL_UP:
        	nConfigValue = 0b1000;
        	SET_BIT(*pODR_Reg,nPin);
        	break;

        case PULL_DOWN:
        	nConfigValue = 0b1000;
        	CLR_BIT(*pODR_Reg,nPin);
        	break;

        case ANALOG:
        	nConfigValue = 0b0000;
        	break;

        default:
        	return STM_ERR_INVALID_ARG;
    }

    WRITE_BITS(*pConfigReg, nConfigValue, nBitPos);

    return STM_OK;
}

stm_err_t GPIO_INPUT_READ(GPIO_PORTS ePort, uint8_t nPin){

	if(nPin > 15)
		return STM_ERR_INVALID_SIZE;

	switch (ePort) {
		case PORTA:
			return GET_BIT(GPIOA_IDR,nPin);
			break;

		case PORTB:
			return GET_BIT(GPIOB_IDR,nPin);
			break;

		case PORTC:
			return GET_BIT(GPIOC_IDR,nPin);
			break;

		default:
			return STM_ERR_INVALID_ARG;
			break;
	}
}

/*
 * Step 1: Choose CRL or CRH and calculate bit position
 * Step 2: Choose Output MODE bits
 * Step 3: Choose Output Configuration Bits
 * Step 4: Configure the Register
 */
stm_err_t GPIO_OUTPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, OUTPUT_MODE eMode, OUTPUT_CNF eCnf){

	// Error Checking
	    if (nPin > 15)
	    	return STM_ERR_INVALID_SIZE;

	    volatile uint32_t* pConfigReg ;
	    volatile uint32_t* pLCKReg ;
	    uint8_t nConfigVal;
	    uint8_t nConfigBits;
	    uint8_t nModeBits;
	    uint8_t nBitPos;


	    // STEP 1: Choose CRL or CRH and calculate bit position
	    if (nPin < 8) {
	    	// Setting the POS
	        nBitPos = nPin * 4;
	        // Port Selection
	        switch(ePort) {
	            case PORTA: pConfigReg 	= &GPIOA_CRL; pLCKReg 	= &GPIOA_LCKR ;
	            	break;

	            case PORTB: pConfigReg 	= &GPIOB_CRL; pLCKReg 	= &GPIOB_LCKR ;
	            	break;

	            case PORTC: pConfigReg = &GPIOC_CRL; pLCKReg 	= &GPIOC_LCKR ;
	            	break;

	            default: return STM_ERR_INVALID_ARG;
	        }
	    }

	    else {
	    	// Setting the POS
	        nBitPos = (nPin - 8) * 4;
	        // Port Selection
	        switch(ePort) {
	            case PORTA: pConfigReg = &GPIOA_CRH; pLCKReg 	= &GPIOA_LCKR ;
	            	break;

	            case PORTB: pConfigReg = &GPIOB_CRH; pLCKReg 	= &GPIOB_LCKR ;
	            	break;

	            case PORTC: pConfigReg = &GPIOC_CRH; pLCKReg 	= &GPIOC_LCKR ;
	            	break;

	            default: return STM_ERR_INVALID_ARG;
	        }
	    }
	    // STEP 2: Choose Output MODE bits
	    switch (eMode) {
			case MAX_OUTPUT_SPEED_10MHZ: nModeBits = 0b01;
				break;

			case MAX_OUTPUT_SPEED_2MHZ: nModeBits = 0b10;
				break;

			case MAX_OUTPUT_SPEED_50MHZ: nModeBits = 0b11;
				break;

			default: return STM_ERR_INVALID_ARG;
				break;
		}
	    // STEP 3: Set the Configuration
	    switch (eCnf) {
			case OPEN_DRAIN: nConfigBits = 0b01;
				break;

			case PUSH_PULL: nConfigBits = 0b00;
				break;

			case ALT_FN_PUSH_PULL: nConfigBits = 0b10;
				break;

			case ALT_FN_OPEN_DRAIN: nConfigBits = 0b11;
				break;

			default: return STM_ERR_INVALID_ARG;
				break;
		}
	    // STEP 4

	    //Combine the MODE and CNF bits
	    nConfigVal = (nConfigBits<<2) | nModeBits;
	    // Clear Register from previous Config
	    CLR_BITS(*pConfigReg,0xF,nBitPos);
	    // Write new Config
	    WRITE_BITS(*pConfigReg, nConfigVal, nBitPos);

		return STM_OK;
}

stm_err_t GPIO_OUTPUT_WRITE(GPIO_PORTS ePort, uint8_t nPin, logicLevel_t logicLevel){
    if (nPin > 15)
    	return STM_ERR_INVALID_SIZE;

    volatile uint32_t* pPortRegister;

    switch(ePort){
    	case PORTA: pPortRegister = &GPIOA_BSRR; break;
    	case PORTB: pPortRegister = &GPIOB_BSRR; break;
    	case PORTC: pPortRegister = &GPIOC_BSRR; break;

    	default: return STM_ERR_INVALID_ARG ;
    }

    switch(logicLevel){
    	case LOW: 	*pPortRegister = (1U << (nPin+16)); break;
    	case HIGH: 	*pPortRegister = (1U << (nPin)); break;

    	default: return STM_ERR_INVALID_ARG ;
    }

    return STM_OK;
}

stm_err_t GPIO_OUTPUT_TOGGLE(GPIO_PORTS ePort, uint8_t nPin){
    if (nPin > 15)
    	return STM_ERR_INVALID_SIZE;

	 volatile uint32_t* pPortRegister;
	 volatile uint32_t* pPortOutputDataRegister;

	    switch(ePort){
	    	case PORTA: pPortRegister = &GPIOA_BSRR; pPortOutputDataRegister = &GPIOA_ODR;  break;
	    	case PORTB: pPortRegister = &GPIOB_BSRR; pPortOutputDataRegister = &GPIOB_ODR; 	break;
	    	case PORTC: pPortRegister = &GPIOC_BSRR; pPortOutputDataRegister = &GPIOC_ODR;	break;

	    	default: return STM_ERR_INVALID_ARG ;
	    }

	if(GET_BIT(*pPortOutputDataRegister, nPin))
		*pPortRegister = (1 << (nPin+16)); // reset
	else
	    *pPortRegister = (1 << (nPin)); // set

	return STM_OK;
}
