#include<stdio.h>

int menu () {

  int opcion;
  
  printf("Elija una opcion:\n");
  printf("1. Copiar - strcpy\n");
  printf("2. Comparar - strcpm\n");
  printf("3. Calcular longitud - strlen\n");
  printf("4. Concatenar - strcat\n");
  printf("5. Salir\n");

  
  scanf("%d", &opcion);

  return opcion;
}


void copiar(char origen[5], char destino[5]){
  int i;

  for(i=0;i<5;i++){
    destino[i] = origen[i];
  } 
   
};

void copiar_cadena(){

  char cadena[5];
  char copia[5];

  printf("Ingrese una cadena de caracteres: \n");
  scanf("%s", cadena);
  printf("Cadena entrada = %s, direccion= %p\n", cadena, &cadena);
  
  copiar(cadena, copia);
  
  printf("%s\n", copia);
  printf("Cadena copia = %s, direccion= %p\n", copia, &copia);
  
}

int main (void) {

  int opcion = -1;
  do {

    opcion = menu();

    switch (opcion) {

      case 1:
        copiar_cadena();
        break;

      default:
        printf("Estas feo!");
        break;
    }
    
  } while (opcion != 5);
  
  return 0;
}


