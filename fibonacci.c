#include <stdio.h>

int main(void) {


}

int fibArray(int *res, int n) {
    *res = malloc(n*sizeof(int));
    for(int i = 0; i<n;i++){
        if(i == 0){
            res[i]=0;
        }else if(i==1){
            res[i]=1;
        }else {
            res[i]=res[i-2] + res[i-1];
        }
    }
    return res;
}