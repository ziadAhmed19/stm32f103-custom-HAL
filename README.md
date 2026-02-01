## Project Overview

**stm32f103-custom-HAL** is a modular firmware for the STM32F103C6/CT6 “Blue Pill” development board.
It provides a layered MCAL-style driver architecture, that include  **GPIO**, **USART**, **TIM2** and support a generic **error handling system (`stm_err_t`)**.

This firmware is structured using a **DIO (Digital Input/Output) layered approach**, allowing future expansion to peripherals such as timers, UART, and external interrupts.

---

##  Implemented Peripherals

### 1. GPIO (DIO Layer)


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
  