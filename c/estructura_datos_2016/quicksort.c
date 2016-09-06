#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_array(int numeros[], int cantidad, char* titulo){
  printf("\n%s:\n\t[ ", titulo);
  for(int i = 0; i<cantidad; ++i) {
    printf("%d", numeros[i]);
    if (i<cantidad-1) {
      printf(", ");
    }
  }
  printf(" ]\n\n");
}

int particion(int numero[], int min, int max){

  int j,i,intercambio,pivote;

  pivote = numero[max];
  i = min;
  for(j= min; j<max; j++){
    if(numero[j] <= pivote){

      intercambio = numero[i];
      numero[i]=numero[j];
      numero[j]=intercambio;
      i++;
    }
  }
  intercambio = numero[i];
  numero[i]=numero[max];
  numero[max]=intercambio;
  
  return i;
}

void quicksort(int numeros[], int min, int max) {

  int pivote;
  if(min < max){
    pivote=particion(numeros, min, max);
    quicksort(numeros, min, pivote-1);
    quicksort(numeros, pivote+1, max);
  }

  
}

void llenar_arreglo(int numeros[], int cantidad){

  int i;
  /* initialize the random number generator */
  srand(time(NULL)); /* generate the seed */
  /* [0, RAND_MAX] => [0, 100] */
  double factor_escala = (double)RAND_MAX / (double)100;
  int r, n;
  
  for(i=0; i<cantidad; i++){
    
    r = rand(); /* r in [0, RAND_MAX] */
    n = (int) ((double)r / factor_escala); /* n in [0, 100] */
    printf("\nGenerado el numero: %d", n);
    numeros[i] = n;
  }

}

int main (void) {
  

  int *numeros;
  int cantidad;

  printf("Cuantos numeros desea ordenar?:");
  scanf("%d", &cantidad);

  numeros = (int *)malloc(cantidad * sizeof(int));
  
  if (NULL == numeros) {
    printf("Error creando arreglo de numeros!!!!! FATAL ERRRRORRORORR");
    exit(-1);
  }

  llenar_arreglo(numeros, cantidad);
  print_array(numeros, cantidad, "Antes de ordenar");

  quicksort(numeros, 0, cantidad-1);
  print_array(numeros, cantidad, "Despues de ordenar");

  free(numeros);
}
