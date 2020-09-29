#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 
 * 10.Construir um programa em "C" que implementa uma agenda eletrônica.
 * O programa deve ter um menu com as seguintes opções:
 * • Entrar um novo nome na agenda.
 * • Imprimir na tela os dados de uma das pessoas cadastradas (conforme solicitação).
 * • Imprimir a lista de nomes cadastrados que comecem pela letra indicada.
 * • Fim
 * Cada entrada da agenda deve ter os seguintes campos: 
 * •char nome[30];
 * •char endereco[100];
 * •char fone[10]; 
 * •long int CEP; 
 * Obs: a agenda deve ter capacidade para 100 entradas.ARMAZENAR OS VALORES DA AGENDA EM UM ARQUIVO .TXT
 */

struct Pessoa
{
    char nome[30];
    char endereco[100];
    char fone[10]; 
    char CEP[10];
} pessoas[100];

enum Tabela
{
    coluna_nome = 1,
    coluna_endereco = 2,
    coluna_fone = 3,
    coluna_cep = 4
};

int n = 0;

void limparAgenda(){
    FILE *agenda = fopen("agenda.txt", "w");
    if (agenda != NULL) printf("\nAgenda Limpa!\n");
    fclose(agenda);
    for (int i = 0; i < n; i++)
    {
        strcpy(pessoas[i].nome, "");
        strcpy(pessoas[i].fone, "");
        strcpy(pessoas[i].endereco, "");
        strcpy(pessoas[i].CEP, "");
    }
    
    n = 0;
}

void lerAgenda(){
    char dado[255];
    char limpar;
    FILE *agenda = fopen("agenda.txt", "r");
    if (agenda == NULL){
        printf("Problemas na abertura do arquivo\nDeseja limpar a agenda? <S>im - <N>ao: ");
        scanf("%c", &limpar);
        if (limpar == 's' || limpar == 'S'){
            fclose(agenda);  
            limparAgenda();
        }
    }
    for (int linha = 0, coluna = 0; fscanf(agenda, "%[^;]%*c", dado) != EOF; coluna++){
        if (dado[0] == 10) // 10 = \n (ascii)
        {
            coluna = 0;
            linha++;
        }
        

        switch (coluna)
        {
        case coluna_nome:
            strcpy(pessoas[linha].nome, dado);
            break;
        case coluna_endereco:
            strcpy(pessoas[linha].endereco, dado);
            break;
        case coluna_fone:
            strcpy(pessoas[linha].fone, dado);
            break;
        case coluna_cep:
            strcpy(pessoas[linha].CEP, dado);
            break;
        default:
            break;
        }
        if(coluna == 0) n++;
    }
}

void novoNome() {
    char temQuebralinha[3];
    FILE *agenda;
    agenda = fopen("agenda.txt", "a+");
    if (agenda == NULL)
    {
        printf("Erro ao abrir o arquivo agenda.txt");
        return;
    }

    printf("Informe o nome da pessoa (maximo 30 caracteres): ");
    scanf("%s", pessoas[n].nome);
   
    printf("Informe o fone? ");
    scanf("%s", pessoas[n].fone);

    printf("Informe o endereco: ");
    scanf("%s", pessoas[n].endereco);

    printf("Informe o CEP: ");
    scanf("%s", pessoas[n].CEP);

    if(n == 0){
        strcpy(temQuebralinha, "");
    } else {
        strcpy(temQuebralinha, "\n");
    }

    fprintf(agenda, "%s;%d;%s;%s;%s;%s;", temQuebralinha, n + 1, pessoas[n].nome, pessoas[n].fone, pessoas[n].endereco, pessoas[n].CEP);
    n++;

    fclose(agenda);  
}

void listarTudo(){
    if(n == 0){
        printf("\nAgenda Vazia!\n");
    } else {
        for(int i = 0; i < n; i++){
            printf("Nome: %s\n", pessoas[i].nome);
            printf("Fone: %s\n", pessoas[i].fone);
            printf("Endereco: %s\n", pessoas[i].endereco);
            printf("CEP: %s\n\n", pessoas[i].CEP);
            system("pause");
        }
    }
}

void pesquisarPessoa(){
    char nome[30];
    printf("Digite o nome da pessoa para pesquisar!: ");
    scanf("%s", nome);
    for(int i = 0; i <= n; i++){
        if(strcmp(strlwr(nome), strlwr(pessoas[i].nome)) == 0){
            printf("\n\nEncontrada Pessoa %d\n", i + 1);
            printf("Nome: %s\n", pessoas[i].nome);
            printf("Fone: %s\n", pessoas[i].fone);
            printf("Endereco: %s\n", pessoas[i].endereco);
            printf("CEP: %s\n\n", pessoas[i].CEP);
            system("pause");
        }else{
            printf("Nenhuma Pessoa encontrada com os parametros informados!\n");
        }
    }
}

void ImprimirListaFiltradaPessoa(){
    char letra[30];
    printf("Digite a letra inicial da pessoa para pesquisar!");
    scanf("%s", letra);
    for(int i = 0; i <= n; i++){
        if(tolower(letra[0]) == tolower(pessoas[i].nome[0])){
            printf("\n\nEncontrada Pessoa %d\n", i + 1);
            printf("Nome: %s\n", pessoas[i].nome);
            printf("Fone: %s\n", pessoas[i].fone);
            printf("Endereco: %s\n", pessoas[i].endereco);
            printf("CEP: %s\n\n", pessoas[i].CEP);
            system("pause");
        }else{
            printf("Nenhuma Pessoa encontrada com os parametros informados!\n");
        }
    }
}

int menu(){
    int opcao;
    printf("\nOque deseja fazer?\n\n");
    printf("1) Nova pessoa.\n");
    printf("2) Perquisar Pessoa\n");
    printf("3) Imprimir a lista de nomes que comecem pela letra indicada\n");
    printf("4) Listar toda a agenda\n");
    printf("5) Resetar agenda\n");
    printf("6) Fim\n");
    scanf("%d", &opcao);
    return opcao;
}

int main(void){
    int opcao;
    struct Pessoa pessoa[100];
    printf("Agenda (limite 100 entradas)\n");

    lerAgenda();
    do{
        opcao = menu();
        switch (opcao)
        {
        case 1:
            novoNome();
            break;
        case 2:
            pesquisarPessoa();
            break;
        case 3:
            ImprimirListaFiltradaPessoa();
            break;
        case 4:
            listarTudo();
            break;
        case 5:
            limparAgenda();
            break;
        default:
            if(opcao != 6) printf("Opcao invalida! tente novamente\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}