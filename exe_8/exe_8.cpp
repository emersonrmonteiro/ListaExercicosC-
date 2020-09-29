#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
 // 8.Fazer um programa em "C" que leia nomes de pessoas compostos por um prénome
 // e um sobrenome separados por um espaço em branco e imprima:
 // -A lista de nomes em ordem alfabética do pré-nome;
 // -A lista de nomes em ordem alfabética de sobrenomes;
 // -O número médio de letras por nome.
 
 struct Nome
 {
     char nome[50];
     char sobrenome[50];
 };
 

void ordenaPorNome(Nome *nome, int n){
{
    Nome temp;
    for(int i = 0; i < n; i++)
    {
        for(int e = 0; e < n; e++)
            {
                if(stricmp(nome[e].nome, nome[i].nome) > 0)
                {
                    temp = nome[i]; 
                    nome[i] = nome[e];
                    nome[e] = temp;
                }
            }
        }
    }
}

void ordenaPorSobrenome(Nome *nome, int n){
    Nome temp;
    for(int i = 0; i < n; i++)
    {
        for(int e = 0; e < n; e++)
        {
            if(stricmp(nome[e].sobrenome, nome[i].sobrenome) > 0)
            {
                temp = nome[i]; 
                nome[i] = nome[e];
                nome[e] = temp;
            }
        }
    }
}

float mediacalculaMediaLetrasPorNome(Nome *nome, int n){
    int contLetras = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%s", nome[i].nome);
        contLetras = contLetras + strlen(nome[i].nome);
    }
    return contLetras / n;
}

int main(void){
    float media;
    int n, opcao, contador = 0;
    char  sair[1];
    printf("digite a quantidade de nomes ");
    scanf("%d", &n);
    Nome *nome = (Nome *)malloc(sizeof(Nome) * n);
    for(int i = 0; i < n; i++){
        printf("Digite o nome <Pressione ENTER> en seguida digite o sobrenome da %d%c pessoa: \nNome: ", i + 1, 166);
        scanf("%s", nome[i].nome);
        printf("Sobrenome: ");
        scanf("%s", nome[i].sobrenome);
    }

    for(int i = 0; i < n; i++){
        printf("nome: %s\n", nome[i].nome);
        printf("sobrenome: %s\n", nome[i].sobrenome);
    }

    printf("Escolha uma op%c%co:\n\t1 para ordernar por nome\n\t2 para ordernar por sobrenome\n\t3 para exibir o n%cmero medio de letras\n", 135, 198, 163);   
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        ordenaPorNome(nome, n);
        printf("Ordenado por Nome\n");
        for(int i = 0; i < n; i++){
            printf("\b%s %s\n", nome[i].nome, nome[i].sobrenome);
        }
        break;
    case 2:
        ordenaPorSobrenome(nome, n);
        printf("Ordenado por Sobrenome\n");
        for(int i = 0; i < n; i++){
            printf("\b%s %s\n", nome[i].nome, nome[i].sobrenome);
        }
        break;
    case 3:
        printf("%n", n);
        media = mediacalculaMediaLetrasPorNome(nome, n);
        printf("O numero medio de letras por nome eh: %.2f", media);
        break;
    default:
        break;
    }

    return 0;
}