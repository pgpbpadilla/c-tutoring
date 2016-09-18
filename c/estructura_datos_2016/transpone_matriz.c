#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void random_int_matrix(int** matrix, int num_cols, int num_rows) {
  /* fill with random integers */
  int i, j;
  for(i=0; i<num_rows; i++){
    for(j=0; j<num_cols; j++){
      matrix[i][j] = rand() % 100;    
    }
  }
}

void print_matrix(int** m, int num_cols, int num_rows){
  int i, j;
  printf("\n");
  for(i=0; i<num_rows; i++){
    printf("| ");
    for(j=0; j<num_cols; j++){
      printf("%-10d", m[i][j]);
    }
    printf("|\n");
  }
  printf("\n");
}

int** create_matrix(int num_cols, int num_rows){

  int** m;
  
   m =(int**)malloc(num_rows*sizeof(int*));

  if(m==NULL){
    printf("fatal error: memory allocation failed for rows.\n");
    return NULL;
  }

  for (int i=0; i<num_rows; ++i) {
    m[i] = (int*)malloc(num_cols*sizeof(int));
    if(m[i] == NULL) {
      printf("fatal error: memory allocation failed for columns.\n");
      return NULL;
    }
  }

  return m;
}

void destroy_matrix(int **m, int num_rows) {

  for(int i=0; i<num_rows; i++){
    free(m[i]);
  }
  free(m);
}

void transpose_matrix(int** m, int** transpose, int m_num_cols, int m_num_rows){
  int i,j;
  for(i=0; i<m_num_rows; i++){
    for(j=0; j<m_num_cols; j++){
      transpose[j][i] = m[i][j];
    }
  }
}

int main(void) {

  int** m;
  int num_cols, num_rows;

  srand (time(NULL));

  printf("How many columns?: ");
  scanf("%d", &num_cols);
  printf("How many rows?: ");
  scanf("%d", &num_rows);

  m = create_matrix(num_cols, num_rows);

  if (NULL == m) {
    exit(-1);
  }

  random_int_matrix(m, num_cols, num_rows);
  print_matrix(m, num_cols, num_rows);

  int **transpose = create_matrix(num_rows, num_cols);

  if (NULL == transpose) {
    exit(-1);
  }

  transpose_matrix(m, transpose, num_cols, num_rows);
  print_matrix(transpose, num_rows, num_cols);

  destroy_matrix(m, num_rows);
  destroy_matrix(transpose, num_cols); 

  return 0;
}

