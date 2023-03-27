#include <stdio.h>

void displayString(char data[]);
int main()
{
    char str[] = "Welcome All";
    displayString(str);
    return 0;
}
void displayString(char data[])
{
	printf("String Output\n");
	fflush(stdout);
	puts(data);

}
