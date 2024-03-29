/*Codigo exemplo incompleto, utilizando struct com ponteiro */

/*1 - Faça um tratamento de erro para que o algoritmo verifique se a memoria foi alocada corretamente. */

/*2 - Adicione os demais campos da estrutura nas funcoes inputval e showval*/

/*3 - Comente o código explicando o que está sendo feito nas linhas 48 e 49 explicando a diferença entre elas.*/

/*4 - Faça uma função que verifique se uma ação esta com um ROE maior que 30 e o Dividend Yield maior que 10 */

/*5 - Sugerir melhorias no código */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Definição do tipo
typedef struct valuation
{
    char business_name[30];
    char stock_name[6];
    float stock_value;
    float dy;
    float lp;
    float ROE;
} tValuation;

//Cabecalho das funcoes
int inputval(tValuation *in_stock);
int showval(tValuation *in_stock);
int verifyVal(tValuation *in_stock);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int i;

    tValuation stocks[10];

    inputval(stocks);
    showval(stocks);
    // verifyVal(stocks);

    free(stocks);

    return 0;
}

int inputval(tValuation *in_stock)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o nome da empresa: ");
        setbuf(stdin, NULL);
        fgets(in_stock[i].business_name, 30, stdin);

        printf("Digite o nome da acao: ");
        setbuf(stdin, NULL);
        fgets(in_stock[i].stock_name, 30, stdin);

        printf("Digite o valor por cada acao: ");
        scanf("%f", &in_stock[i].stock_value);

        printf("Digite o valor pago em dividendos pela empresa em 2020: ");
        scanf("%f", &in_stock[i].dy);

        printf("Digite o LP da empresa em 2020: ");
        scanf("%f", &in_stock[i].lp);

        printf("Digite o ROE da empresa em 2020: ");
        scanf("%f", &in_stock[i].ROE);

        printf("\n%p\n", in_stock);
        printf("\n%p\n", &in_stock[i].dy);

        in_stock = NULL;
    }

    // printf("Digite o nome da empresa: ");
    //     setbuf(stdin, NULL);
    //     fgets(in_stock[i].business_name, 30, stdin);

    //     printf("Digite o nome da acao: ");
    //     setbuf(stdin, NULL);
    //     fgets(in_stock[i].stock_name, 30, stdin);

    //     printf("Digite o valor por cada acao: ");
    //     scanf("%f", &in_stock[i].stock_value);

    //     printf("Digite o valor pago em dividendos pela empresa em 2020: ");
    //     scanf("%f", &in_stock[i].dy);

    //     printf("Digite o LP da empresa em 2020: ");
    //     scanf("%f", &in_stock[i].lp);

    //     printf("Digite o ROE da empresa em 2020: ");
    //     scanf("%f", &in_stock[i].ROE);

    //     printf("\n%p\n", in_stock);
    //     printf("\n%p\n", &in_stock[i].dy);

    //     in_stock = NULL;

    return 0;
}

int showval(tValuation *in_stock)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("O nome da empresa e: %s \n", in_stock[i].business_name);
        printf("O nome da acao e: %s \n", in_stock[i].stock_name);

        printf("O valor da acao e: %f \n", in_stock[i].stock_value);
        printf("O valor do dividendo pago pela empresa foi: %.2f\n", in_stock[i].dy);
        printf("O LP de 2020 foi: %.2f \n", in_stock[i].lp);
        printf("O ROE de 2020 foi: %.2f \n", in_stock[i].ROE);
    }

    return 0;
}

// int verifyVal(tValuation *in_stock[]) {
//     printf("\n\n");

//     if (in_stock->ROE > 30) {
//         printf("O ROE e maior do que 30. ROE: %f\n", in_stock->ROE);
//     } else {
//         printf("O ROE e menor do que 30. ROE: %f\n", in_stock->ROE);
//     }

//     if (in_stock->dy > 10) {
//         printf("O DY e maior do que 10. DY: %f\n", in_stock->dy);
//     } else {
//         printf("O DY e menor do que 10. DY: %f\n", in_stock->dy);
//     }
// }