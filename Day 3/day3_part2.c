#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 1024

int main(int argc, char** argv){
    FILE *input;
    char buff[MAXC];
    char buff_one[MAXC];
    char buff_two[MAXC];
    char buff_three[MAXC];
    int len_1 = 0;
    int len_2 = 0;
    int len_3 = 0;
    int count = 0;
    int group_counter = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int d = 0;
    int found = 0;
    char found_ch;
    char search;
    int priority_sum = 0;

    input = fopen("C:\\Users\\inle\\Desktop\\Advert of Code 2022\\Day 3\\backpack.txt", "r");

    if(input == NULL){
        printf("Error - file could not be opened\n");
        return 1;
    }

    while(fgets(buff, MAXC, input)){
            if(group_counter == 0){
                strcpy(buff_one, buff);
                len_1 = strlen(buff_one); }
            else if(group_counter == 1){
                strcpy(buff_two, buff);
                len_2 = strlen(buff_two); }
            else if(group_counter == 2){
                strcpy(buff_three, buff);
                len_3 = strlen(buff_three); }

        if((group_counter == 2)){
            group_counter = 0;
            for(j=0; j<len_1-1; j++){
                search = buff_one[j];
                for(k=0; k<len_2; k++){
                    if(search == buff_two[k]){
                        for(d=0; d<len_3; d++){
                            if(search == buff_three[d]){
                                found = 1;
                                found_ch = buff_three[d];
                            }
                        }
                    }
                }
            }
            printf("Common char : %c\n", found_ch);
            if(found_ch>=97 && found_ch<=122)
                priority_sum += (found_ch-96);
            else if(found_ch>=65 && found_ch<=90)
                priority_sum += (found_ch-38);
        }else group_counter++;
    }

    printf("\nPriority sum = %d\n", priority_sum);

    fclose(input);
}
