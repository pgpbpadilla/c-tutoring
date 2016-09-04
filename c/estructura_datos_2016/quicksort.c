#include<stdio.h>

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

int main (void) {

  int numeros[] = {5, 7, 6, 1, 8, 4, 9, 3, 2, 0};
  
  print_array(numeros, 10, "Antes de ordenar");
  quicksort(numeros, 0, 9);
  print_array(numeros, 10, "Despues de ordenar");
}
