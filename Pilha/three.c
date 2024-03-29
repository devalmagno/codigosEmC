#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause");
#define CLEAR system("cls");
#define TITLE printf("\n\n>> Pilha\n");

void push(int stack[], int *top, int stackSize, int number);
void pop(int stack[], int *top, int stackSize);
void list(int stack[], int *top, int stackSize);
void insert(int queue, int array[], int number);
void delete(int queue, int array[]);

int rpos[2] = { -1, -1};
int spos[2] = { -1, -1};

int main() {
    CLEAR;
    
    int N, number, j, i = 0, alt = 0, num[100], top = -1;
    int nPar = 0, nImpar = 0;
    int stackSize = 0;
    int contPar = 0, contImpar = 0;
    num[0] = 1;

    TITLE;

    while(number != 0) {
        printf("Digite o numero[%d]: ", i + 1);
        scanf("%d", &number);
        num[i] = number;
        i++;
    }

    for (j = 0; j < i; j++) {
        if (num[j] % 2 == 0) {
            nPar++;
        } else {
            nImpar++;
        }
    }

    int *par = malloc(nPar * sizeof(int));
    int *impar = malloc(nImpar * sizeof(int));

    for (j = 0; j < i; j++) {
        if (num[j] % 2 == 0) {
            insert(1, par, num[j]);
        } else {
            insert(2, impar, num[j]);
        }
    }

    stackSize = 100;

    int *stack = malloc(stackSize * sizeof(int));

    for (j = 0; j < i; j++) {
        if (j % 2 != 0) {
             if (contImpar != nImpar) {
                if (impar[j] > 0) {
                    printf("impar: %d\n", impar[contImpar]);
                    push(stack, &top, stackSize, impar[contImpar]);
                } else {
                    pop(stack, &top, stackSize);
                }

                delete(2, impar);
                contImpar++;
            }
        } else {
            if (contPar != nPar) {
                if (par[j] > 0) {
                    printf("par: %d\n", par[contPar]);
                    push(stack, &top, stackSize, par[contPar]);
                } else {
                    pop(stack, &top, stackSize);
                }

                delete(1, par);
                alt = 0;
                contPar++;
            }
        }

        // if (alt == 1) {
        //     if (contPar != nPar) {
        //         if (par[j] > 0) {
        //             printf("par: %d\n", par[contPar]);
        //             push(stack, &top, stackSize, par[contPar]);
        //         } else {
        //             pop(stack, &top, stackSize);
        //         }

        //         delete(1, par);
        //         alt = 0;
        //         contPar++;
        //     }
        // } else {
        //     if (contImpar != nImpar) {
        //         if (impar[j] > 0) {
        //             printf("impar: %d\n", impar[contImpar]);
        //             push(stack, &top, stackSize, impar[contImpar]);
        //         } else {
        //             pop(stack, &top, stackSize);
        //         }

        //         delete(2, impar);
        //         alt = 1;
        //         contImpar++;
        //     }
        // }
    }

    list(stack, &top, stackSize);

    return 0;
}

void push(int stack[], int *top, int stackSize, int number) {
    if (*top == -1) {
        *top = stackSize - 1;
    }
    
    stack[(*top) - 1] = number;
    printf("%d", stack[(*top) -1]);
    (*top)--;
}

void pop(int stack[], int *top, int stackSize) {
    if ((*top) == stackSize - 1) {
        (*top) = -1;
    } else {
        (*top)++;
    }
}

void list(int stack[], int *top, int stackSize) {
    int i, cont = 1;

    printf("\n\nPilha:\n\n");

    for (i = stackSize - 1; i >= *top; i--) {
        printf("[%d]: %d\n", cont, stack[i]);
        cont++;
    }

    PAUSE;
}

void insert(int queue, int array[], int number) {
    int i;

    switch (queue) {
        case 1:
            if (rpos[0] == -1) rpos[0] = 0;

            spos[0] = spos[0] + 1;
            array[spos[0]] = number;
            break;
        case 2:
            if (rpos[1] == -1) rpos[1] = 0;
            spos[1] = spos[1] + 1;                
            array[spos[1]] = number;

            break;
    }
}

void delete(int queue, int array[]) {
    int i;

    switch (queue) {
        case 1:
            array[rpos[0]] = 0;
            rpos[0] = rpos[0] + 1;

            break;
        case 2:
            array[rpos[1]] = 0;
            rpos[1] = rpos[1] + 1;

            break;
    }
}