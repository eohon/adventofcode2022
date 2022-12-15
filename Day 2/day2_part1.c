#include <stdio.h>
#include <stdlib.h>

#define MAXC 1024

int main(int argc, char** argv){
    char buff[MAXC];
    char my_hand, his_hand; /* rock, paper, scissors for me and my enemy */
    FILE *input;
    int total_points = 0;

    input = fopen("C:\\cheat_sheet.txt", "r");
    if(input == NULL){
        printf("Error - file did not open\n");
        return 1;
    }

    /* Get mine and my opponent's hand and save into variables my_hand and his_hand.
       Use switch statement and if clauses to calculate  total_points, according to
       the specifications given by Advent of Code 2022 */
    while(fgets(buff, MAXC, input)){
        sscanf(buff, "%c %c", &his_hand, &my_hand);
        switch(his_hand){
        case 'A': //rock
            if(my_hand == 'X') //rock
                total_points += 4;
            else if(my_hand == 'Y') //paper
                total_points += 8;
            else if(my_hand == 'Z') //scissors
                total_points +=  3;
            break;
        case 'B': //paper
            if(my_hand == 'X') //rock
                total_points += 1;
            else if(my_hand == 'Y') //paper
                total_points += 5;
            else if(my_hand == 'Z') //scissors
                total_points += 9;
            break;
        case 'C': //scissors
            if(my_hand == 'X') //rock
                total_points += 7;
            else if(my_hand == 'Y') //paper
                total_points += 2;
            else if(my_hand == 'Z') //scissors
                total_points += 6;
            break;
        }
    }
    printf("Total points won: %d", total_points);
    fclose(input);
}
