#include <stdio.h>
#include <stdbool.h>

void swap2(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool sort2(int *x, int *y)
{
    // Aufgabe a)
    if(*x>*y){
        swap2(x,y);
        return true;
    }
    return false;
}

void sort(int ar[], int size)
{
    // Aufgabe b)
    bool a;
    bool b =true;
    while(b){
        b=false;
        for(int i = 0;i<size-1;i++){
            a= sort2(&ar[i],&ar[i+1]);
            if(a){
                b=true;
            }
        }
        size--;
        if(size<=1){
            b=false;
        }
    }
}

int main(void)
{
    {
        int x = 4;
        int y = 7;
        swap2(&x, &y);
        printf("x = %d, y = %d\n", x, y); // Erwartete Ausgabe: x = 4, y = 7
    }

    {
        int a = 7;
        int b = 4;
        bool r1 = sort2(&a, &b);
        printf("a = %d, b = %d, r1 = %d\n", a, b, r1); // Erwartete Ausgabe: a = 4, b = 7, r1 = 1
    }

    {
        int x = 3;
        int y = 5;
        bool r2 = sort2(&x, &y);
        printf("x = %d, y = %d, r2 = %d\n", x, y, r2); // Erwartete Ausgabe: x = 3, y = 5, r2 = 0
    }

    {
        int ar[] = {5,4,3,2,1};
        int ar_size = sizeof(ar) / sizeof(int);
        sort(ar, ar_size);
        for (int i=0; i<ar_size; i++) {
            printf("ar[%d] = %d\n", i, ar[i]);
        }
    }
}
