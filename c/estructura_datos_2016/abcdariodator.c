#include <stdio.h>

int main(void) {

  int x= 'A';
  
  for(x='A'; x<='Z'; x++){
    printf("%c %d \n", x, x);
  }

  return 0;
}
