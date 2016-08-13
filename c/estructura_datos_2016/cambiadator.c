#include <stdio.h>

int main(){

  float temporal,a,b;
  
  printf("Ingresa dos numeros:\n");
  scanf("%f %f", &a, &b);
  printf("a=%f; b=%f\n", a,b);
  
  temporal=a;
  a=b;
  b=temporal;
  
  printf("Despues del cambiazo:\na=%f; b=%f\n", a,b);
  return 0;
}
