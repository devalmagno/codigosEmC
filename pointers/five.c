#include <stdio.h>
#include <stdlib.h>

// 5) Crie um programa que contenha uma função que permita passar por parâmetro dois números inteiros A e B. A função deverá calcular a soma entre estes dois números e armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas deverá modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função principal

void somaValores();

int main()
{
    system("cls");

    int a = 15, b = 80;

    printf(">>> POINTEIROS\n\n");

    printf("\n\nValores antes de chamar a funcao: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    somaValores(&a, &b);

    printf("Apos chamar a funcao: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    return 0;
}

void somaValores(int *a, int *b)
{
    int valorSoma = *a + *b;
    *a = valorSoma;
}