#include<stdio.h>
#include<stdlib.h>

typedef int **matriz; 
typedef int *pentero; 
 
matriz generar_matriz(int m, int n) { 
  matriz aux; int i; 

  /* Reserva memoria para `m` veces el tamanio de `pentero`.
     `pentero` es de tipo `int*`, es decir, se esta reservando
     memoria para `m` apuntadores a entero.
     
     La funcion `malloc` regresa `void*`, un apuntador a `void`. Que es 
     como un comodin por que puede apuntar a cualquier tipo de dato.

     IMPORTANTE: `malloc` regresa un apuntador que apunta al inicio del bloque reservado.

     El resultado de `malloc` esta siendo `cast`-eado a el tipo `matriz` 
     `matriz` es de tipo `int**`, un apuntador a apundadores a enteros, 
     osease un apuntador de apunta a otro apuntador que apunta a un entero.

     apuntador2 -> apuntador1 -> int

     - apuntador1 guarda la direccion de memoria del entero al que apunta
       esto es literal, apuntador1 guarda una direccion de memoria, no el valor del entero.
     - apuntador2 guarda la direccion de `apuntador1`, no el valor del entero.

     `(matriz)malloc(...)` es un casting, es decirle al compilador: "transforma el valor que me regreso `malloc` 
     en un dato de tipo `matriz`"

     Si la reservacion es exitosa, `aux` es un apuntador de tipo `int**` que apunta al inicio del bloque reservado.
     Si la reservacion de memoria falla, `aux` tendra el valor `NULL`
   */
  aux= (matriz)malloc( m*sizeof(pentero) );

  /* Revisamos si la asignacion fue exitosa */
  if ( aux == NULL) {
    /* Si fallo la reservacion de memoria, la funcion regresa el valor `NULL` */
    return NULL; 
    /* Aqui se acaba el asunto */
  }

  /* Si la reservacion fue exitosa entonces `aux` es apuntador al inicio de un bloque de `m` apuntadores a enteros
     Estas van a ser las columnas de la matriz */

  /* Usamos un ciclo para reservar memoria para cada uno de los elementos de las filas */
  for (i=0; i<m; i++) {
      /* Reserva memoria para un bloque de `n` enteros
	 El apuntador en la posicion `aux[i]` apunta al inicio del bloque recien reservado.
       */
    aux[i] = (pentero)malloc( n*sizeof(int) );
  }
    
  /* Revisa si la reservacion fue exitosa */
  if ( aux == NULL) {
    return NULL; 
  }
  
  /* Regresa el apuntador que apunta al inicio del bloque de enteros que representa */
  /* una matriz de `m` columnas y `n` filas */
  return aux; 
} 
 
void liberar_matriz(matriz p, int m, int n){ 
  int i; 
  for(i=0; i<m; i++) {
    free(p[i]); 
  }

  free(p);
} 

void leer_matriz(matriz p, int m, int n){ 
  int i, j; 
  for (i=0; i<m; i++){ 
    for (j=0; j<n; j++){ 
      printf("p[%d][%d]:",i,j); 
      scanf("%d",&(p[i][j])); 
    } 
  } 
} 
 
 
void mostrar_matriz(matriz p, int m, int n){ 
  int i, j; 
  for (i=0; i<m; i++){ 
    for (j=0; j<n; j++){ 
      printf("%d ",p[i][j]); 
 
    } 
    printf("\n"); 
  } 
} 
 
void sumar_matrices(matriz A, matriz B, int m, int n) {
  int i, j; 
  for (i=0; i<m; i++){ 
    for (j=0; j<n; j++){ 
      A[i][j] = A[i][j] + B[i][j]; 
    } 
  } 
} 
 
int main (){ 
  int m, n; 
  matriz A, B; 

  printf("FILAS:"); 
  scanf("%d", &m); 

  printf("COLUMNAS:"); 
  scanf("%d", &n); 

  A = generar_matriz(m,n); 
  B= generar_matriz(m,n); 

  printf("DATOS DE LA MATRIZ A:\n"); 
  leer_matriz(A,m,n); 
  mostrar_matriz(A,m,n); 

  printf("DATOS DE LA MATRIZ B:\n"); 
  leer_matriz(B,m,n); 
  mostrar_matriz(B,m,n); 

  sumar_matrices(A,B,m,n); 

  printf("La suma de A y B es:\n"); 
  mostrar_matriz(A,m,n); 

  printf("LIBERANDO LAS MATRICES:\n"); 

  liberar_matriz(A,m,n); 

  A=NULL; 

  liberar_matriz(B,m,n); 

  B=NULL; 
  return 0; 
} 
