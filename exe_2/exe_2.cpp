#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// 2.Fazer um programa que lê um valor, um operador (+,-,*,/) 
// e outro valor e imprime o resultado da expressão:
// <valor 1> <operador> <valor 2>

int main (void){
    float valor1, valor2, result;
    int novo;
    char operador[1];
    bool sair = false;
    
    printf("Calculadora em C\n\n");

    while (!sair){
        printf("Digite um numero\n");
        scanf("%f", &valor1);
        
        do{
            printf("Digite a operacao (+, -, *, /)\n");
            scanf(" %s", &operador);
        }
        while(strcmp(operador, "+") != 0 &&
              strcmp(operador, "-") != 0 && 
              strcmp(operador, "*") != 0 &&
              strcmp(operador, "/") != 0);

        printf("Digite outro numero\n");
        scanf("%f", &valor2);

        switch (*operador)
        {
        case '+':
            result = valor1 + valor2;
            break;
        case '-':
            result = valor1 - valor2;
            break;
        case '*':
            result = valor1 * valor2;
            break;
        case '/':
            if (valor2 == 0) {
                printf("Erro! Divisao por Zero");
                break;
            }
            result = valor1 / valor2;
            break;
        default:
            break;
        }
        printf("\n%.2f\n", result);
        system("pause");
        system("cls");
        printf("Deseja fazer outra operacao?\n1 - Sim, 2 - Nao\n");
        scanf(" %d", &novo);
        if(novo != 1){
            sair = true;
        }

    }
    return 0;
}