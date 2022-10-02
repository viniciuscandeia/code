#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

#define cor_preta     "\033[30m"
#define cor_vermelha  "\033[31m"
#define cor_verde     "\033[32m"
#define cor_amarela   "\033[33m"
#define cor_azul      "\033[34m"
#define cor_magenta   "\033[35m"
#define cor_ciano     "\033[36m"
#define cor_branca    "\033[37m"

/*
1) (4 pontos) Faça um programa em C que implementa uma agenda eletrônica. Os
itens devem ser descritos por uma estrutura e armazenados em um array com 10
posições. O programa deve ter um menu com as seguintes opções:
- Cadastrar um novo item na agenda;
- Exibir na tela os dados de uma das pessoas cadastradas, por indice;
- Exibir a lista de nomes cadastrados que comecem por uma letra inserida;
- Sair

Os itens devem invocar funções que implementem as funcionalidades descritas.
A estrutura que descreve os itens da agenda devem possuir os seguintes campos:

char nome[30];
char endereco[100];
char fone[13];
long int CEP;
*/

struct informacao_agenda{
    char nome[30];
    char endereco[100];
    char fone[13];
    long int CEP;
};

void verificacao_resposta(char *resposta){ // criando uma função de nome "verificacao_resposta" que recebe um ponteiro de variável do tipo char com nome "resposta"

    if (resposta[0] != '1' && resposta[0] != '2' && 
        resposta[0] != '3' && resposta[0] != '4'){ // se "resposta" for diferente de "1", "2", "3", "4"
        
        printf(cor_vermelha "\nESCOLHA INVALIDA!\n\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
        printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização
        Sleep(1000); // sleep de 1 segundo

        while (true){ // while funcionará até a condição do "if" ser verdadeira
            system("cls"); // limpando tela
            printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização

            printf(cor_branca "Qual das opcoes a seguir, voce desejar usar? \n\n");
            printf(cor_amarela "1" cor_branca " - Cadastrar um novo item na agenda\n"
                   cor_amarela "2" cor_branca " - Exibir na tela os dados de uma das pessoas cadastradas, por indice\n"
                   cor_amarela "3" cor_branca " - Exibir a lista de nomes cadastrados que comecem por uma letra inserida\n"
                   cor_amarela "4" cor_branca " - Sair\n");

            printf(cor_vermelha "\n>> " cor_branca); // mostrando ">> " em amarelo 
            fgets(resposta, 3, stdin);
            fflush(stdin);

            if (resposta[0] == '1' || resposta[0] == '2' || 
                resposta[0] == '3' || resposta[0] == '4'){  // se "resposta" for igual a "1", "2", "3", "4"
                    break; // para finalizar o while
            } else {  // caso a condição não seja verdadeira
                printf(cor_vermelha "\nESCOLHA INVALIDA!\n\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
                printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização
                Sleep(1000); // sleep de 1 segundo
            }
        }
    }

}

void verificador_resposta_2(int *resposta, int quantidade_contatos, struct informacao_agenda *agenda){ // criando uma função de nome "verificacao_resposta" que recebe um ponteiro de variável do tipo char com nome "resposta"

    if (*resposta < 1 || *resposta > quantidade_contatos){ // se "resposta" for diferente de "1", "2", "3", "4"
        
        printf(cor_vermelha "\nESCOLHA INVALIDA!\n\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
        printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização
        Sleep(1000); // sleep de 1 segundo

        while (true){ // while funcionará até a condição do "if" ser verdadeira
            system("cls"); // limpando tela
            printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização

            printf(cor_branca "Qual das opcoes a seguir, voce desejar usar? \n\n");
            printf(cor_amarela "1" cor_branca " - Cadastrar um novo item na agenda\n"
                   cor_amarela "2" cor_branca " - Exibir na tela os dados de uma das pessoas cadastradas, por indice\n"
                   cor_amarela "3" cor_branca " - Exibir a lista de nomes cadastrados que comecem por uma letra inserida\n"
                   cor_amarela "4" cor_branca " - Sair\n");
            printf(cor_vermelha "\n>> 2\n" cor_branca); // mostrando ">> " em amarelo 
            printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
            printf("Qual dos contatos a seguir, voce desejar olhar seus dados? \n\n");
            for(int i = 0; i < quantidade_contatos; i++){
                printf(cor_amarela "%d" cor_branca, i + 1);
                printf(cor_branca " - Nome ..... : " cor_ciano "%s\n" cor_branca, agenda[i].nome);
            }

            printf(cor_vermelha "\n>> " cor_branca);
            scanf("%d", resposta);
            fflush(stdin);

            if (*resposta > 0 && *resposta < quantidade_contatos + 1){  // se "resposta" for igual a "1", "2", "3", "4"
                    break; // para finalizar o while
            } else {  // caso a condição não seja verdadeira
                printf(cor_vermelha "\nESCOLHA INVALIDA!\n\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
                printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização
                Sleep(1000); // sleep de 1 segundo
            }
        }
    }

}

void cadastrar_contato(struct informacao_agenda *agenda, int *quantidade_contatos){
    
    if (*quantidade_contatos < 9){

        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_amarela "Contato %d\n\n" cor_branca, *quantidade_contatos + 1);
        
        printf(cor_branca "Nome ..... : " cor_amarela ">> " cor_branca);
        fgets(agenda[*quantidade_contatos].nome, 30, stdin);
        fflush(stdin);
        agenda[*quantidade_contatos].nome[strlen(agenda[*quantidade_contatos].nome) - 1] = '\0';

        printf(cor_branca "Endereco . : " cor_amarela ">> " cor_branca);
        fgets(agenda[*quantidade_contatos].endereco, 100, stdin);
        fflush(stdin);
        agenda[*quantidade_contatos].endereco[strlen(agenda[*quantidade_contatos].endereco) - 1] = '\0';

        printf(cor_branca "Telefone . : " cor_amarela ">> " cor_branca);
        fgets(agenda[*quantidade_contatos].fone, 13, stdin);
        fflush(stdin);
        agenda[*quantidade_contatos].fone[strlen(agenda[*quantidade_contatos].fone) - 1] = '\0';

        printf(cor_branca "CEP ...... : " cor_amarela ">> " cor_branca);
        scanf("%ld", &agenda[*quantidade_contatos].CEP);
        fflush(stdin);

        *quantidade_contatos += 1;

        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_verde "Contato armazenado com sucesso!\n" cor_branca); // mostrando "Produto cadastrado com sucesso!" em verde

    } else {
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nao eh possivel adicionar mais contatos!\n" cor_branca); // mostrando "Nao eh possivel adicionar mais contatos!" em vermelho
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(2000);
}

void listar_contatos(struct informacao_agenda *agenda, int *quantidade_contatos){
    
    int resposta;

    if (*quantidade_contatos == 0){
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nenhum contato armazenado!\n" cor_branca); // mostrando "Nenhum produto cadastrado!" em vermelho
    } else {
    
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf("Qual dos contatos a seguir, voce desejar olhar seus dados? \n\n");

        for(int i = 0; i < *quantidade_contatos; i++){
            printf(cor_amarela "%d" cor_branca, i + 1);
            printf(cor_branca " - Nome ..... : " cor_ciano "%s\n" cor_branca, agenda[i].nome);
        }

        printf(cor_amarela "\n>> " cor_branca);
        scanf("%d", &resposta);
        fflush(stdin);

        verificador_resposta_2(&resposta, *quantidade_contatos, agenda);
        
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização

        printf(cor_branca "Nome ..... : " cor_ciano "%s\n" cor_branca, agenda[resposta - 1].nome);
        printf(cor_branca "Endereco . : " cor_ciano "%s\n" cor_branca, agenda[resposta - 1].endereco);
        printf(cor_branca "Telefone . : " cor_ciano "%s\n" cor_branca, agenda[resposta - 1].fone);
        printf(cor_branca "CEP  ..... : " cor_ciano "%ld\n" cor_branca, agenda[resposta - 1].CEP);
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(3000);

}

void contatos_com_letra_tal(struct informacao_agenda *agenda, int *quantidade_contatos){

    char resposta[3];
    int comparacao = 1;
    char caractere_nome[3];
    
    printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
    printf(cor_branca "Realizar busca por contatos que comecem com qual letra? \n\n");
    printf(cor_amarela ">> " cor_branca);
    fgets(resposta, 3, stdin);
    fflush(stdin);
    resposta[strlen(resposta) - 1] = '\0';

    printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização

    for(int i = 0; i < *quantidade_contatos; i++){
        caractere_nome[0] = agenda[i].nome[0];
        comparacao = strcmp(resposta, caractere_nome);
        if (comparacao == 0){
            printf(cor_branca "Nome ..... : " cor_ciano "%s\n" cor_branca, agenda[i].nome);
        }
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(3000);

}

int main() {

    system("cls");

    struct informacao_agenda *agenda;
    agenda = malloc (10 * sizeof(struct informacao_agenda));

    char resposta[3];
    int quantidade_contatos = 0;

    while (resposta[0] != '4'){

        system("cls");
        printf(cor_branca "================================================================\n\n" cor_branca);
    
        printf(cor_branca "Qual das opcoes a seguir, voce desejar usar? \n\n");
        printf(cor_amarela "1" cor_branca " - Cadastrar um novo item na agenda\n"
               cor_amarela "2" cor_branca " - Exibir na tela os dados de uma das pessoas cadastradas, por indice\n"
               cor_amarela "3" cor_branca " - Exibir a lista de nomes cadastrados que comecem por uma letra inserida\n"
               cor_amarela "4" cor_branca " - Sair\n");
        printf(cor_amarela "\n>> " cor_branca);
        fgets(resposta, 4, stdin);
        resposta[strlen(resposta) - 1] = '\0';

        verificacao_resposta(resposta);

        if (resposta[0] == '1'){ // Cadastrar novo item
            cadastrar_contato(agenda, &quantidade_contatos);
        }
        if (resposta[0] == '2'){ // Listar informações de um determinado contato
            listar_contatos(agenda, &quantidade_contatos);
        }
        if (resposta[0] == '3'){ // Procurar contatos por letra
            contatos_com_letra_tal(agenda, &quantidade_contatos);
        }
        if (resposta[0] == '4'){ // Sair
            break;
        }

    }

    printf(cor_branca "\n================================================================\n\n" cor_branca);

    free(agenda);

    return 0;
}
