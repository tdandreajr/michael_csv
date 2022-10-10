#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Create a function that will scan through a file and find the earliest fight song.  HINTS: You can use atoi in the stdlib library to convert a string to a number.  Also - watch for songs that have an unknown year!

int main (){
    FILE *data_file;
    data_file = fopen("fight_songs.csv", "r");

    char *char_ptr;
    char file_line[301];
    char_ptr = &file_line[0];

    int iterator = 0;

    while (fgets (char_ptr, 300, data_file) != NULL ) {
        iterator++;
        printf("Line %d [%s]\n", iterator, char_ptr);
    }
    fclose(data_file);
    return 0;

}