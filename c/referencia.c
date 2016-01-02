#include <stdio.h>


void uno(int a) {
  a = 25;
}

void dos(int *a) {
  *a = 34;
}

int main (void) {

  int a = 5;
  int b = 6;
  int *c = &a;

  printf("Valor a = %d, direccion= %p\n", a, &a);
  printf("Valor b = %d, direccion= %p\n", b, &b);
  printf("Valor c = %p, direccion= %p, valor apuntado=%d\n", c, &c, *c);

  uno(a);
  printf("a = %d\n", a);

  dos(&a);
  printf("a = %d\n", a);

  return 0;
}
