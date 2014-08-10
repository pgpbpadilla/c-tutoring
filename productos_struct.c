#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Producto {
  char* nombre;
  float precio;
} Producto;

int main() { 

  Producto prods [5];
  
  prods[0].nombre = "leche";
  prods[0].precio = 40.0f;

  for(int i=1; i<5; ++i) {

    printf("\nProducto %d\n", i);

    printf("Nombre: ");
    prods[i].nombre = (char *)malloc(sizeof(char)*25);
    scanf("%s", prods[i].nombre);
    printf("Precio: "); 
    scanf("%f", &prods[i].precio);
  }

   printf("=========");   
   printf("Productos"); 
   printf("=========\n\n"); 
  
   for(int i=0; i<5; ++i) { 
     printf("%s - %f\n", prods[i].nombre, prods[i].precio); 
   } 
  
  return 0;
}

