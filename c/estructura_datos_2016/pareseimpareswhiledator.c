#include <stdio.h>

int main(){

  int cuenta= 1, es_par, numero,
    cuenta_pares=0,
    cuenta_impares=0;

  printf("Ingresa diez numeros:\n");

  while(cuenta <= 10){

    scanf("%d", &numero);

    es_par = numero%2 == 0;
  
    if(es_par) {
      cuenta_pares++;
    } else {
      cuenta_impares++;
    }
    cuenta++;
  }
  
  printf("pares=%d; impares=%d\n", cuenta_pares, cuenta_impares);
  return 0;
}
