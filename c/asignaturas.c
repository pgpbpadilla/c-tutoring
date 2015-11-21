#include <stdio.h>

float total(int cantidad);

int main()
{
	int cantidad;
	float total_a_pagar;
	printf("ingresa el numero de asignaturas a cursar: \n\n");
	scanf("%d", &cantidad);
	
	total_a_pagar= total (cantidad);
	
	printf("el total a pagar es: %f", total_a_pagar);

	getchar();
	return 0;

}

float total(int cantidad){
	float precio_asignatura = 800;
	float precio_total = cantidad * precio_asignatura;

	if(precio_total > 4800){
		return 4800;
	}
	
	return precio_asignatura*cantidad;
	
}
