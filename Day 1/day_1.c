#include <stdio.h>
#include <stdlib.h>

#define MAXC 1024

int main(int argc, char** argv){
    FILE *input;
    int max = 0;
    int temp_sum = 0;
    int temp_num;
    char buff[MAXC];
    int i;

    input = fopen("C:\\calories.txt", "r");

    if(input == NULL){
        printf("ERROR - File did not open");
        exit(1);
    }

    while(fgets(buff, MAXC, input)){
        if(buff[0] == '\n'){
            if(max < temp_sum)
                max = temp_sum;
            temp_sum = 0;
        }else{
            sscanf(buff, "%d", &temp_num);
            temp_sum += temp_num;
        }
    }

    printf("\nMax calories = %d\n", max);
    fclose(input);
}
