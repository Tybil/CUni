#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool contains(char const *search, int searchSize, char const *input, int inputSize){
    bool a=false;
    for(int i = 0; i<inputSize;i++){
        for(int j =0;j<searchSize;j++){
            if(input[j+i]!=search[j]){
                a=false;
                break;
            }
            a=true;
        }
        if(a){
            return true;
        }   
    }
    return false;
}

int main(int argc, char *argv[]){
    char *s = malloc(1024*sizeof(char));
    int a = 1;
    while(fgets(s,1024,stdin)!=NULL){
        if(contains(argv[1],strlen(argv[1]),s,strlen(s))){
            printf("Der Suchtext wurde in Zeile %i gefunden!\n Zeile: %s",a,s);
        }
        a++;
    }
    free(s);
    return 0;
}