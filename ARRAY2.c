#include<stdio.h>
#include<stdint.h>
int main()
{
	uint8_t myNum[10] = {0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA} ;
    //WRITE A DATA
//	*(myNum+1)=0xFF; //second element in array [myNum[10] == *(myNum+1)]
	myNum[1] = 0xFF;
    for(uint32_t i=0;i<10;i++)
    {
    	//printf("%x \n", *(myNum+i));
    	printf("%x \n", myNum[i]);
    }
   	return 0;
}
