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
    char writerschar[20];
    writers = &writerschar[0];
    char *year;
    char yearchar[10];
    year = &yearchar[0];
    
    int i = 0;
    int j = 0;
    int k = 0;
    int g = 0;
    int y = 0;
    while (1){
        //Get a row into var from file f;
        //QUESTION: Will this all work properly since the first line has headers? Shouldn't we do something
        //to ignore the first line? Or at least handle it differently?
        fgets (var, 300, f);
        if (feof(f)){
            break;
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

        //Now that the string in conf is terminated and complete, we can perform string functions such as compare
        //against the string using the libary functions. This would NOT work if we had not terminated the string
        //with the "\0" as it would not be seen as a string, but still as just a character array.
        if (strcmp(conf, "ACC")== 0){
            printf("%s", var);
        }
        i++;

        //I left this in here, however there is no reason to continue incrementing the j variable now. We are done
        //manipulating the conference string, and j is related only to that string, so we don't need to do anything
        //more with j. Leaving it alone allows us to know that the string conf is length j.
        //j++;

        // SONG -------------------------------------------------------------------------------------------------------
        //Variable k will be our index reference for song, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the song array.
        k = 0;
        while (*(var + i) != ','){
            *(song + k) = *(var + i);
            i++;
            //j++; Don't do anything with j. It's not related to song in any way.
            k++;
        }
        
        *(song + k) = '\0';
        i++;
        //j++; Don't do anything with j. It's not related to song in any way.
        //k++; Don't do anything with k. Again, leaving it alone allows us to know that the string is length k.


        // WRITERS ----------------------------------------------------------------------------------------------------
        //Variable g will be our index reference for writers, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the writers array.
        g = 0;
        while (*(var + i) != ','){
            *(writers + g) = *(var + i);
            i++;
            //j++; Don't do anything with j. It's not related to writers in any way.
            //k++; Don't do anything with k. It's not related to writers in any way.
            g++;
        }

        *(writers + g) = '\0';
        i++;
        //j++; Don't do anything with j. It's not related to song in any way.
        //k++; Don't do anything with k. It's not related to song in any way.
        //g++; Don't do anything with g. Again, leaving it alone allows us to know that the string is length g.

        // YEAR ----------------------------------------------------------------------------------------------------___
        //Variable y will be our index reference for year, but i will continue to be our variable index for var.
        //We want to do the same thing - look through var characters until we find a comma. Again, the data should be
        //copied character by character into the yaer array.
        y = 0;
        while(*(var + i) != ','){
            *(year + y) = *(var + i);
            i++;
            //j++; Don't do anything with j. It's not related to year in any way.
            //k++; Don't do anything with k. It's not related to year in any way.
            //g++; Don't do anything with g. It's not related to year in any way.
            y++;
            
        }

        *(year + y) = '\0';

        //We are converting year to an integer. However, what happens if it's actually "Unknown"?
        //We should handle that case. What does the function return when the year is "Unknown"? Is it NULL, is
        //it zero? Experiment to learn what happens. Maybe rename your original file and only include a single
        //line of data.
        int x = atoi(year);

        //Right here at this point, we have the data in our school, conf, song, writers, and x variables.
        //This would be a good time to go through and figure out how to determine the output for the lowest
        //year would be.
        //NOTE: If we haven't handled the first line of headers, and the "Unknown" values, comparisons
        //probably won't work properly!
        printf("%s:", school);
        printf("%s: ", conf);
        printf("Song name is %s ", song);
        printf(" Written by %s ", writers);
        printf("Year of song is %d\n ", x);
        
    }
        fclose(f);
    return 0;
}
