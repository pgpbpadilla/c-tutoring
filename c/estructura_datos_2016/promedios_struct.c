#include <stdio.h>
#include <stdlib.h>

typedef struct grupo {
  float * calificaciones;
  float promedio;
} grupo;

float* lee_calificaciones();
float promedio(float* datos);

int main() {
  
  int numero_grupos;
  float* promedios_de_grupos;

  printf("Cuantos grupos? :");
  scanf("%d", &numero_grupos);
  
  promedios_de_grupos = (float*)malloc( sizeof(float*) * numero_grupos);

  if (NULL == promedios_de_grupos) {
    printf("Error reservando memoria para promedios de grupos");
    exit(-1);
  }
  
  for (int i=0; i<numero_grupos; ++i) {

    printf("\n== Grupo %d ==\n", i+1);
    
    grupo grupo_k;
    grupo_k.calificaciones = lee_calificaciones();
    
    if (NULL == grupo_k.calificaciones) {
      printf("Error reservando memoria para calificaciones");
      exit(-2);
    }
    
    grupo_k.promedio = promedio(grupo_k.calificaciones);
    printf("\nPromedio: %f\n", grupo_k.promedio);
    promedios_de_grupos[i] = grupo_k.promedio;
  }

  float promedio_general = promedio(promedios_de_grupos);
  
  printf("\nPromedio general: %f\n", promedio_general);

}


float* lee_calificaciones(){
  float* calificaciones;
  int numero_alumnos;

  printf("Cuantos alumnos?: ");
  scanf("%d", &numero_alumnos);

  calificaciones = (float*)malloc( sizeof(float*) * numero_alumnos );
  
  if (NULL == calificaciones) {
    printf("Error reservando memoria para lista de calificaciones");
    return NULL;
  }
  
  float calificacion_k;

  for (int k=0; k<numero_alumnos; ++k) {
    
    printf("Calification alumno %d/%d? : ", k+1, numero_alumnos);
    scanf("%f", &calificacion_k);

    calificaciones[k] = calificacion_k;
  }
  
  return calificaciones;
}

float promedio(float * datos) {
  int numero_datos = sizeof(datos) / sizeof(datos[0]);
  float suma = 0.0;

  for (int k=0; k<numero_datos; ++k) {
    suma+= datos[k];
  }

  return suma/numero_datos;
}
