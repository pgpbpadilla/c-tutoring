#include <stdio.h>

float promedio_en_linea();

int main(){

  int i=0, numero_grupos;
  float suma_promedios=0.0, promedio_general=0.0,promedio_k=0.0;

  printf("Cuantos grupos?");
  scanf("%d", &numero_grupos);
  
  for(i=1; i<=numero_grupos; i++){
    printf("Calificaciones para grupo %d/%d\n", i, numero_grupos);

    promedio_k = promedio_en_linea();
    suma_promedios += promedio_k;

    printf("el promedio del grupo %d es: %f\n", i, promedio_k);
  }
  
  promedio_general = suma_promedios/numero_grupos;

  printf("El promedio general es: %f\n", promedio_general);
  
}

float promedio_en_linea(){

  int i, numero_datos;
  float calificacion =0, suma=0, promedio=0;
  
  printf("Cuantos datos a promediar?\n");
  scanf("%d",&numero_datos);
  
  for(i=1;i<=numero_datos;i++){
    printf("Calificacion %d/%d?\n", i, numero_datos);
    scanf("%f", &calificacion);

    suma+=calificacion;
  }
  
  promedio = suma/numero_datos;

  return promedio;
}

