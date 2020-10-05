#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// 4.Exercício: fazer um programa em "C" que solicita o total
// gasto pelo cliente de uma loja,
// imprime as opções de pagamento, solicita a opção desejada e
// imprime o valor total das prestações (se houverem).
// 1) Opção: a vista com 10% de desconto
// 2) Opção: em duas vezes (preço da etiqueta)
// 3) Opção: de 3 até 10 vezes com 3% de juros ao mês
// (somente para compras acima de R$ 100,00).

void sair(){
    system("pause");
    exit(1);
}

int main (void){
    float valor, desconto, juros, parcela, resultado;
    int opcao, parcelas, resto, continuar = 0;
    do{
        printf("Digite o total gasto na loja\n");
        printf("Valor: ");
        scanf("%f", &valor);
        printf("Escolha a opcao de pagamento:\n\n");
        do{
            printf("1) Op%c%co: a vista com 10%c de desconto\n", 135, 198, 37);
            printf("2) Op%c%co: em duas vezes (pre%co da etiqueta)\n", 135, 198, 135);
            if(valor > 100.00) {
                printf("3) Op%c%co: de 3 ate 10 vezes com 3%c de juros ao m%cs\n", 135, 198, 37, 136);
            }
            printf("Opc%c%co: ", 135, 198);
            scanf("%d", &opcao);

            if(valor < 100.00 && opcao == 3){
                printf("Op%c%co 3 permitida somente se Valor for maior que R$ 100,00\n", 135, 198);
                opcao = 0;
            }
            if(opcao < 1 || opcao > 3 ){
                printf("Op%c%co inv%clida! Digite o n%cmero da op%c%Co de pagamento\n",135, 198, 160, 163, 136, 198);
                opcao = 0;
            }
        } while(opcao == 0);

        switch (opcao)
        {
        case 1:
            desconto = valor * .1;
            resultado = valor - desconto;
            printf("-----------------\n");
            printf("Valor gasto: R$ %.2f\n", valor);
            printf("10%c Desconto: R$ %.2f\n", 37, desconto);
            printf("-----------------\n");
            printf("Pagar a vista: R$ %.2f\n", resultado);
            printf("-----------------\n");
            break;
        case 2:
            parcela = valor / 2;
            printf("-----------------\n");
            printf("Em duas vezes (pre%co da etiqueta)\n", 135);
            printf("-----------------\n");
            printf("1%c parcela: R$ %.2f\n", 166, parcela);
            printf("1%c parcela: R$ %.2f\n", 166, parcela);
            printf("-----------------\n");
            break;
        case 3:
            do{
                printf("Digite a quantidade de parcelas (3 a 10)\n");
                printf("Parcelas: ");
                scanf("%d", &parcelas);
                if(parcelas < 3 || parcelas > 10){
                    printf("Quantidade de parcelas indispon%civel na op%c%c de pagamento 3\n", 161, 135, 198);
                    parcelas = 0;
                }
            }while(parcelas == 0);
            juros =  (valor * .03);
            parcela = (valor + juros) / parcelas;
            printf("-----------------\n");
            printf("Valor gasto: R$ %.2f\n", valor);
            printf("3%c Juros: R$ %.2f\n", 37, juros);
            printf("Total com juros: R$ %.2f\n", valor + juros);
            printf("-----------------\n");
            for(int i = 1; i <= parcelas; i ++){
                printf("%d%c parcela: R$ %.2f\n", i, 166, parcela);
            }
            printf("-----------------\n");
            break;
        default:
            printf("Op%c%co nao tratada", 135, 198);
            break;
        }
        printf("Deseja inserir um novo valor? 1-Sim, 2-Nao: ");
        scanf("%d", &continuar);
    }
    while(continuar == 1);

    return 0;
}