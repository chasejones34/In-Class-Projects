#include <string.h>
#include <stdio.h>

#define MAXLENGTH 1000

int main(void){
    char name[MAXLENGTH];
    
    printf("What is your name? ");
    scanf("%s", &name);
    printf("My name is %d characters\n", strlen(name));
    
}