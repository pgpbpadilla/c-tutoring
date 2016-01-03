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

int calcula_tamano(char cadena[]) {
  int longitud = 0;
  
  while(cadena[longitud] != '\0') {
    longitud++;
  }
  
  return longitud;
}

void copiar(char origen[], char* destino){
  int i;

  int longitud = calcula_tamano(origen);

  for(i=0;i<=longitud;i++){
    destino[i] = origen[i];
  } 
};

void copiar_cadena(){

  char cadena[255];
  char copia[255];

  printf("Ingrese una cadena de caracteres: \n");
  scanf("%s", cadena);
  printf("Cadena entrada = %s, direccion= %p\n", cadena, &cadena);
  printf("Longitud de '%s' = %d\n", cadena, calcula_tamano(cadena));
  
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


