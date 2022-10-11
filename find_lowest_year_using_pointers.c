#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Create a function that will scan through a file and find the earliest fight song.  HINTS: You can use atoi in the stdlib library to convert a string to a number.  Also - watch for songs that have an unknown year!

int main (){
    FILE *f;
    f = fopen("fight_songs.csv", "r");
    
    char *var;
    char varchar[301];
    var = &varchar[0];
    char *school;
    char schoolchar[20];
    school = &schoolchar[0];
    char *conf;
    char confchar[20];
    conf = &confchar[0];
    char *song;
    char songchar[50];
    song = &songchar[0];
    char *writers;
    char writerschar[50];
    writers = &writerschar[0];
    char *year;
    char yearchar[10];
    year = &yearchar[0];

    int current_row_num = 0;
    int lowest_year = 9999;
    char lowest_year_school[20];
    char lowest_year_conf[20];
    char lowest_year_song[50];
    char lowest_year_writer[50];
    
    int i = 0;
    int j = 0;
    int k = 0;
    int g = 0;
    int y = 0;

    while (fgets (var, 300, f) != NULL ) {
        current_row_num++;
        if (current_row_num == 0){
            continue;
        }
        // SCHOOL -----------------------------------------------------------------------------------------------------
        //Variable i will be our index reference for both school and var array index.
        //We want to look through var characters until we find a comma. That data should be copied character
        //by character into the school array. Discontinue the while once we reach a comma.
        i = 0;
        while (*(var + i) != ','){
            //This copies the value at the index i referenced by var to the value at the index i referenced by school.
            *(school + i) = *(var + i);
            i++;
        }
        //A string is terminated with the null char, so we need to do this manually. Because we already incremented
        //the i variable in the previous loop, we can just set the school index at i to null char, terminating the 
        //string.
        *(school + i) = '\0';



        // CONFERENCE -------------------------------------------------------------------------------------------------
        //Variable j will be our index reference for conference, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the conf array.

        //We first must increment i to get past the comma. We initialize j to zero since we are at the beginning of
        //the conf array.
        i++;
        j = 0;
        //Continue to use the i variable to look through the var array after the previous comma. Discontinue the
        //while once we reach a comma. 
        while (*(var + i) != ','){
            //This copies the value at the index i referenced by var to the value at the index j referenced by conf.
            *(conf + j) = *(var + i);
            //We have to now increment both i and j separately because they are different locations in different
            //char strings.
            i++;
            j++;
        }

        //A string is terminated with the null char, so we need to do this manually. Because we already incremented
        //the j variable in the previous loop, we can just set the conf index at j to null char, terminating the 
        //string.
        *(conf + j) = '\0';



        // SONG -------------------------------------------------------------------------------------------------------
        //Variable k will be our index reference for song, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the song array.
        i++;
        k = 0;
        while (*(var + i) != ','){
            *(song + k) = *(var + i);
            i++;
            k++;
        }
        
        *(song + k) = '\0';



        // WRITERS ----------------------------------------------------------------------------------------------------
        //Variable g will be our index reference for writers, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the writers array.
        i++;
        g = 0;
        while (*(var + i) != ','){
            *(writers + g) = *(var + i);
            i++;
            g++;
        }

        *(writers + g) = '\0';


        // YEAR ----------------------------------------------------------------------------------------------------___
        //Variable y will be our index reference for year, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the year array.
        i++;
        y = 0;
        while(*(var + i) != ','){
            *(year + y) = *(var + i);
            i++;
            y++;
            
        }

        *(year + y) = '\0';

        //We are converting year to an integer. However, what happens if it's actually "Unknown"?
        //We should handle that case.
        int x = atoi(year);

        //Right here at this point, we have the data in our school, conf, song, writers, and x variables.
        //This would be a good time to go through and figure out how to determine the output for the lowest
        //year would be.
        if (x > 0 && x < lowest_year) {
            lowest_year = x;
            strcpy(lowest_year_school, school);
            strcpy(lowest_year_conf, conf);
            strcpy(lowest_year_song, song);
            strcpy(lowest_year_writer, writers);
        }
        printf("School: [%d] [%s]\n", current_row_num, school);
    }
    fclose(f);


    //Now outside of the loop, we should have copies of the actual data referencing the lowest year.
    //We can do whatever we want with it now!
    printf("The data from the earliest year is:\n");
    printf("School: [%s]\n", lowest_year_school);
    printf("Conference: [%s]\n", lowest_year_conf);
    printf("The song name is [%s]\n", lowest_year_song);
    printf("Written by [%s]\n", lowest_year_writer);
    printf("Year of song is [%d]\n", lowest_year);
    return 0;
}
