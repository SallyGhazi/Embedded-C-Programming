#include <stdio.h>
#include <string.h>

int main()
{
    char str[]="Hello World";
    int len1 = sizeof(str);
    int len2 = strlen(str);
    printf("len1 = %d\n",len1);
    printf("len2 = %d\n",len2);

    printf("Welcome All\n");
    printf("%s\n",str);

    return 0;
}
