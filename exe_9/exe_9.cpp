#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
 
// 9.Fazer uma função em "C" que retorna a razão entre dois números.
// A função deve retornar pelo comando return o valor 1 se a operação foi possível e o valor 0 se a operação não foi 
// possível (divisão por zero, por exemplo). O resultado da divisão deve retonar por um parâmetro por referência.

//função que soma 10 ao valor recebido
int dividir(int x, float y, float *result)
{
  try{
      if (y == 0) {
         throw 0;
      }
      *result = x / y;
      return 1;
  }catch(int e){
      return 0;
  }
}
int main(void)
{
  float x, y, resultado;
  int validacao;
  printf("Digite o numero Dividendo: ");
  scanf("%f", &x);
  printf("Digite o numero Divisor: ");
  scanf("%f", &y);  
       
  validacao = dividir(x, y, &resultado);
  if(validacao == 0){
      printf("Erro: divisor nao pode ser ZERO");
  } else {
      printf("Resultado da Divisao eh: %.2f", resultado);
  }
  return 0;
}