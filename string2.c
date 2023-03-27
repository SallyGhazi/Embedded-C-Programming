#include <stdio.h>
#include <string.h>

int main()
{
    char str[40];
    printf("Type The Name: ");
    fflush(stdout);
    scanf("%[^\n]s",str);
    printf("%s\n",str);
    return 0;
}
