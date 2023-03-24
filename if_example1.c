#include<stdio.h>
int main()
{
	int age;
	printf("enter the age :");
	fflush(stdout);
	scanf("%d",&age);

	if(age<=18)
	{
		printf("not eligible to vote \n");
	}

	if(age>18)
	{
		printf(" Eligible to vote \n");
	}

	return 0;

}
