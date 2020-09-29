#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
// 6.Fazer um programa em "C" que lê um conjunto de 10 valores
// inteiros e verifica se algum dos valores é igual a média dos mesmos.

int main(void){
    int numero[10], soma = 0;
    float media;
    for(int i = 0; i < 10; i++){
        printf("Digite o %d%c valor: ", i + 1, 167);
        scanf("%d", &numero[i]);
        soma = soma + numero[i];
    }
    media = (float)soma / 10;
    printf("%f", media);
    printf("%f", soma);
    for(int i = 0; i < 10; i++){
        if(numero[i] == media){
            printf("O %d%c n%cmero %c igual a m%cdia: n%cmero: %d, soma: %d, m%cdia: %f\n", i +1, 167, 163, 130, 130, 163, numero[i], soma, 130, media);
            break;
        }
    }
    return 0;
}