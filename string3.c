#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[40];
    printf("Enter The Name: ");
    fflush(stdout);
    fgets(str,sizeof(str),stdin);   // read string
    printf("Name: ");
    puts(str); // display string
    return 0;
}
