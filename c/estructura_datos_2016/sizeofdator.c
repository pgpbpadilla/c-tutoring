#include <stdio.h>
#include <stddef.h>

void print_row(char* nombre, size_t tamanio) {
  printf("%-18s | %-7zd\n", nombre, tamanio);
}

int main() {

  printf("%-18s | %-7s\n", "Tipo de dato", "Tamanio");
  print_row("char", sizeof(char));
  print_row("unsigned char", sizeof(unsigned char));
  print_row("signed char", sizeof(signed char));
  print_row("short", sizeof(short));
  print_row("int", sizeof(int));
  print_row("unsigned int", sizeof(unsigned int));
  print_row("signed int", sizeof(signed int));
  print_row("short int", sizeof(short int));
  print_row("unsigned short int", sizeof(unsigned short int));
  print_row("signed short int", sizeof(signed short int));
  print_row("long int", sizeof(long int));
  print_row("signed long int", sizeof(signed long int));
  print_row("unsigned long int", sizeof(unsigned long int));
  print_row("long", sizeof(long));
  print_row("unsigned long", sizeof(unsigned long));
  print_row("float", sizeof(float));
  print_row("double", sizeof(double));
  print_row("long double", sizeof(long double));
  
  
  return 0;
}
