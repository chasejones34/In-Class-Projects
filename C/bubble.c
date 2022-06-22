#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int* xvec;  // x vector for swap
    int n;      // size of the aray
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    xvec = (int*)calloc(n, sizeof(int)); 
    
    srand(time(0));
    for(int i = 0; i < n; i++){
        xvec[i] = rand();
        printf("%d ", xvec[i]);
        
    }
    printf("%d ", RAND_MAX);
    return 0;
}