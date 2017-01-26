#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int number [] = {1, 2, 3, 4};
int *pointer [] = {& number [0], &number [1], &number [2], &number [3]};
int **p = pointer;
p = p + 1;
*p = *p + 1;
**p = **p + 1;

for (int i = 0; i < 4; i++)
{
printf("number [%d] = %d\n", i, number[i]);
}
}