#include <stdio.h>

int main(){

  int i=0,numero, es_par,cuenta_pares=0, cuenta_impares=0;
  
  printf("Ingrese diez numeros que pertenescan al conjunto de los numeros naturales:\n");
  for(i=0; i<10; i++) {
    
    scanf("%d", &numero);
  
    es_par = numero%2==0;
  
    if (es_par) {
      cuenta_pares++;
    } else {
      cuenta_impares++;
    }
  }
  printf("%d son impares y %d son pares\n", cuenta_impares, cuenta_pares);
  return 0;
}
