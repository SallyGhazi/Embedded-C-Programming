#include<stdio.h>
#include<stdint.h>



int main()
{

	const uint8_t data = 10;
	uint8_t *ptrData;
	printf("Before = %d \n",data);
	ptrData = &data;
	*ptrData = 50;
//	data = 50;  //syntax error
	printf("After = %d \n",data);

	return 0;

}
