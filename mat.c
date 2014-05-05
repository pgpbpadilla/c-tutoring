#include <stdio.h>
#include <stdlib.h>



void imprime_matriz(int **matriz,int  num_filas, int num_cols){
 
 int x;
 for(x=0;x<num_filas;x++){
  
    printf("%d ", **matriz);
    printf("\n");}
}
int main(void){
   
  int num_filas;
  int num_cols;

/* Recibe las dimensiones de la matriz, filas & columnas */
  printf("Dame las dimensiones de la matriz ...\n");
    
  printf("Filas:");
  scanf("%d",&num_filas);
  printf("Columnas:");
  scanf("%d",&num_cols);
    
  /* Aparta la memoria para num_filas filas de enteros */
  /* Aparta la memoria para num_filas apuntadorea a apuntadores de enteros */
  printf("sizeof: %d, num_filas: %d ...\n", sizeof(int*), num_filas);
  int** filas=(int**)malloc(sizeof(int*) * num_filas);
  printf("Memoria apartada...");


  if( NULL == filas){
    printf("Error apartando memoria para filas");
  }
  printf("Memoria apartada");
  /* Por cada fila */
  int j, i;
  for(j=0;j<num_filas;j++ ){
    /* Aparta la memoria para num_cols enteros */
    filas[j]=(int*)malloc(sizeof(int) * num_cols);
    printf("Memoria para elementos  apartada");
        
      /* llenar la matriz con numeros aleatorios en el intevalo [0, num_filas*num_cols] */
      for(i=0; i<num_cols ; i++){
	/* rand() regresa un entero en tre 0 y RAND_MAX>32767 */
	filas[i][j] = rand() % 100;
      }
  }
  printf("Imprime matriz");
  imprime_matriz(filas, num_filas, num_cols);

  return 0;    
}
