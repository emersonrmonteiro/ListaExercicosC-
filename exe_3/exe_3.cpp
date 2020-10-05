#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// 3.Escrever um programa em "C" que solicita as notas das duas
// provas feitas por cada um dos alunos de uma turma
// (as notas tem de estar no intervalo [0 10]) e imprime para 
// cada um a média das notas. O programa deve para imediatamente 
// após ter sido digitado o valor 50 para a nota da primeira prova.

void sair(){
    system("pause");
    exit(1);
}

typedef struct Notas{
    float nota[2];
};

void limpaHistorico(){
    FILE *historico = fopen("historico.txt", "w");
    fclose(historico);
}

void inserirHistorico(Notas notas, int aluno, float media){
    FILE *historico = fopen("historico.txt", "a");
    if (historico == NULL) printf("Ocorreu um erro ao tentar abrir o arquivo de log");
    
    fprintf(historico, "Aluno %d\t 1-Nota: %.2f,\t2-Nota: %.2f,\tMedia: %.2f\n", aluno, notas.nota[0], notas.nota[1], media);

    fclose(historico);
}

Notas perguntarNotas(int aluno){
    struct Notas notas;
    bool invalido;
    for(int i = 0; i < 2; i++){
        do{
            printf("Digite a %i nota do aluno %d: ", i + 1 , aluno);
            scanf(" %f", &notas.nota[i]);
            if(notas.nota[i] == 50 && i == 0) sair();
            invalido = false;
            if(notas.nota[i] < 0 || notas.nota[i] > 10){
                printf("Entrada invalida! A nota deve estar entre 0 e 10 ou 50 para sair\n");
                invalido = true;
            }
        }
        while(invalido);
    }
    return notas;
}

int main (void){
    struct Notas notas;
    float media;
    int aluno = 1;
    limpaHistorico();
    printf("\n\n .: Calculadora de Medias dos alunos :.\n\t(Digite 50 para sair)\n\n");

    while (true){        
        notas = perguntarNotas(aluno);
        media = (notas.nota[0] + notas.nota[1]) / 2;
        printf("Aluno %d\t 1-Nota: %.2f\t2-Nota: %.2f,\tMedia: %.2f\n", aluno, notas.nota[0], notas.nota[1], media);
        inserirHistorico(notas,aluno, media);
        aluno++;
    }
    return 0;
}