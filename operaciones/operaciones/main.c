#include <stdio.h>


float operacion(int, int, int);

int main(void) {

    int opcion;
    int numero1, numero2;
    
    do {
        printf("Operaciones del Malnacidation!\n");
        
        printf("Eliga su malnacida operacion:\n");
        
        printf("1. Suma\n"
               "2. Resta\n"
               "3. Multiplicacion\n"
               "4. Division\n"
               "5. Irse a la verga\n");
        
        scanf("%d", &opcion);
        
        if (5 == opcion) {
            printf("Nada que hacer, vamonos a la verga!!!\n");
            break; // terminar si la opcion es igual a 5
        }
        
        printf("\nDame el primer numero hijo de puta!:");
        scanf("%d", &numero1);
        printf("\nDame el segundo numero hijo de perra!:");
        scanf("%d", &numero2);
        
        operacion(numero1, numero2, opcion);
        
    } while (5 != opcion);
    
    return 0;
}


float operacion(int numero1, int numero2, int opcion){

    float resultado = 0.0f;

    switch (opcion) {
        case 1: /*Suma*/
            resultado= (float)(numero1 + numero2);
            break;
        case 2: /*Resta*/
            resultado= (float)(numero1 - numero2);
            break;
        case 3: /*Multiplicacion*/
            resultado= (float)(numero1 * numero2);
            break;
        case 4: /*Division*/
            resultado= ((float)numero1 / (float)numero2);
            break;
        default:
            printf("Opcion no reconocida %d, vaya ud. y chinge a su madre.\n", opcion);
            break;
    }
    
    printf("\n\n\tEl resultado es: %f pinche ignorante que no sabes ni sumar!!!\n\n", resultado);

    return resultado;
}