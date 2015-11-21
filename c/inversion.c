#include <stdio.h>

int calcula_ano2();
int calcula_ano(int saldo_inicial, int retiro_anual, float taza_interes_anual);

int main()
{
  int ano;
  float saldo_inicial = 100000;

  ano = calcula_ano2();
  printf("No te alcanza pinche jodido, no puedes retirar al ano: %d\n", ano);

  ano = calcula_ano(saldo_inicial, 3000, 0.1);
  printf("No te alcanza pinche jodido, no puedes retirar al ano: %d\n", ano);

  return 0;

} 

int calcula_ano2(){
  return calcula_ano(100000, 12000, 0.05);
}

int calcula_ano(int saldo_inicial, int retiro_anual, float taza_interes_anual){
  int ano = 0;
  float saldo;
  saldo = saldo_inicial;
  do{ 
    /* printf("Saldo al ano: %d es: %f\n\n", ano, saldo);  */
    /* incrementa el saldo anterior dada la taza de interes */
    saldo = saldo * (1.0 + taza_interes_anual) - 12000; 
    /* printf("Saldo al ano: %d es: %f\n\n", ano, saldo);  */
    ano++;
    /* mientras que el saldo sea menor a 150000 */
  }while(saldo > 12000);

  return ano;
}



  /* int ano =1; */
  /* /\* desde que el saldo es igual al saldo inicial *\/ */
  /* /\* y mientras que el saldo sea menor o igual a 150000 *\/ */
  /* /\* incrementa el saldo anterior en 5% *\/ */
  /* for(saldo = saldo_inicial; saldo <= 150000; saldo=saldo*1.05) { */
  /*   printf("Saldo al ano: %d es: %f\n\n", ano, saldo); */
  /*   ano++; */
  /* } */

  /* ano =0; */
  /* saldo = saldo_inicial; */
  /* /\* mientras  que el saldo sea menor que 150000 *\/ */
  /* while(saldo <= 150000){ */
  /*   printf("Saldo al ano: %d es: %f\n\n", ano, saldo); */
  /*   /\* incrementa el saldo anterior en 5% *\/ */
  /*   saldo= saldo * 1.05; /\* saldo = saldo + 0.5 * saldo*\/ */
  /*   ano++; */
  /* } */
