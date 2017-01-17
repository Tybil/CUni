#include <stdio.h>
 int main(void) {
      int x;
      int y=1;
      int z = 0;
      int mittelwert = 0;
      while(y!=0) {
          y = scanf("%i",&x);
          mittelwert = mittelwert + x;
          z++;
          }
      double a = mittelwert/z; 
      printf("%f",a);

 }