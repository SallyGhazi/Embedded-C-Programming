#include <stdint.h>
#include <stdio.h>
#include "uart.h"


int main(void)
{
	//ENABLE UART MODULE
	uart2_tx_init();
	while(1)
	{
	//	uart2_write('A');
		printf("hello world-Example \r\n");
	}

}
