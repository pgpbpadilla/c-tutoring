#include<stdio.h>
int TAMANO_GRUPO = 4;

struct alumno{
  char nombre[30];
  float calificaciones[3];
  float promedio;
};

float calcula_promedio(struct alumno el_alumno) {

  float suma_calificaciones, promedio = 0;
  
  for(int i=0; i<4; i++) {

    suma_calificaciones+= el_alumno.calificaciones[i]; 
  }
  promedio = suma_calificaciones/3;

  printf("promedio= %f\n", promedio);

  return promedio;
}

void imprime_alumno(struct alumno el_alumno){
  printf("\nAlumno: %s\n", el_alumno.nombre);
  printf("Calificaciones:\n");

  for(int i=0; i<3; i++) {
    printf("\tParcial %d: %f\n", i, el_alumno.calificaciones[i]);
  }

  el_alumno.promedio = calcula_promedio(el_alumno);

  printf("Promedio: %f", el_alumno.promedio);
}

void rellena_informacion_alumnos(struct alumno alumnos[TAMANO_GRUPO]) {
  int i;
  
  for(i=0; i<TAMANO_GRUPO; i++) {
    printf("\nInformacion del alumno %d:", i);
    printf("\nNombre: ");
    scanf("%s", alumnos[i].nombre);

    printf("\nDame sus calificacfiones:\n");
    for(int j=0; j<3; j++) {
      printf("\tParcial %d: ", j);
      scanf("%f", &alumnos[i].calificaciones[j]);
    }
  }

}

int main(void){
 
  struct alumno todos_los_alumnos[TAMANO_GRUPO];

  rellena_informacion_alumnos(todos_los_alumnos);
  
  printf("Los alumnos son:");
  for(int i=0; i<TAMANO_GRUPO; i++) {
    imprime_alumno(todos_los_alumnos[i]);
  }
}
