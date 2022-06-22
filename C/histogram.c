#include <string.h>
#include <stdio.h>

#define IN 1
#define OUT 0

int main(void){
    int c;      //letters in the word
    int l;      //for loop stepper
    int state;      //toggle between inside and outsode a word
    int count = 0;      //counter for the number of chars in a word
    int length[20];     //storage array for the words
    
    state = OUT;
    
    for(l = 0; l < 10; l++){
        length[l] = 0;
    }
    
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.'){      //checks for the end of word/end of line characters
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            length[count]++;
            count = 0;
            ++count;
        }
        else if(state == IN){
            ++count;
        }
    }

    /* Janky for loop that create the histogram*/

    printf("1-2: ");
    for(l = 1; l <= (length[1] + length[2]); l++){
        printf("X");
    }
    printf("\n");

    printf("3-4: ");
    for(l = 1; l <= (length[3] + length[4]); l++){
        printf("X");
    }
    printf("\n");

    printf("5-6: ");
    for(l = 1; l <= (length[5] + length[6]); l++){
        printf("X");
    }
    printf("\n");

    printf("7-8: ");
    for(l = 1; l <= (length[7] + length[8]); l++){
        printf("X");
    }
    printf("\n");

    printf("9-10: ");
    for(l = 1; l <= (length[9] + length[10]); l++){
        printf("X");
    }
    printf("\n");

    printf("11-12: ");
    for(l = 1; l <= (length[11] + length[12]); l++){
        printf("X");
    }
    printf("\n");

}