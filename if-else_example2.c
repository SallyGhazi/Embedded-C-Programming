#include<stdio.h>

int main()
{
	float num1,num2;
	int inum1,inum2;
	printf("enter the first number :");
	fflush(stdout);
	if(scanf("%f",&num1)==0)
	{
		printf("Invalid input ...exiting");
		return 0;
	}

	printf("enter the second number :");
	fflush(stdout);
	if(scanf("%f",&num2)==0)
	{
		printf("Invalid input ...exiting");
		return 0;
	}

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
