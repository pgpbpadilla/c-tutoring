#include<stdio.h>

int main() {

  char myString[255];

  printf("Write something:\n");

  if (NULL == fgets(myString, 256, stdin)) {
    printf("Error trying to read from stdin");
    return -1;
  }

  printf("%s", myString);
  return 0;
}
