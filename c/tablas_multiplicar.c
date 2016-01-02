#include <stdio.h>

int main(void){

  int opcion,i,j,resultado;

  do{
  
    printf("\n1.-Tablas de multiplicar con while\n");
    printf("2.-Tablas de multiplicar con for\n");
    printf("3.-Tablas de multiplicar con do-while\n");
    printf("4.-Salir\n");
    scanf("%d", &opcion);

    switch(opcion){
    case 1:
      printf("Tablas de multiplicar con while:\n");

      i=1;
      while(i<=10){
        j=1;      
        while(j<=10){
          resultado = i * j;
          printf("%d * %d = %d\n", i,j,resultado);
          j++;
        }
        i++;
      }
      break;

    case 2:
      printf("Tablas de multiplicar con for:\n");

      for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
          resultado = i*j;
          printf("%d * %d = %d\n", i,j,resultado);
        }
      }
      break;
      
    case 3:
      printf("Tablas de multiplicar con do-while:\n");
      j=1;      
      do {
        i=1;
        do {
          resultado=i*j;
          printf("%d * %d = %d \n", i,j, resultado);
          i++;
        } while (i<=10);
        j++;
      } while (j<=10);
      break;

    case 5:
      i = j = 1;
      do {

        printf("%d * %d = %d\n", i, j, i*j);
        i++;

        if (i == 10) {
          i = 1;
          j++;
        }

      } while (i<11 && j<11);
      break;
    case 4:
      printf("Adios\n");
      break;
      
    default:
      printf("Escoje una opcion correcta!!!\n");
    }
  }while(opcion != 4);

  return 0;
}
