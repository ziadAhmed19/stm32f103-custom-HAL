# stm32f103-firmware

## Project Overview

**stm32f103-firmware** is a modular firmware for the STM32F103C6/CT6 “Blue Pill” development board.
It provides a layered MCAL-style driver architecture, starting with **GPIO** support and a generic **error handling system (`stm_err_t`)**.

This firmware is structured using a **DIO (Digital Input/Output) layered approach**, allowing future expansion to peripherals such as timers, UART, and external interrupts.

---

## Supported Peripherals (Implemented)

### 1. GPIO (DIO Layer)

The GPIO driver provides a full set of functions to configure and manipulate pins on GPIO ports **A, B, and C**.

#### Input Pin Functions

* **`stm_err_t GPIO_INPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, INPUT_CNF eCnf)`**

  Configures a pin as input with a specific input mode.
  **Implementation steps:**

  1. Choose CRL or CRH register and calculate the 4-bit position for the pin
  2. Clear existing MODE and CNF bits for that pin
  3. Set the input configuration bits

* **`stm_err_t GPIO_INPUT_READ(GPIO_PORTS ePort, uint8_t nPin)`**

  Reads the current state of a GPIO input pin. Returns `STM_OK` on success or a relevant error code if the pin number is invalid.

#### Output Pin Functions

* **`stm_err_t GPIO_OUTPUT_CONFIG(GPIO_PORTS ePort, uint8_t nPin, OUTPUT_MODE eMode, OUTPUT_CNF eCnf)`**

  Configures a pin as output with the specified output mode and configuration.
  **Implementation steps:**

  1. Choose CRL or CRH register and calculate the 4-bit position for the pin
  2. Set the output mode bits
  3. Set the output configuration bits
  4. Configure the register

* **`stm_err_t GPIO_OUTPUT_WRITE(GPIO_PORTS ePort, uint8_t nPin, logicLevel_t logicLevel)`**

  Writes a logic HIGH or LOW to a GPIO output pin.
  Uses **atomic-level writing** via the `BSRR` register for safe, interrupt-friendly updates.

* **`stm_err_t GPIO_OUTPUT_TOGGLE(GPIO_PORTS ePort, uint8_t nPin)`**

  Toggles the current output state of a pin.
  Reads the pin’s output latch (`ODR`) and writes to `BSRR` for atomic toggle.

---

## Error Handling (`stm_err_t`)

The firmware includes a **generic error handling module**, inspired by Espressif’s ESP-IDF approach.

### Error Data Type

```c
typedef int stm_err_t;
```

### Standard Error Codes

| Error Code            | Meaning                                |
| --------------------- | -------------------------------------- |
| STM_OK                | Operation completed successfully       |
| STM_ERROR             | Generic failure                        |
| STM_ERR_INVALID_ARG   | Invalid argument passed to a function  |
| STM_ERR_INVALID_SIZE  | Invalid pin or size                    |
| STM_ERR_INVALID_STATE | Operation not allowed in current state |
| STM_ERR_NOT_FOUND     | Requested resource not found           |
| STM_ERR_TIMEOUT       | Operation timed out                    |
| STM_ERR_NOT_FINISHED  | Operation not fully completed          |

### Error Handling Functions

* **`const char* stm_err_to_name(stm_err_t ERROR_CODE)`**
  
  Returns a string representation of the error code for debugging or logging purposes.

* **`void STM_CHECK_ERROR(stm_err_t returned_valueFrom_function)`**
  
  Halts the program in an infinite loop if the error code is not `STM_OK`. Useful for debug checks during development.

* **`stm_err_t STM_CHECK_ERROR_WITHOUT_ABORT(stm_err_t returned_valueFrom_function)`**

  Returns the error code without halting the program. Allows non-blocking error checks.
  