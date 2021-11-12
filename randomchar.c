#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE sizeof(unsigned char)
#define MINC 33
#define MAXC 126

int main(int argc,char** argv){

    FILE* f = fopen("/dev/random","r"); // File pointer

    char c;
    opterr = 0;
    unsigned int reps = 1;

    while((c = getopt(argc,argv,"c:")) != -1){
        switch(c){
            case 'c':
                reps = atoi(optarg);
                break;
            case '?':
                if(optopt == 'c'){
                    fprintf(stderr,"Option -%c required an argument.\n", optopt);
                } else {
                    fprintf(stderr,"Unknown option `-%c`.\n", optopt);
                }
                return 1;
            default:
                abort();
        }
    }

    unsigned char buffer[BUFFER_SIZE];
    unsigned char ch;

    for(unsigned int i = 0; i < reps; i++){
        fread(buffer, BUFFER_SIZE, 1, f);
        ch = MINC + buffer[0] % (MAXC+1 - MINC);
        printf("%c",ch);
    }

    fclose(f);

    return 0;

}