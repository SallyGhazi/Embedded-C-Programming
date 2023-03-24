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
	int num1,num2;
	printf("enter the first number :");
	fflush(stdout);
	scanf("%d",&num1);

	printf("enter the second number :");
	fflush(stdout);
	scanf("%d",&num2);

	if(num1==num2)
	{
		printf("Numbers are equal \n");
	}
	else
	{
		if(num1<num2)
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
