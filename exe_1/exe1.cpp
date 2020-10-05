#include <stdio.h>
#include <string.h>
#include <time.h>

// 1.Fazer um programa em "C" que lê o preço de um produto e 
// inflaciona esse preço em 10% se ele for menor que 100 e
// em 20% se ele for maior ou igual a 100. 
// OBS: não use o comando "if" ou o operador de condição "?". 

enum Log{
    inseriuValor = 1,
    inflacionou = 2,
    informouResultado = 3
};

void inserirLog(Log logType, float valor){
    FILE *log = fopen("log.txt", "a");
    if (log == NULL){
        printf("Ocorreu um erro ao tentar abrir o arquivo de log\n");
        return;
    }

    struct tm *local;
    time_t t;
    t= time(NULL);
    local=localtime(&t);

    int dia=local->tm_mday;
    int mes=local->tm_mon+1;
    int ano=local->tm_year+1900;
    int hora=local->tm_hour;
    int minuto=local->tm_min;
    int segundo=local->tm_sec;

    switch (logType)
    {
    case inseriuValor:
        fprintf(log, "%d/%d/%d %d:%d:%d - Inseriu valor: %.2f\n", dia, mes, ano, hora, minuto, segundo, valor);
        break;
    case inflacionou:
        fprintf(log, "%d/%d/%d %d:%d:%d - Inflacionou: %.2f\n", dia, mes, ano, hora, minuto, segundo, valor);
        break;
    case informouResultado:
        fprintf(log, "%d/%d/%d %d:%d:%d - Exibiu valor inflacionado: %.2f\n", dia, mes, ano, hora, minuto, segundo, valor);
        break;
    default:
        break;
        fprintf(log, "%d/%d/%d %d:%d:%d - Condicao nao tratada %d", dia, mes, ano, hora, minuto, segundo, logType);
    }
    fclose(log);
}

void prepararMensagem(char texto[100], char *mensagem, float valor){
    
    char log[30];
    snprintf(log, 7, "%.2f", valor);

    printf("%f\n", valor);
    printf("%s\n", log);
    printf("%s\n", texto);
    strcat(texto, log);
    
    strcpy(mensagem, texto);
}

int main (void){
    float valor, inflacao;
    char percentual[10], *mensagem[100];
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    inserirLog(inseriuValor, valor);
    
    switch (valor < 100.00)
    {
        case true:
            inflacao = valor * .1;
            strcpy(percentual, "10%");
            inserirLog(inflacionou, inflacao);
            break;
        case false:
            inflacao =  valor * .2;
            strcpy(percentual, "20%"); 
            inserirLog(inflacionou, inflacao);
            break;
    }

    printf("O valor informado R$ %.2f foi inflacionado em R$ %.2f (%s)\nValor final = R$ %.2f", valor, inflacao, percentual, valor + inflacao);
    inserirLog(informouResultado, valor + inflacao);
    return 0;
}