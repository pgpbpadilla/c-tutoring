#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cp(char* a){
    char *f;
    int length = strlen(a);
    printf("a=%s has %d characters.\n", a, length);
    
    f = (char*)malloc( length * sizeof(char));
    
    if (f == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }
    
//    while (*a != 0) {
//        *f = *a;
//        printf("%p:*f = %c\n", f, *f);
//        f++; // BAD: incrementing the address pointed to
//        a++; // BAD: incrementing the address pointed to
//    }
    
    // if you already know the length of the string to copy
    // then use that length.
    for (int k = 0; k < length; ++k) {
        f[k] = a[k];
    }
    
    // in order to return a pointer to beginning of the string
    // you need to NOT increment the pointer.
    return f;
}

int main(void){
    char* copy = cp("test\0");
    
    printf("%p = %s.\n", copy, copy);
}