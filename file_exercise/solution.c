#include <stdio.h>
#include <stdlib.h>


void file_write(char *file_name ,char *text[100] , int text_size) {
    FILE * fp;
    char counter = 'a';
    fp = fopen(file_name,"w");
    for(int i=0;i<text_size;i++) {
        if(text[i][0] >='0' && text[i][0] <='9') continue;
        fprintf(fp,"%c.%s\n",counter++,text[i]);
    }
}




int main() {
    char **text = (char**)malloc(4*sizeof(char*));
    text[0] = (char*)calloc(18,sizeof(char));
    sprintf(text[0],"Gooli 31, Bat Yam");

    text[1] = (char*)calloc(9,sizeof(char));
    sprintf(text[1],"22 Slomo");
    text[2] = (char*)calloc(5,sizeof(char));
    sprintf(text[2],"Levi");
    text[3] = (char*)calloc(6,sizeof(char));
    sprintf(text[3],"Shosh");


    int size = 4;
    file_write("output.txt",text,size);
}