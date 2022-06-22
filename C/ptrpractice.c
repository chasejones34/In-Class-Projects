#include <stdio.h>

int practice(){
    long value1 = 200000;
    long value2;
    
    long *ptr = &value1;
    printf("%d\n", *ptr);

    value2 = *ptr;

    printf("%d\n", value2);
    printf("%x\n", &value1);
    printf("%x\n", ptr);

    return(0);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main(){
    printf(":Practice:\n");
    practice();
    printf("\n");
    
    printf(":Swap Method:\n");
    int x = 4;
    int y = 7;

    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);
}