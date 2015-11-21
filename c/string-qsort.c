#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp (const void * elem1, const void * elem2) {
    char* f = (char*)elem1;
    char* s = (char*)elem2;
    return strcmp(f,s);
}

int main(void){

  char words[8][20];

  strcpy(words[0], "one");
  strcpy(words[1], "two");
  strcpy(words[2], "three");
  strcpy(words[3], "four");
  strcpy(words[4], "five");
  strcpy(words[5], "six");
  strcpy(words[6], "seven");
  strcpy(words[7], "eight");

  int word_count= sizeof(words)/sizeof(*words);
  qsort(words, word_count, sizeof(*words), comp);

  for (int i=0; i<word_count; ++i){
    printf("%s\n", words[i]);
  }
  
  return 0;
}
