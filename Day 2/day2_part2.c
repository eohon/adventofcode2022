#include <stdio.h>
#include <stdlib.h>

#define MAXC 1024

/* Same methodology as day2_part1.c but with different numbers
   within the switch statement */

int main(int argc, char** argv){
    char buff[MAXC];
    char outcome, his_hand;
    FILE *input;
    int total_points = 0;

    input = fopen("C:\\Users\\inle\\Desktop\\Advert of Code 2022\\Day 2\\cheat_sheet.txt", "r");
    if(input == NULL){
        printf("Error - file did not open\n");
        return 1;
    }

    while(fgets(buff, MAXC, input)){
        sscanf(buff, "%c %c", &his_hand, &outcome);
        switch(his_hand){
        case 'A': //rock
            if(outcome == 'X') //lose
                total_points += 3;
            else if(outcome == 'Y') //draw
                total_points += 4;
            else if(outcome == 'Z') //win
                total_points += 8;
            break;
        case 'B': //paper
            if(outcome == 'X') //lose
                total_points += 1;
            else if(outcome == 'Y') //draw
                total_points += 5;
            else if(outcome == 'Z') //win
                total_points += 9;
            break;
        case 'C': //scissors
            if(outcome == 'X') //lose
                total_points += 2;
            else if(outcome == 'Y') //draw
                total_points += 6;
            else if(outcome == 'Z') //win
                total_points += 7;
            break;
        }
    }
    printf("Total points won: %d", total_points);
    fclose(input);
}
