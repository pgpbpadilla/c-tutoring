#include <stdio.h>

/* gcc -o funcionsuma funcionsuma.c -std=c99 -pedantic*/

typedef struct complejo{
  int real;
  int imaginario;
} com;
/* typedef struct complejo com; */
com multiplica_complejos(struct complejo u,struct complejo w);
int suma_de_enteros(int, int);
int eleva_al_cuadrado(int);
int main(){
  
  int resultado = suma_de_enteros(10, 10244);
  printf("El resultado es: %d\n", resultado);

  int x_al_cuadrado = eleva_al_cuadrado(5);
  printf("El resultado es: %d\n", x_al_cuadrado);

  struct complejo w, u;
  w.real = 2;
  w.imaginario = 3;
  u.real = 4;
  u.imaginario = 5;
  struct complejo z= multiplica_complejos(u, w);
  printf("Resultado: %d + %d i\n", z.real, z.imaginario);
  return 0;
}


int suma_de_enteros(int i,int x){
  return i+x;
}
 
int eleva_al_cuadrado(int x){
  return x*x;
}

struct complejo multiplica_complejos(struct complejo u,struct complejo w){

  struct complejo resultado;

  /*z= (x, y) = (a,b)*(c,d) =(a*c-b*d, a*d+b*c) => x=a*c-b*d , y=a*d+b*c 
     Re(z)= x, Im(z)=y
  */
  resultado.real = (u.real*w.real - u.imaginario*w.imaginario);
  resultado.imaginario =(u.real*w.imaginario + u.imaginario*w.real) ;

  return resultado;
}
