
#include <stdio.h>
#include <stdlib.h>


int main() { 
  char* productos [5];
  float precios [5];
  
  int i=1;
  
  productos[0] = "\nLeche";
  precios[0] = 30.0f;

  
 for(i=1; i<5; i++){
    productos[i] = (char*)malloc(sizeof (char)*10);
    printf("Dame el nombre del producto:\n ");
    scanf("%80s", productos[i]);
    printf("Dame el precio del producto:\n ");
    scanf("%f", &precios[i]);
    
 }
    
  printf("=========");  
  printf("Productos");
  printf("=========");
  
  for(i=0; i<5; ++i) {
    printf("%s - %f\n", productos[i], precios[i]);
  }
  
  return 0;
}

