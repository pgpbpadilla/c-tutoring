#include <stdio.h>

float potencia_for(float numero, int potencia);
float potencia_while(float numero, int potencia);
int main()

{
  float masa_final, masa_final1 = 0.0;
  float masa_inicial = 50;
  float k = .024;
  int n = 10;
  float resultado, resultado1;


  /* 1 - mf = mi - k*mi = (1-k) * mi */
  /* 2 - mf = (1-k) * mi -  k * [(1-k) * mi] = (1-k) * [(1-k)*mi] = (1-k)^2 * mi 
  /* 3 - mf = (1-k)^2 * mi - k * [(1-k)^2 * mi] = (1-k) * [(1-k)^2 * mi] = (1-k)^mi 
  /* 4 - ... */
  
  /* 7 - mf = (1-k)^7 *mi */

  resultado =  potencia_for ((1.0 - k), n); /* (1-k)^n */
  printf("resultado = %f\n", resultado);

 resultado1 =  potencia_while ((1.0 - k), n); /* (1-k)^n */
  printf("resultado1 = %f\n", resultado);

  masa_final =  resultado * masa_inicial; /* mf = (1-k)^n * mi*/
  masa_final1 =  resultado1 * masa_inicial;

  printf("for Te quedan %f gramos de estroncio\n", masa_final);
  printf("while Te quedan %f gramos de estroncio\n", masa_final1);

}

float potencia_for(float numero, int potencia) {

  float resultado = numero; 
  int i;
  printf("el numero es %f y la potencia es %d\n ", numero, potencia);
  if (potencia== 0)
    return 1;
  if (potencia== 1)
    return numero;
  for( i = 2; i <= potencia; i++) {
    resultado =resultado *  numero;
  }
  return resultado;
}


float potencia_while(float numero, int potencia) {
  int  i=2;
  float resultado = numero;

  if (potencia == 0)
    return 1;
  if (potencia == 1)
    return numero;
  while(i <= potencia) { /*mientras se cumpla la condicion*/
    /* haz lo que esta en este `scope`*/
    resultado = resultado * numero;
    i++;
  }
  return resultado;
}
