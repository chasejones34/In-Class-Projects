#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int swing;
int pitch;
int outs = 0;
int p1Runs = 0;
int p2Runs = 0;
bool first[2] = { false, true };    //runner on first
bool second[2] = { false, true };   //runner on second
bool third[2] = { false, true };    //runner on third
char input[25];
char single[25] = "single";
char multi[25] = "multi";
int p1Score = 0;
int p2Score = 0;
int inning;

void drawDiamond(int n){    //prints the view of the runners in the bases
    if(n == 0){
        printf("          .\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   .             .\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 1){
        printf("          .\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   .             0\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 2){
        printf("          0\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   .             .\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 3){
        printf("          .\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   0             .\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 4){
        printf("          0\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   .             0\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 5){
        printf("          .\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   0             0\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 6){
        printf("          0\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   0             .\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
    if(n == 7){
        printf("          0\n");
        printf("       .    .\n");
        printf("     .         .\n");
        printf("   0             0\n");
        printf("     .         .\n");
        printf("       .    .\n");
        printf("          .\n");
    }
}

int main(void){
    printf("Welcome to the Baseball Guessing Game!\n");
    printf("Do you want to play single or multiplayer?\nType \"single\" or \"multi\": ");
    scanf("%s", &input);
    int result = strcmp(single, input);
    
    if(result == 0){
      for(inning = 1; inning < 3; inning ++){
        first[2] = false;
        second[2] = false;
        third[2] = false;
            
        while(outs < 3){
            printf("Swing! (Enter an integer): ");
            scanf("%d", &swing);
            if(swing < 0 || swing > 100){
                printf("Enter a number between 0 and 100\n");
                printf("Swing! (Enter an integer): ");
                scanf("%d", &swing);
            }
            printf("Swing: %d\n", swing);
            
            srand(time(NULL));
            int random = rand() % 100 + 1;
            printf("Pitch: %d\n", random);
            int x = swing - random;
            int dif = abs(x);
            printf("Difference: %d\n", dif);

            if(dif <= 30 && dif > 20){  //Single
                printf("Single!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    third[2] = true;
                }
                if(first[2] == true){
                    first[2] = false;
                    second[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    first[2] = true;
                }
                first[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
 
            if(dif <= 20 && dif > 10){  //Double
                printf("Double!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = true;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    third[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    second[2] = true;
                }
                second[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                           
            if(dif <= 10 && dif > 5){   //Triple
                printf("Triple!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    third[2] = true;
                }
                third[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                
            if(dif <= 5 || dif == random){  //Home Run
                printf("Home Run!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                p1Runs++;
                drawDiamond(0);
            }
            if(dif > 40){      //Out
                printf("Out!\n");
                outs = outs + 1;
            }
            printf("Outs: %d\n", outs);
        }
        
        p1Score = p1Runs;
        printf("+--------------+\n");
        printf("Player 1: %d\n", p1Score);
        printf("Player 2: %d\n", p2Score);
        printf("+--------------+\n");
        printf("Switch Sides!\n");
        printf("Going to the bottom of %d\n", inning);
        printf("+--------------+\n");
        outs = 0;
        first[2] = false;
        second[2] = false;
        third[2] = false;
        
        while(outs < 3){
            
            printf("Pitch! (Enter an integer): ");  //Solo player is pitching now
            scanf("%d", &pitch);
            if(pitch < 0 || pitch > 100){
                printf("Enter a number between 0 and 100/n");
                printf("Pitch! (Enter an integer): ");
                scanf("%d", &pitch);
            }
            printf("Pitch: %d\n", pitch);

            srand(time(NULL));
            int random = rand() % 100 + 1;
            printf("Swing: %d\n", random);
            int dif = abs(pitch - random);
            printf("Difference: %d\n", dif);

            if(dif <= 30 && dif > 20){  //Single
                printf("Single!\n");
                if(third[2] == true){
                    third[2] = false;
                    p2Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    third[2] = true;
                }
                if(first[2] == true){
                    first[2] = false;
                    second[2] = true;
                }
                if(first[2] == false){
                    first[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    first[2] = true;
                }
                first[2] = true;
            
                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }

            if(dif <= 20 && dif > 10){  //Double
                printf("Double!\n");
                if(third[2] == true){
                    third[2] = false;
                    p2Runs++;
                }
                if(second[2] == true){
                    second[2] = true;
                    p2Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    third[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    second[2] = true;
                }
                second[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                
            if(dif <= 10 && dif > 5){   //Triple
                printf("Triple!\n");
                if(third[2] == true){
                    third[2] = false;
                    p2Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p2Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p2Runs++;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    third[2] = true;
                }
                third[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }

            if(dif <= 5 || dif == random){  //Home Run
                printf("Home Run!\n");
                if(third[2] == true){
                    third[2] = false;
                    p2Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p2Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p2Runs++;
                }
                p2Runs++;
                drawDiamond(0);
            }
            if(dif > 40){           //Out
                printf("Out!\n");
                outs = outs + 1;
            }
            /*Bottom of the inning*/
            printf("Outs: %d\n", outs);
        } 
        
        p2Score = p2Runs;
        printf("+--------------+\n");
        printf("Player 1: %d\n", p1Score);
        printf("Player 2: %d\n", p2Score);
        printf("+--------------+\n");
        printf("Switch Sides!\n");
        printf("Going to the top of %d\n", inning + 1);
        printf("+--------------+\n");
        outs = 0;
    }
  }
  if(p1Score > p2Score){
      printf("Ball Game!\nYou Win!");
  }
  else if(p1Score < p2Score){
      printf("Ball Game!\nYou Lose!");
  }
  else{
      printf("Its a Tie!");
  }

  /* +----------------Multiplayer------------------+ */
  result = strcmp(multi, input);    //Multiplayer
  if(result == 0){
    printf("+--------------+\n");
    printf("Player 1 will be the Home team\n");
    printf("Player 2 will be the Visiting team\n");
    printf("+--------------+\n");
    for(inning = 1; inning < 3; inning ++){
        first[2] = false;
        second[2] = false;
        third[2] = false;

        while(outs < 3){
            printf("Player 1, Pitch!: (Enter and Integer): ");
            scanf("%d", &pitch);
                if(pitch < 0 || pitch > 100){
                    printf("Enter a number between 0 and 100\n");
                    printf("Pitch! (Enter an integer): ");
                    scanf("%d", &pitch);
                }
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("Player 2, Swing!: (Enter and Integer): ");
            scanf("%d", &swing);
                if(swing < 0 || swing > 100){
                    printf("Enter a number between 0 and 100\n");
                    printf("Swing! (Enter an integer): ");
                    scanf("%d", &swing);
                }
            int dif = abs(swing - pitch);

            if(dif <= 30 && dif > 20){  //Single
                printf("Single!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    third[2] = true;
                }
                if(first[2] == true){
                    first[2] = false;
                    second[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    first[2] = true;
                }
                first[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
 
            if(dif <= 20 && dif > 10){  //Double
                printf("Double!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = true;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    third[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    second[2] = true;
                }
                second[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                           
            if(dif <= 10 && dif > 5){   //Triple
                printf("Triple!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    third[2] = true;
                }
                third[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                
            if(dif <= 5 || dif == pitch){  //Home Run
                printf("Home Run!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                p1Runs++;
                drawDiamond(0);
            }
            if(dif > 40){      //Out
                printf("Out!\n");
                outs = outs + 1;
            }
            printf("Outs: %d\n", outs);
        }
        
        p1Score = p1Runs;
        printf("+--------------+\n");
        printf("Player 1: %d\n", p1Score);
        printf("Player 2: %d\n", p2Score);
        printf("+--------------+\n");
        printf("Switch Sides!\n");
        printf("Going to the bottom of %d\n", inning);
        printf("+--------------+\n");
        outs = 0;
        first[2] = false;
        second[2] = false;
        third[2] = false;
        
    
    while(outs < 3){
            printf("Player 2, Pitch!: (Enter and Integer): ");
            scanf("%d", &pitch);
                if(pitch < 0 || pitch > 100){
                    printf("Enter a number between 0 and 100\n");
                    printf("Pitch! (Enter an integer): ");
                    scanf("%d", &pitch);
                }
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("Player 1, Swing!: (Enter and Integer)");
            scanf("%d", &swing);
                if(swing < 0 || swing > 100){
                    printf("Enter a number between 0 and 100");
                    printf("Swing! (Enter an integer): ");
                    scanf("%d", &swing);
                }
            int dif = abs(swing - pitch);

            if(dif <= 30 && dif > 20){  //Single
                printf("Single!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    third[2] = true;
                }
                if(first[2] == true){
                    first[2] = false;
                    second[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    first[2] = true;
                }
                first[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
 
            if(dif <= 20 && dif > 10){  //Double
                printf("Double!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = true;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    third[2] = true;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    second[2] = true;
                }
                second[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                           
            if(dif <= 10 && dif > 5){   //Triple
                printf("Triple!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                if(first[2] == false && second[2] == false && third[2] == false){
                    third[2] = true;
                }
                third[2] = true;

                /* Determining what diamond to draw */
                if(first[2] == false && second[2] == false && third[2] == false){
                    drawDiamond(0);
                }
                else if(first[2] == true && second[2] == false && third[2] == false){
                    drawDiamond(1);
                }
                else if(first[2] == false && second[2] == true && third[2] == false){
                    drawDiamond(2);
                }
                else if(first[2] == false && second[2] == false && third[2] == true){
                    drawDiamond(3);
                }
                else if(first[2] == true && second[2] == true && third[2] == false){
                    drawDiamond(4);
                }
                else if(first[2] == true && second[2] == false && third[2] == true){
                    drawDiamond(5);
                }
                else if(first[2] == false && second[2] == true && third[2] == true){
                    drawDiamond(6);
                }
                else if(first[2] == true && second[2] == true && third[2] == true){
                    drawDiamond(7);
                }
            }
                
            if(dif <= 5 || dif == pitch){  //Home Run
                printf("Home Run!\n");
                if(third[2] == true){
                    third[2] = false;
                    p1Runs++;
                }
                if(second[2] == true){
                    second[2] = false;
                    p1Runs++;
                }
                if(first[2] == true){
                    first[2] = false;
                    p1Runs++;
                }
                p1Runs++;
                drawDiamond(0);
            }
            if(dif > 40){      //Out
                printf("Out!\n");
                outs = outs + 1;
            }
            printf("Outs: %d\n", outs);
        }
        
        p2Score = p2Runs;
        printf("+--------------+\n");
        printf("Player 1: %d\n", p1Score);
        printf("Player 2: %d\n", p2Score);
        printf("+--------------+\n");
        printf("Switch Sides!\n");
        printf("Going to the bottom of %d\n", inning);
        printf("+--------------+\n");
        outs = 0;
        first[2] = false;
        second[2] = false;
        third[2] = false;

        }
    
    }
    if(p1Score > p2Score){
      printf("Ball Game!\nPlayer 1 Wins!");
    }
    else if(p1Score < p2Score){
      printf("Ball Game!\nPlayer 2 Wins!");
    }
    else{
        printf("Its a Tie!");
    }
}
  
