typedef int **matriz; 
typedef int *pentero; 
 
matriz generar_matriz(int m, int n) { 
  matriz aux; int i; 
  if ((aux =(matriz)malloc(m*sizeof(pentero))) == NULL) 
    return; 
  for (i=0; i<m; i++) 
    if ((aux[i] = (pentero)malloc(n*sizeof(int))) == NULL) 
      return; 
  return aux; 
} 
 
void liberar_matriz(matriz p, int m, int n){ 
  int i; 
  for(i=0; i<m; i++) 
    free(p[i]); 
  free(p) 
    } 
 
void leer_matriz(matriz p, int m, int n){ 
  int i, j; 
  for (i=0; i<m; i++){ 
    for (j=0; i<n; j++){ 
      printf(“p[%d][%d]:”,i,j); 
      scanf(“%d”,&(p[i][j])); 
    } 
  } 
} 
 
 
void mostrar_matriz(matriz p, int m, int n){ 
  int i, j; 
  for (i=0; i<m; i++){ 
    for (j=0; i<n; j++){ 
      printf(“%d ”,p[i],p[j]); 
 
    } 
    printf(“\n”); 
  } 
} 
 
void sumar_matrices(matriz A, matriz b, int m, int n) 
  int i, j; 
for (i=0; i<m; i++){ 
  for (j=0; i<n; j++){ 
    A[i][j] = A[i][j] + B[i][j]; 
  } 
 } 
} 
 
int main (){ 
  int m, n; matriz A, matriz B; 
  printf(“FILAS:”); 
  scanf(“%d”, &m); 
  printf(“COLUMNAS:”); 
  scanf(“%d”, &n); 
  A = generar_matriz(m,n); 
  B=generar_matriz(m,n); 
  printf(“DATOS DE LA MATRIZ A:\n”); 
  leer_matriz(A,m,n); 
  printf(“DATOS DE LA MATRIZ B:\n”); 
  leer_matriz(B,m,n); 
  sumar_matrices(A,B,m,n); 
  printf(“La suma de A y B es:\n”); 
  mostrar_matriz(A,m,n); 
  printf(“LIBERANDO LAS MATRICES:\n”); 
  liberar_matriz(A,m,n); 
  A=NULL; 
  liberar_matriz(B,m,n); 
  B=NULL; return 0; 

} 
