#include <stdio.h>
int TAMANO = 2;

struct viaje{
  int clave;
  float kilometros;
  float litros;
};

float calcula_promedio(float valores[], int tamano) {

  float suma = 0, promedio = 0;
  
  for(int i=0; i < tamano; i++) {

    suma += valores[i]; 
  }
  promedio = suma / tamano;

  return promedio;
}


void imprime_viaje(struct viaje el_viaje){
  printf("\nViaje: %d\n", el_viaje.clave);
  printf("\nKm recorridos: %f\n", el_viaje.kilometros);
  printf("\nLts consumidos: %f\n", el_viaje.litros);
}

void rellena_informacion_viajes(struct viaje viajes[TAMANO]) {
  int i;
  
  for(i=0; i<TAMANO; i++) {
    printf("\nInformacion del auto %d:", i);
    printf("\nClave: ");
    scanf("%d", &viajes[i].clave);
    printf("\nKm recorridos: ");
    scanf("%f", &viajes[i].kilometros);
    printf("\nLitros consumidos: ");
    scanf("%f", &viajes[i].litros);
  }

}

int main(void){

  float promedio_kilometros;

  float promedio_litros;

  float kilometros[TAMANO];

  float litros[TAMANO];

  struct viaje todos_los_viajes[TAMANO];

  rellena_informacion_viajes(todos_los_viajes);
  
  printf("Los viajes son:");
  for(int i=0; i<TAMANO; i++) {
    imprime_viaje(todos_los_viajes[i]);

    kilometros[i] = todos_los_viajes[i].kilometros;

    litros[i] = todos_los_viajes[i].litros;

  }

  promedio_kilometros = calcula_promedio(kilometros, TAMANO);

  promedio_litros = calcula_promedio(litros, TAMANO);

  printf("Promedio kilometros = %f\n",promedio_kilometros);

  printf("Promedio litros = %f\n",promedio_litros);
}
