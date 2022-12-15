#include <stdio.h>
#include <stdlib.h>

#define MAXC 1024
#define HALF_MAXC 512

int main(int argc, char** argv){
    FILE *input;
    char buff[MAXC];
    char buff_left[HALF_MAXC];
    char buff_right[HALF_MAXC];
    int half_way;
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int found = 0;
    int found_pos;
    char found_ch;
    char search;
    int priority_sum = 0;

    input = fopen("C:\\Users\\inle\\Desktop\\Advert of Code 2022\\Day 3\\backpack.txt", "r");

    if(input == NULL){
        printf("Error - file could not be opened\n");
        return 1;
    }

    while(fgets(buff, MAXC, input)){
        i = 0;
        count = 0;
        while(buff[i] != '\0'){
            count++;
            i++;
        }
        half_way = count / 2;
        for(j = 0; j<count; j++){
            if(j < half_way)
                buff_left[j] = buff[j];
            else if(j >= half_way)
                buff_right[j-half_way] = buff[j];
        }

        for(i = 0; i<half_way; i++){
            search = buff_left[i];
            for(k = 0; k<half_way; k++){
                if(search == buff_right[k]){
                    found = 1;
                    found_ch = buff_right[k];
                    found_pos = k;
                }
            }
        }

        if(found_ch>=97 && found_ch<=122)
            priority_sum += (found_ch-96);
        else if(found_ch>=65 && found_ch<=90)
            priority_sum += (found_ch-38);
    }

    printf("\nPriority sum = %d\n", priority_sum);

    fclose(input);
}
