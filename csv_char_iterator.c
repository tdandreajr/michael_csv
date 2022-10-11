#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Create a function that will scan through a file and find the earliest fight song.  HINTS: You can use atoi in the stdlib library to convert a string to a number.  Also - watch for songs that have an unknown year!

int main (){
    FILE *data_file;
    data_file = fopen("fight_songs.csv", "r");

    char *char_ptr;
    char file_line[301];
    char temp_file_line[301];
    char lowest_year_str[301];
    char_ptr = &file_line[0];

    const char s[2] = ",";
    char *token;
    int lowest_year = 2022;
    int lowest_year_row_num = 0;

    int row_num = 0;
    while (fgets (char_ptr, 300, data_file) != NULL ) {
        row_num++;
        if (row_num == 1) {
            continue;
        }
        strcpy(temp_file_line, file_line);
        token = strtok(file_line, s); //Get first token - School
        token = strtok(NULL, s); //Get second token - Conference
        token = strtok(NULL, s); //Get third token - Song
        token = strtok(NULL, s); //Get fourth token - Writer
        token = strtok(NULL, s); //Get fifth token - Year
        if (strcmp(token,  "Unknown") == 0 )  {
            continue;
        }

        int token_val;
        token_val = atoi(token);
        if (token_val < lowest_year) {
            lowest_year = token_val;
            lowest_year_row_num = row_num;
            strcpy(lowest_year_str, temp_file_line);
        }

        //printf( "Current lowest value [%d] line [%d]\n", lowest_year, lowest_year_row_num);
    }
    printf("Lowest line: %s", lowest_year_str);

    fclose(data_file);
    return 0;

}