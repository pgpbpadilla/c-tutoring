#include<stdio.h>

int menu();
int calcula_tamano(const char cadena[]);
void copiar(char origen[], char* destino);
void copiar_cadena();
void comparar_cadena();
const char* compara(char* cadena1, char* cadena2);
void calcular_longitud ();
void concatenar_cadenas();
char* concatenar(char* destino,const char* origen);

int main(void) {

  int opcion = -1;
  do {

    opcion = menu();

    switch (opcion) {

    case 1:
      copiar_cadena();
      break;

    case 2:
      comparar_cadena();
      break;

    case 3:
      calcular_longitud();
      break;

    case 4:
      concatenar_cadenas();
      break;
      
    default:
      printf("Estas feo!");
      break;
    }
    
  } while (opcion != 5);
  
  return 0;
}


int menu() {

  int opcion;
  
  printf("\n\nElija una opcion:\n");
  printf("1. Copiar - strcpy\n");
  printf("2. Comparar - strcpm\n");
  printf("3. Calcular longitud - strlen\n");
  printf("4. Concatenar - strcat\n");
  printf("5. Salir\n");

  
  scanf("%d", &opcion);

  return opcion;
}

int calcula_tamano(const char cadena[]) {
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

  char cadena[] = "Malnacido seras por toda la eternidad, blah!";
  char copia[255];

  /* printf("Ingrese una cadena de caracteres: \n"); */
  /* scanf("%s", cadena); */

  printf("Cadena entrada = %s, direccion= %p\n", cadena, &cadena);
  printf("Longitud de '%s' = %d\n", cadena, calcula_tamano(cadena));
  
  copiar(cadena, copia);
  
  printf("%s\n", copia);
  printf("Cadena copia = %s, direccion= %p\n", copia, &copia);
  
}

void comparar_cadena(){

  char cadena1[]="Malnacido del mal";
  char cadena2[]="Malnacido dal mel";
  const char* resultado;
  printf("Las cadenas a comparar son:\n1 - %s\n2 - %s\n", cadena1, cadena2);
  resultado = compara(cadena1, cadena2);
  printf("\nLas cadenas %s son iguales!\n", resultado);
}

const char* compara (char* cadena1, char* cadena2) {
  int longitud1, longitud2, i;

  longitud1 = calcula_tamano(cadena1);
  longitud2 = calcula_tamano(cadena2);

  if (longitud1 != longitud2) {
    return "NO";
  }
  // son de la misma longitud
  for(i=0;i<longitud1;i++){
    if (cadena1[i] != cadena2[i]) {
      return "NO";
    }
  }
  
  return "SI";

}

void calcular_longitud () {
  char cadena[]="Hola malnacido";
  /* cadena de entrada = pedir entrada al usuario*/

  printf("La cadena '%s' tiene %d caracteres\n", cadena, calcula_tamano(cadena));
}


void concatenar_cadenas() {

  char destino[80] = "David no sabe programar. ";
  const char origen[] = "No seas como david";
  printf("La concatenacion de la cadena '%s' y la cadena '%s'\n ", destino, origen);
  
  printf("es: %s\n", concatenar(destino, origen)); 
  
}

char* concatenar(char* destino,const char* origen) {

  int i, tamano_origen, tamano_destino;

  tamano_origen = calcula_tamano(origen);
  tamano_destino = calcula_tamano(destino);
  
  /* d = abc\0, o = jk\0 == o[2] = \0 */
  /*   - tamano_d = 3 - d[tamano_d] -> \0 */
  /*   - tamano_o = 2 */

  /* - i = 0; 0<2+1 => SI */
  /* - destino[3+0] = origen[0] => destino[3] = origen[0] => destino='abcj';  */
  /* - i++ => i=1; */
  /* - 1 < 2+1 => SI */
  /* - destino[3+1] = origen[1] => destino[4] = origen[1] => destino='abcjk';  */
  /* - i++ => i=2 */
  /* - 2 < 2+1 => SI */
  /* - destino[3+2] = origen[2] = > destino[5] = origen[2] => destino='abcjk\0' */

  for(i= 0; i < tamano_origen + 1; i++) {
    destino[tamano_destino + i] = origen[i];
  }

  /* d = abc\0, o = jk\0 == o[2] = \0 */
  /* - i = 3; 3 < 3 + 2 + 1 => SI */
  /* - destino[3]= origen[3-3] => destino[3]=origen[0] => destino='abcj'              */
  /* - i++ => i=4; 4<3+2+1 => SI */
  /* - destino[4] = origen[4-3] => destino[4] = origen[1] => destino='abcjk' */
  /* - i++ => 5; 5 < 3+2+1 => SI */
  /* - destino[5] = origen[5-3] => destino[5]=origen[2] => destino='abcjk\0' */
  /* - i++ => 6; 6 < 3+2+1 => NO  */                 

  /* for(i= tamano_destino; i < tamano_destino + tamano_origen + 1; i++) { */
  /*   destino[i] = origen[i-tamano_destino]; */
  /* } */

  return destino;
  
}

