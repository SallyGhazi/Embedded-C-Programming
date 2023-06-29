#include <stdint.h>
#include <stdio.h>

#define GPIOAEN        (1U<<0)
#define UART2EN        (1U<<17)

#define UART2_IRQN0     38

#define SYS_FREQ       16000000
#define APB1_CLK       SYS_FREQ
#define UART_BAUDRATE  9600
/*======================================================================*/
//initialize the pointers for the registers
uint32_t *portaAHB1ENR = (uint32_t*)0x40023830; //RCC registers
uint32_t *APB1ENR      = (uint32_t*)0x40023840; //APB bus peripherals
uint32_t *GPIOA_MODER  = (uint32_t*)0x40020000; //configure the GPIO a mode for the alternate function
uint32_t *GPIOA_AFRL   = (uint32_t*)0x40020020;
uint32_t *USART2_SR    = (uint32_t*)0x40004400;
uint32_t *USART2_DR    = (uint32_t*)0x40004404;
uint32_t *USART2_BRR   = (uint32_t*)0x40004408;
uint32_t *USART2_CR1   = (uint32_t*)0x4000440C;

/*======================================================================*/
/* Enable AHB1 for GPIOC -------------------------------------------*/
uint32_t volatile *pAHB1ENR     = (uint32_t*)0x40023830; //RCC registers

/* Enable APB2 for EXIT -------------------------------------------*/
uint32_t volatile *APB2ENR      = (uint32_t*)0x40023844; //APB2 bus peripherals

/* GPIOC -------------------------*/
uint32_t volatile *pGPIOC      = (uint32_t*)0x40020800;

/* Pending register -------------------------------------------*/
uint32_t volatile *pEXTI_PR      = (uint32_t*)0x40013c14;

/* Interrupt mask register ------------------------------------*/
uint32_t volatile *pEXTI_IMR      = (uint32_t*)0x40013c00;

/* Falling Trigger selection register -------------------------*/
uint32_t volatile *pEXTI_FTSR    = (uint32_t*)0x40013c0c;

/* SYSCFG external interrupt configuration register 4 -------------------------*/
uint32_t volatile *pSYSCFG_EXTICR4    = (uint32_t*)0x40013814;

/* Interrupt Set-Enable Register -------------------------*/
uint32_t volatile *pNVIC_ISER1    = (uint32_t*)0xe000e104;

/*======================================================================*/
void uart2_tx_init(void);
static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t Baudrate);
void uart2_write(char ch);

int __io_putchar(char ch)
{
	uart2_write(ch);
	return ch;
}
void Button_Init(void)
{
	*pAHB1ENR |= (1U << 2);
	*APB2ENR  |= (1U << 14);
	*pSYSCFG_EXTICR4 |= (1U << 5); //pc13
	*pEXTI_FTSR |= (1U << 13);
	*pEXTI_IMR |= (1U << 13);
	*pNVIC_ISER1 |= (1U << 8);
}

int main(void)
{
	uart2_tx_init();
	Button_Init();
	printf("Enter the Loop \r\n");

	while(1)
	{
	}
	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	printf("Button is Pressed \r\n");
	*pEXTI_PR |= (1U << 13);

}

void uart2_tx_init(void)
{
	//Enable clock access to GPIOA
	*portaAHB1ENR = GPIOAEN;

	//Enable Clock Access for USART2
	*APB1ENR |= (1U<<17);

	//SET PA2 MOODE TO Alternate function Mode
	*GPIOA_MODER |=  (1U<<5);
	*GPIOA_MODER  &=~ (1U<<4);
	//SET PA2 Alternative function type to UART_TX (AF07)
	*GPIOA_AFRL |= (1U<<8);
	*GPIOA_AFRL |= (1U<<9);
	*GPIOA_AFRL |= (1U<<10);
	*GPIOA_AFRL &=~ (1U<<11);
	//CONFIGURE UART MODULE
	*APB1ENR |= UART2EN ;
	*USART2_BRR = compute_uart_bd(APB1_CLK, UART_BAUDRATE);

	//CONFIGURE TRANSFER DIRECTION
	*USART2_CR1 = 0X0008;
	*USART2_CR1 |= 0X2000;
}

static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t Baudrate)
{
	return((PeriphClk+(Baudrate/2U))/Baudrate);
}
void uart2_write(char ch)
{
	//Make sure the transmit data register is empty
	while(!(*USART2_SR & 0x0080)){}
	//write to transmit data register
	*USART2_DR = (ch & 0XFF);

}
