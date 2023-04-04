/*
 * uart.h
 *
 *  Created on: Apr 5, 2023
 *      Author: juju1
 */
#include <stdint.h>
#include <stdio.h>

#ifndef UART_H_
#define UART_H_

#define GPIOAEN        (1U<<0)
#define UART2EN        (1U<<17)

#define SYS_FREQ       16000000
#define APB1_CLK       SYS_FREQ
#define UART_BAUDRATE  115200

void uart2_tx_init(void);
static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t Baudrate);
void uart2_write(int ch);
int __io_putchar(int ch);
#endif /* UART_H_ */
