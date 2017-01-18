#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *input = malloc(8*sizeof(int));
    int a = 8;
    int x;
    int z=0;
    while(scanf("%i",&x)==1) {
        if(z>=a){
            a = a+8;
            input = realloc(input,a*sizeof(int));
        }
        input[z]=x;
        z++;
    }
    for(int i = z-1;i>=0;i--){
        printf("%i\n",input[i]);
    }
    free(input);
}