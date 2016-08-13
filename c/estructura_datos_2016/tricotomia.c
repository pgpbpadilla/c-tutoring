#include <stdio.h>

int main(){

  int i=0,numero,
    es_cero, es_positivo,
    cuenta_ceros=0,
    cuenta_positivos=0,
    cuenta_negativos=0;
  
  printf("Ingrese diez numeros que pertenescan al conjunto de los numeros enteros:\n");
  for(i=0; i<10; i++) {
    
    scanf("%d", &numero);
  
    es_cero = numero == 0;
    es_positivo = numero > 0;
  
    if (es_cero) {
      cuenta_ceros++;
    } else if (es_positivo) {
      cuenta_positivos++;
    } else {
      cuenta_negativos++;
    }
  }
  printf("ceros: %d; positivos: %d; negativos: %d\n", cuenta_ceros,
	 cuenta_positivos, cuenta_negativos);
  return 0;
}
