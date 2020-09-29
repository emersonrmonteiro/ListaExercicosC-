#include <stdio.h>

// 1.Fazer um programa em "C" que lê o preço de um produto e 
// inflaciona esse preço em 10% se ele for menor que 100 e
// em 20% se ele for maior ou igual a 100. 

float inflacionar(float valor, float inflacao){
    return valor + (valor * inflacao);
}

int main (void){
    float valor, result;
    printf("Digite o valor do produto!");
    scanf("%f", &valor);
    
    for(float i = valor; i < 100; i = 100){
        result = inflacionar(valor, .1);
    }

    for(float i = valor; i >= 100; i = 99){
        result = inflacionar(valor, .2);
    }

    printf("%.2f", result);
    return 0;
}