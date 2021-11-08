#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *A = (char*)malloc(sizeof(char));
    sprintf(A, "Hello World\n");
    printf("%s",A);
    sprintf(A, "BY\n");
    printf("%s",A);

    return 0;
}