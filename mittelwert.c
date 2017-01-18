#include <stdio.h>
 int main(void) {
      int x;
      int z = 0;
      int mittelwert = 0;
      while(scanf("%i",&x)==1) {
          mittelwert = mittelwert + x;
          z++;
          }
      double a =1.0* mittelwert/z; 
      printf("%f\n",a);

 }