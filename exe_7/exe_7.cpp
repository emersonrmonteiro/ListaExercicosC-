#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
 // 7.Fazer um programa que lê valores para uma matriz do tipo
 // "float" de 5 linhas por 3 colunas e imprime a diferença entre
 // a média dos elementos das colunas pares e a média dos elementos das linhas ímpares.

 int main(void){
     float numero[5][3], somaColunaPar = 0, somaLinhaImpar = 0;
     int contPar = 0, contImpar = 0;
     for(int l = 0; l < 5; l++){
         for(int c = 0; c < 3; c++){
             printf("Digite um n%cmero para a linha: %d, coluna: %d: ", 163, l + 1, c + 1);
             scanf("%f", &numero[l][c]);
             if((c+1) % 2 == 0){
                 somaColunaPar = somaColunaPar + numero[l][c];
                 contPar++;

             } 
             if((l+1) % 2 == 1){
                 somaLinhaImpar = somaLinhaImpar + numero[l][c];
                 contImpar++;
             }
         }
     }
     printf("\n\t\tMatriz resultante\n\n");
     printf("\tColuna_1\tColuna_2\tColuna_3\n");
    for(int l = 0; l < 5; l++){
     printf("linha_%d\t", l+1);
        for(int c = 0; c < 3; c++){
            printf("[%f]\t", numero[l][c]);
        }
        printf("\n");
    }
    printf("\nA medida = soma das colunas pares (%f) / quantidade (%d) = %f\n", somaColunaPar, contPar , somaColunaPar / contPar);
    printf("A medida = soma das linhas impares (%f) / quantidade (%d) = %f\n", somaLinhaImpar, contImpar , somaLinhaImpar / contImpar);
    printf("A diferen%ca da m%cdia dos elementos da colunas pares com as colunas impares %c: %f", 135, 130, 130, (somaColunaPar / contPar) - (somaLinhaImpar / contImpar));

     return 0;
 }