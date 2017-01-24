#include <stdio.h>
 int main(void) {
      int x;
      int z = 0;
      int summe = 0;
      while(scanf("%i",&x)!=-1) {
          summe = summe + x;
          z++;
          }
      double a =1.0* summe/z; 
      printf("%f\n",a);

 }