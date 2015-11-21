#include<stdio.h>

int main()

{
  int fila =1, columna= 1;
  int limite=0;

  scanf("%d",& limite);
 
  for(fila = 1; fila <= limite; fila++){

    for(columna = 1; columna <= limite; columna++){

      if(fila == 1 || fila == limite ){     
        printf("* ");
        continue;
      }

      if(columna == 1 || columna == limite){
        printf("* ");
        continue;
      }
      
      printf("  ");
    }
    
    printf("\n");
  }
  
  return 0;
} 


    
