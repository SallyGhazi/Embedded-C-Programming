#include<stdio.h>
#include<stdint.h>

int main()
{
	int len = 5;
    uint8_t myNum[len] ;
    for(uint32_t i=0;i<len;i++)
    {
    	myNum[i]= i+5;
    }

    uint32_t totalSize = sizeof(myNum)/sizeof(uint8_t) ;
    printf("Array size is = %d \n",totalSize);

    //to print the all array elements
    for(uint32_t i=0;i<totalSize;i++)
    {
    	printf("Array element[%d] = %d \n",i,myNum[i]);
    }
	return 0;
}
