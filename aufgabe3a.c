#include <stdio.h>

int main(void)
{
int ar[] = {200 , 30, 4, 1000};
int *p = &ar [0];
int *q = &ar [3];
int r = 0;
while (p < q)
{
 r = r + *p + *q;
 p = p + 1;
 q = q - 1;
 }
 printf("r = %d\n", r);
 }