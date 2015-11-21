#incude <stdio.h>

float total_x_transporte(float peso, float precio_x_gr);

int main(void)
{
  float total, peso, precio_gr;

  printf("ingresa el peso del paquete en gramos\n\n");
  scanf("%f", peso);
  printf("ingresa el precio por gramo:\n\n");
  scanf("%f", precio_gr);

  total= total_x_transporte(peso, precio_gr);
  printf("el precio del transporte es: %f", total);

  return 0;
}

float total_x_transporte(float peso, float precio_x_gr){
  float gramo_extra, total;
