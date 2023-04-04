#include <stdint.h>
#include <stdio.h>

#define GPIOAEN        (1U<<0)
#define UART2EN        (1U<<17)

#define SYS_FREQ       16000000
#define APB1_CLK       SYS_FREQ
#define UART_BAUDRATE  115200

uint32_t *portaAHB1ENR = (uint32_t*)0x40023830;
uint32_t *APB1ENR      = (uint32_t*)0x40023840;
uint32_t *GPIOA_MODER  = (uint32_t*)0x40020000;
uint32_t *GPIOA_AFRL   = (uint32_t*)0x40020020;
uint32_t *USART2_SR    = (uint32_t*)0x40024400;
uint32_t *USART2_DR    = (uint32_t*)0x40024404;
uint32_t *USART2_BRR   = (uint32_t*)0x40024408;
uint32_t *USART2_CR1   = (uint32_t*)0x4002440C;

void uart2_tx_init(void);
static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t Baudrate);

int main(void)
{
	//ENABLE CLOCK ACCESS TO UART2

	//CONFIGURE BAUDRATE

	//CONFIGURE TRANSFER DIRECTION

	//ENABLE UART MODULE
	uart2_tx_init();

}
void uart2_tx_init(void)
{
	//Enable clock access to GPIOA
	*portaAHB1ENR = GPIOAEN;
	//SET PA2 MOODE TO Alternate function Mode
	*GPIOA_MODER  &=~ (1U<<4);
	//SET PA2 Alternative function type to UART_TX (AF07)
	*GPIOA_AFRL |= (1U<<8);
	*GPIOA_AFRL |= (1U<<9);
	*GPIOA_AFRL |= (1U<<10);
	*GPIOA_AFRL &=~ (1U<<11);
	//CONFIGURE UART MODULE
	*APB1ENR |= UART2EN ;
	*USART2_BRR = compute_uart_bd(APB1_CLK, UART_BAUDRATE);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t Baudrate)
{
	return((PeriphClk+(Baudrate/2U))/Baudrate);
}
