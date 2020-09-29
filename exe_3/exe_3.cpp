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

float perguntarNota(int numeroAluno){
    float nota;
        do{
            printf("Digite a nota do aluno %d: \n", numeroAluno);
            scanf(" %f", &nota);
            
            if(nota == 50 && numeroAluno == 1) sair();
            if(nota >= 0 && nota <=10) return nota;

            printf("Entrada invalida! A nota deve estar entre 0 e 10 ou 50 para sair\n");
        }
        while(nota < 0 || nota > 10);
}

int main (void){
    float nota1, nota2;
    int aluno = 0;
    printf("\n\n .: Calculadora de Medias dos alunos :.\n\t(Digite 50 para sair)\n\n");

    while (true){        
        nota1 = perguntarNota(1);
        nota2 = perguntarNota(2);
        aluno++;
        printf("Media do %d%c aluno: %.2f\n\n", aluno, 167, (nota1 + nota2)/2);
    }
    return 0;
}