/*
 * Example.h
 *
 *  Created on: Oct 24, 2024
 *      Author: exp230017
 */

#ifndef INC_EXAMPLE_H_
#define INC_EXAMPLE_H_

/* Define BEGIN */

#define MAX_ARR_SIZE 128

/* Typedef BEGIN */

typedef enum
{
    Example_PASS = 0,
	Example_FAIL
} Example_STATE;

typedef struct
{
    uint8_t				DataSize;
    uint8_t   			TxData[MAX_ARR_SIZE];
	UART_HandleTypeDef*	Handle;
} Example_UART ;

typedef struct
{
	GPIO_TypeDef 		*Example_port;
	uint16_t 			Example_pin;
} Example_GPIO ;

typedef struct
{
	Example_UART		UART;
	Example_GPIO		GPIO;
} Example_Buffer ;

/* Prototypes BEGIN */

void Example_SET_UART_Handle(Example_Buffer* Handle,UART_HandleTypeDef *huart);
void Example(Example_Buffer *Handle);

#endif /* INC_EXAMPLE_H_ */
