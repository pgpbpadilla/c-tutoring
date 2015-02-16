#include <stdio.h>

float calcula_salario(int, float, int);

int main(void) {

    float salario_base= 10.0f;
    float salario_ganado = 0.0f;
    
    int horas_trabajadas, turno_trabajado;
    
    printf("Cuantas horas finjio el trabajador?\n");
    scanf("%d", &horas_trabajadas);
    printf("Cual es el turno del esclavo?\n");
    scanf("%d", &turno_trabajado);
    printf("Usando salario base: %f\n", salario_base);
    
    salario_ganado = calcula_salario(turno_trabajado, salario_base, horas_trabajadas);

    printf("El salario ganado es: %f, pinche jodido!!!\n", salario_ganado);
    
    return 0;
}

float calcula_salario(int turno, float salario_base, int horas){
    
    float salario_bruto = 0.0;
    float salario_neto = 0.0;
    float impuestos = 0.08; /* = 8% */
    float precio_hora = 0.0;
    
    float precio_hora_extra = 0.0f;
    int horas_extra = 0;
    int horas_regulares = 0;
    
    switch (turno) {
        case 1:
            precio_hora = salario_base;
            
            if (horas <= 40) {
                horas_regulares = horas;
                horas_extra = 0;
            }else{
                horas_regulares = 40;
                horas_extra = horas - horas_regulares;
                precio_hora_extra = 1.5f * precio_hora;
            }
            break;
        case 2:
            precio_hora = 1.2f * salario_base;
            
            if (horas <= 40) {
                horas_regulares = horas;
                horas_extra = 0;
            } else {
                horas_regulares = 40;
                horas_extra = horas - horas_regulares;
                precio_hora_extra = 2.0f * precio_hora;
            }
            break;
        default:
            break;
    }
    
    printf("Horas regulares: %d\n", horas_regulares);
    printf("Horas extra: %d\n", horas_extra);
    printf("Precio por hora: %f\n", precio_hora);
    printf("Precio por hora extra: %f\n", precio_hora_extra);
    
    salario_bruto = precio_hora*horas_regulares + precio_hora_extra*horas_extra;
    salario_neto = salario_bruto*(1 - impuestos);
    
    printf("Tu salario neto es una mierda: $%f\n", salario_neto);
    printf("Te quitan por impuestos: $%f\n", salario_bruto*impuestos);

    return salario_neto;
}
