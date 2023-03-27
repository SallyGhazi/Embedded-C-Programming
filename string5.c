#include <stdio.h>

int main()
{
    char msg[] = "Welcome All";
    char *pointerMsg = "Welcome All";
    msg[0] = 'A' ;
    pointerMsg[0] = 'A' ;

    printf("Address is %s \n",msg);
    printf("Address is %s \n",pointerMsg);
    printf("Address is %p \n",&msg);
    printf("Address is %p \n",&pointerMsg);
    printf("Address is %p \n",msg);
    printf("Address is %p \n",pointerMsg);
    return 0;
}
