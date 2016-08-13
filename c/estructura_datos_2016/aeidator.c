#include <stdio.h>
#include <ctype.h>

int main(){

  char caracter;
  int es_a, es_e, es_i, i,
    cuenta_a=0,
    cuenta_e=0,
    cuenta_i=0;
  
  printf("Ingrese diez caracteres:\n");

  for(i=0; i<10; i++) {
    
    scanf(" %c", &caracter);
  
    es_a = tolower(caracter) == 'a';
    es_e = toupper(caracter) == 'E';
    es_i = tolower(caracter) == 'i';
  
    if (es_a) {
      cuenta_a++;
    } else if (es_e) {
      cuenta_e++;
    } else if (es_i){
      cuenta_i++;
    } 
  }
  printf("Total occurrencias:\n a: %d; e: %d; i: %d\n",
	 cuenta_a, cuenta_e, cuenta_i);
  return 0;
}
