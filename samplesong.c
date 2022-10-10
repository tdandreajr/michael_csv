#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Create a function that will scan through a file and find the earliest fight song.  HINTS: You can use atoi in the stdlib library to convert a string to a number.  Also - watch for songs that have an unknown year!

int main (){
    FILE *f;
    f = fopen("fight_songs.csv", "r");
    FILE *f2;
    f2 = fopen("fight_songs2.csv", "w");
    FILE *f3;
    f3 = fopen ("ACC_schools.csv", "w");
    FILE *f4;
    f4 = fopen ("song_name.csv", "w");
    FILE *f5;
    f5 = fopen("writers.csv", "w");
    FILE *f6;
    f6 = fopen("year.csv", "w");
    
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
        //fscanf(f, "%s", var);
        fgets (var, 300, f);
        if (feof(f)){
            break;
        }
        //fprintf(f2, "%s", var);
        i = 0;
        while (*(var + i) != ','){
            // printf("%c", *(var + i));
            *(school + i) = *(var + i);
            i++;
        }
        *(school + i) = '\0';
        i++;
        j = 0;
        while (*(var + i) != ','){
            *(conf + j) = *(var + i);
            i++;
            j++;
        }
        //*(school + i) = '\0';
        *(conf + j) = '\0';
        //printf("%s:", school);
        // printf("%s\n", conf);
        if (strcmp(conf, "ACC")== 0){
            fprintf(f3, "%s", var);
        }
        i++;
        j++;
        k = 0;
        while (*(var + i) != ','){
            *(song + k) = *(var + i);
            i++;
            j++;
            k++;
            // printf("\n");
        }
        
        *(song + k) = '\0';
        i++;
        j++;
        k++;
        g = 0;
        while (*(var + i) != ','){
            *(writers + g) = *(var + i);
            i++;
            j++;
            k++;
            g++;
        }
        *(writers + g) = '\0';
        i++;
        j++;
        k++;
        g++;
        y = 0;
        while(*(var + i) != ','){
            *(year + y) = *(var + i);
            i++;
            j++;
            k++;
            g++;
            y++;
            
        }
        *(year + y) = '\0';
        int x = atoi(year);
        printf("%s:", school);
        printf("%s: ", conf);
        printf("Song name is %s ", song);
        printf(" Written by %s ", writers);
        printf("Year of song is %d\n ", x);
        fprintf(f6, "%s", var);
        
    }
        fclose(f);
        fclose(f2);
        fclose(f3);
        fclose(f4);
        fclose(f5);
        fclose(f6);
    return 0;
}
