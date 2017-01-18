#include <stdio.h>
#include <stdlib.h>
void fibArray(int *res, int n) {
    for(int i = 0; i<n;i++){
        if(i == 0){
            res[i]=0;
        }else if(i==1){
            res[i]=1;
        }else {
            res[i]=res[i-2] + res[i-1];
        }
    }
}

int main(void) {
    int n;
    scanf("%i",&n);
    int *res = malloc(n*sizeof(int));
    fibArray(res,n);
    for(int i =0;i<n;i++){
        printf("%d",res[i]);
    }

}