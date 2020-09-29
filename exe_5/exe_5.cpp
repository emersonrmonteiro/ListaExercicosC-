#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
 // 5. Fazer uma rotina que recebe um array do tipo double e o número de valores
 // que devem ser solicitados ao usuário e devolve o array preenchido com os valores digitados.
 
double* preencheArray(double *array, int numero){
    double digito;
    for(int i = 1; i <= numero; i++){
        printf("Digite o %d%c numero\n", i, 167);
        printf("N%cmero: ", 163);
        scanf("%lf", &digito);
        array[i-1] = digito;
    }
    return array; 
}

 int main(void){
    int numero;
    printf("Digite o n%cmero de n%cmeros que deseja digitar para preencher o array\n", 163, 163);
    printf("Quantidade: ");
    scanf("%d", &numero);

    double *array = (double *)malloc(sizeof(double) * numero);
    array = preencheArray(array, numero);

    for(int i = 1; i <= numero; i++){
        printf("%d%c n%cmero: %lf\n", i, 167, 163, array[i - 1]);
    }
    return 0;
 }