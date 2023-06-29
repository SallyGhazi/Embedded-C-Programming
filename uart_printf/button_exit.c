#include <stdint.h>
#include <stdio.h>

#define GPIOAEN        (1U<<0)
#define UART2EN        (1U<<17)

#define UART2_IRQN0     38

#define SYS_FREQ       16000000
#define APB1_CLK       SYS_FREQ
#define UART_BAUDRATE  115200

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

