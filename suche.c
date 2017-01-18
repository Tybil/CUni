#include <stdbool.h>

bool contains(char const *search, int searchSize, char const *input, int inputSize){
    bool a=false;
    for(int i = 0; i<inputSize;i++){
        if(input[i]==search[0]){
            for(int j =1;j<searchSize;j++){
                if(input[j+i]==search[j]){
                    bool a = true;
                } else {
                    a=false;
                    break;
                }
            }
            if(a){
                return true;
            }
        }
    }
    return false;
}

int main(void){
    //TODO
    return 0;
}