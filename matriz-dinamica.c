#include <stdio.h>
#include <stdlib.h>

int main(void){

  int num_filas; 
  int num_cols= 2;

  printf("Filas:");
  scanf("%d",&num_filas);
  printf("Columnas:"); 
  scanf("%d",&num_cols );

  /* Reserva memoria para las filas */
  int** filas=(int **)malloc(num_filas * sizeof(int*));
  if( NULL == filas){
    /* termina el programa si la reservacion de memoria falla */
    return -1;
  }

  /* por cada fila */
  int i, j;
  for(i=0; i<num_filas; ++i){
    /* reserva memoria para elemento de la fila */
    filas[i]=(int*)malloc(sizeof(int)*num_cols);

    if (NULL == filas[i]){
      /* termina el programa si la reservacion falla */
      return -1;
    }

    /* por cada elemento en la fila */
    for(j=0; j<num_cols; ++j){
      /* asigna un numero aleatorio en el intervalo [1, num_filas*num_cols] */
      filas[i][j] = rand() % num_filas*num_cols+1;
      printf("%d\t", filas[i][j]);
    }
    printf("\n");

  }
  
  /* for cada fila */
  for(i=0; i<num_filas; ++i){
    /* libera la memoria del apuntador a cada fila */
    free(filas[i]);
  }
  /* libera la memoria del apuntador a la matriz */
  free(filas);

  return 0;
}
