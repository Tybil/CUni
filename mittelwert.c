#include <stdio.h>
 int main(void) {
      int x;
      int y=1;
      int z = 0;
      int mittelwert = 0;
      while(scanf("%i",&x)==1) {
          mittelwert = mittelwert + x;
          z++;
          }
      double a = mittelwert/z; 
      printf("%f",a);

 }