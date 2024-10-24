/*
 * Example.c
 *
 *  Created on: Oct 24, 2024
 *      Author: exp230017
 */

#include "usart.h"
#include "Example.h"

//#warning Program running in example mode

#define UART_HANDLE Handle->UART
#define UART_TX Handle->UART.TxData
#define UART_Size Handle->UART.DataSize

#define Console(x) Example_Console(&UART_HANDLE,x)

/* Global Variables BEGIN */

/* Private Functions BEGIN */

Example_STATE Example_Console(Example_UART *Handle, char *MSG);

void Example_SET_UART_Handle(Example_Buffer *Handle, UART_HandleTypeDef *huart) {
	Handle->UART.Handle = huart;
}

void Example(Example_Buffer *Handle){

	Example_Console(Handle,"Message from device");
}

Example_STATE Example_Console(Example_UART *Handle, char *MSG) {
	Handle->DataSize = 0;

	do {
		Handle->TxData[Handle->DataSize] = MSG[Handle->DataSize];
		if (Handle->DataSize >= MAX_ARR_SIZE) return Example_FAIL;
	}
	while (MSG[Handle->DataSize++]);

	if (HAL_UART_Transmit(Handle->Handle, Handle->TxData, Handle->DataSize, 0x0F)) return Example_FAIL;

	if (HAL_UART_Transmit(Handle->Handle, (const uint8_t*) "\n\r", 2, 0x0F)) return Example_FAIL;

	return Example_PASS;
}
