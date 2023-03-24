#include<stdio.h>
/*
 * The fflush function in C is used to immediately flush out
 * the contents of an output stream.

 * This is particularly useful in displaying output,
 * as the operating system may initially put the output data
 * in a temporary buffer before writing it to
 * an output stream or file like stdout.
 *
 * */
int main()
{
	float num1,num2;
	int inum1,inum2;
	printf("enter the first number :");
	fflush(stdout);
	scanf("%f",&num1);

	printf("enter the second number :");
	fflush(stdout);
	scanf("%f",&num2);
	inum1= num1;
	inum2= num2;

	if((inum1 != num1) || (inum2 != num2)) printf("Warning -comparing only the integer part \n");

	if(inum1==inum2)
	{
		printf("Numbers are equal \n");
	}
	else
	{
		if(inum1<inum2)
		{
			printf("Num2 is Bigger");
		}
		else
		{
			printf("Num1 is Bigger");
		}

	}
	return 0;

}
