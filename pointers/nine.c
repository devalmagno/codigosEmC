#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 9) Crie uma função que receba como parâmetro um array e o imprima. Não utilize índices para percorrer o array, apenas aritmética de ponteiros. 

#define SIZE (5)

void passThroughArrayUsingPointers(int array[SIZE]);

int main()
{
    system("cls");

    size_t i = 0;
    int array[SIZE] = {1, 2, 3, 4, 5};

    printf(">>> POINTEIROS\n\n");

    passThroughArrayUsingPointers(array);

    return 0;
}

void passThroughArrayUsingPointers(int array[SIZE]) {
    int *p;

    for (p = array; *p; ++p) {
        printf("%d\n", *p);
    }
}