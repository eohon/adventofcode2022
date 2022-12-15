#include <stdio.h>
#include <stdlib.h>

#define MAXC 1024

int main(int argc, char** argv){
    FILE *input;

    char buff[MAXC];
    int left[2], right[2];
    int count = 0;

    input = fopen("C:\\Users\\inle\\Desktop\\Advert of Code 2022\\Day 4\\pairs.txt", "r");

    if(input == NULL){
        printf("ERROR - File did not open\n");
        return 1;
    }

    while(fgets(buff, MAXC, input)){
        sscanf(buff, "%d-%d,%d-%d", &left[0], &left[1], &right[0], &right[1]);
        //printf("Left[0] = %d\nLeft[1] = %d\nRight[0] = %d\nRight[1] = %d\n", left[0], left[1], right[0], right[1]);
        if(((left[0] <= right[0]) && (left[1] >= right[1])) || ((left[0] >= right[0]) && (left[1] <= right[1]))) count++;
    }

    printf("Count : %d", count);
    fclose(input);
}
