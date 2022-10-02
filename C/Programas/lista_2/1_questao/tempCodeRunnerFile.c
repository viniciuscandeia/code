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
1 - 2pts) Escrever um programa em C que contenha uma estrutura que sirva para o 
cadastro de produtos em uma loja. Esta estrutura armazena o codigo do produto (int), 
o preço (float) e a descrição do produto (char *); declare um array para armazenar 
10 itens da estrutura definida. Faça o programa exibir um menu com as seguintes 
opções (e as realize através do uso de funções):
	a) Cadastrar produto
	b) Listar produtos cadastrados 
	c) Consultar preço e descrição a partir de código de produto
	d) Calcular média de preço dos produtos
	e) Sair
*/

typedef struct { // criando uma struct
    int codigo_produto; // declarando uma variável do tipo int chamada "codigo_produto"
    float preco; // declarando uma variável do tipo float chamada "preco"
    char *descricao; // declarando um ponteiro do tipo char chamada "descricao"
} tCadastro; // nomeando a struct com "tCadastro"

void verificacao_resposta(char *resposta){

    if (resposta[0] != 'A' && resposta[0] != 'a' && 
        resposta[0] != 'B' && resposta[0] != 'b' && 
        resposta[0] != 'C' && resposta[0] != 'c' && 
        resposta[0] != 'D' && resposta[0] != 'd' && 
        resposta[0] != 'E' && resposta[0] != 'e'){ // se "resposta" for diferente de "A", "B", "C", "D", "E", "a", "b", "c", "d" e "e"
        
        printf(cor_vermelha "\nESCOLHA INVALIDA!\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
        Sleep(1000); // sleep de 1 segundo

        while (true){ // while funcionará até a condição do "if" ser verdadeira
            system("cls"); // limpando tela
            printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização

            printf(cor_amarela "Escolha sua opcao: \n\n" cor_branca); // mostrando "Escolha sua opcao: " em amarelo
            printf(cor_amarela "a) " cor_branca "Cadastrar produto\n" // mostrando "a) " em amarelo e "Cadastrar produto" em branco
            cor_amarela "b) " cor_branca "Listar produtos cadastrados\n" // mostrando "b) " em amarelo e "Listar produtos cadastrados" em branco
            cor_amarela "c) " cor_branca "Consultar preco e descricao a partir de codigo de produto\n" // mostrando "c) " em amarelo e "Consultar preco e descricao a partir de codigo de produto" em branco
            cor_amarela "d) " cor_branca "Calcular media de preco dos produtos\n" // mostrando "d) " em amarelo e "Calcular media de preco dos produtos" em branco
            cor_amarela "e) " cor_branca "Sair\n"); // mostrando "e) " em amarelo e "Sair" em branco

            printf(cor_amarela "\n>> " cor_branca); // mostrando ">> " em amarelo 
            fgets(resposta, 2, stdin); // uso do fgets para registrar a resposta do usuário na variável "resposta"

            fflush(stdin); // limpar o buffer do teclado

            if (resposta[0] == 'A' || resposta[0] == 'a' || 
                resposta[0] == 'B' || resposta[0] == 'b' || 
                resposta[0] == 'C' || resposta[0] == 'c' || 
                resposta[0] == 'D' || resposta[0] == 'd' || 
                resposta[0] == 'E' || resposta[0] == 'e'){  // se "resposta" for igual a "A", "B", "C", "D", "E", "a", "b", "c", "d" ou "e"
                    break; // para finalizar o while
            } else {  // caso a condição não seja verdadeira
                printf(cor_vermelha "\nESCOLHA INVALIDA!\n" cor_branca); // mostrando "ESCOLHA INVALIDA" em vermelho
                Sleep(1000); // sleep de 1 segundo
            }
        }
    }

}

void cadastrar(int *contador, int tamanho, tCadastro *produto){
    char descricao_antes[1000];

    if (*contador <= tamanho - 1){ // verificando se a quantidade de produtos não passa de 10
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização

        printf("Codigo do produto: " cor_amarela ">> " cor_branca); // mostrando "Codigo do produto: " em branco e ">> " em amarelo
        scanf("%d", &produto[*contador].codigo_produto); // salvando a resposta do usuário em "produto[contador_produtos].codigo_produto"
        printf("Preco: " cor_amarela ">> " cor_branca); // mostrando "Preco: " em branco e ">> " em amarelo
        scanf("%f", &produto[*contador].preco); // salvando a resposta do usuário em "produto[contador_produtos].preco"
        printf("Descricao: " cor_amarela ">> " cor_branca); // mostrando "Descricao: " em branco e ">> " em amarelo
        scanf("%s", &descricao_antes);
        fflush(stdin); // limpar o buffer do teclado

        produto[*contador].descricao = malloc(strlen(descricao_antes) * sizeof(char));
        strcpy(produto[*contador].descricao, descricao_antes);
    
        printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
        printf(cor_verde "\nProduto cadastrado com sucesso!\n" cor_branca); // mostrando "Produto cadastrado com sucesso!" em verde
        Sleep(1000); // Sleep de 2 segundos

        *contador += 1; // aumentar em 1 a quantidade de produtos cadastrados
    }
    else { // quantidade de produtos ja passou de 10
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nao eh possivel adicionar mais itens!\n" cor_branca); // mostrando "Nao eh possivel adicionar mais itens!" em vermelho
        Sleep(2000); // Sleep de 2 segundos
    }

}

void listar(int contador, tCadastro *produto){

    if (contador == 0){ // se não tiver nenhum produto cadastrado
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nenhum produto cadastrado!\n" cor_branca); // mostrando "Nenhum produto cadastrado!" em vermelho
    }
    else {
        for(int i = 0; i < contador; i++){ //for para varrer todas as variáveis salvas em "produto"
            printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
            printf(cor_azul "Produto %d\n\n" cor_branca, i + 1); // mostrando "Produto (i + 1)" em azul
            printf("Codigo: ..... " cor_amarela "%d\n" cor_branca, produto[i].codigo_produto); // mostrando "Codigo: " em amarelo e "produto[i].codigo_produto" em branco
            printf("Preco: ...... " cor_amarela "R$ %.2f\n" cor_branca, produto[i].preco); // mostrando "Preco: " em amarelo e "produto[i].preco" em branco
            printf("Descricao: .. " cor_amarela "%s\n" cor_branca, produto[i].descricao); // mostrando "Descricao: " em amarelo e "produto[i].descricao" em branco
        }
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(5000); // Sleep de 5 segundos
}

void encontrar_produto(int contador, tCadastro *produto){
    int verificacao_codigo = 0;
    int codigo;

    if (contador == 0){ // se não tiver nenhum produto cadastrado
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nenhum produto cadastrado!\n" cor_branca); // mostrando "Nenhum produto cadastrado!" em vermelho
    }
    else {
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf("Digite o codigo do produto: " cor_amarela ">> " cor_branca);  // mostrando "Digite o codigo do produto: " em amarelo e ">> " em branco
        scanf("%d", &codigo); // "codigo" receberá o valor digitado pelo usuário
        fflush(stdin); // limpar o buffer do teclado

        for(int i = 0; i < contador; i++){ //for para varrer todas as variáveis salvas em "produto"
            if (codigo == produto[i].codigo_produto){ // verificando se o código digitado pelo usuário está em "produto"
                printf("\nPreco: .... " cor_amarela "R$ %.2f\n" cor_branca, produto[i].preco); // mostrando "Preco: " em branco e "produto[i].preco" em amarelo
                printf("Descricao: .. " cor_amarela "%s\n" cor_branca, produto[i].descricao); // mostrando "Descricao: " em branco e "produto[i].descricao" em amarelo
                verificacao_codigo += 1; // variável criada para informar se o código digitado pelo usuário está ou não em "produto"
            }
        }
        if (verificacao_codigo == 0){ // se "verificacao_codigo" for igual a 0, o código digitando pelo usuário não estava em "produto"
            printf(cor_vermelha "Nao ha nenhum produto cadastrado com esse codigo!\n" cor_branca); // mostrando "Nao ha nenhum produto cadastrado com esse codigo" em vermelho
        }
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(5000); // Sleep de 5 segundos
}

void media_precos(int contador, tCadastro *produto){
    float soma = 0;
    float media = 0;

    if (contador == 0){ // se não tiver nenhum produto cadastrado
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        printf(cor_vermelha "Nenhum produto cadastrado!\n" cor_branca); // mostrando "Nenhum produto cadastrado!" em vermelho
    }
    else{
        soma = 0; // zerando a variável "soma"
        for(int i = 0; i < contador; i++){ //for para varrer todas as variáveis salvas em "produto"
            soma += produto[i].preco; // somando "produto[i].preco" em "soma"
        }
        printf(cor_branca "\n----------------------------------------------------------------\n\n"); // separador para ajudar ma organização
        media = soma / contador;
        printf("Media dos produtos: " cor_amarela "R$ %.2f\n" cor_branca, media); // mostrando "Media dos produtos: " em amarelo e "(soma / contador_produtos)" em branco
    }

    printf(cor_branca "\n----------------------------------------------------------------\n"); // separador para ajudar ma organização
    printf(cor_amarela "\nRetornando ao inicio..." cor_branca); // mostrando "Retornando ao inicio..." em amarelo
    Sleep(5000); // Sleep de 5 segundos
}

int main() { 

    system("cls");

    char resposta[1]; // declarando uma variável do tipo char chamada "resposta" de tamanho 1
    int tamanho = 10; // declarando uma variável do tipo int chamada "tamanho" de valor 10
    int contador_produtos = 0; // declarando uma variável do tipo int chamada "contador_produtos" de valor 0
    int valor;

    tCadastro *produto_original; // declarando um ponteiro que seguirá a estrutura de tCadastro
    produto_original = (int*) malloc (tamanho * sizeof(int)); // alocando, dinamicamente, o tamanho do ponteiro "produto"

    while (resposta[0] != 'e'){ // while que ficará em loop até o usuário digitar "e"

        system("cls"); // limpando tela
        printf(cor_branca "================================================================\n\n"); // separador para ajudar ma organização

        printf(cor_amarela "Escolha sua opcao: \n\n" cor_branca); // mostrando "Escolha sua opcao: " em amarelo
        printf(cor_amarela "a) " cor_branca "Cadastrar produto\n" // mostrando "a) " em amarelo e "Cadastrar produto" em branco
        cor_amarela "b) " cor_branca "Listar produtos cadastrados\n" // mostrando "b) " em amarelo e "Listar produtos cadastrados" em branco
        cor_amarela "c) " cor_branca "Consultar preco e descricao a partir de codigo de produto\n" // mostrando "c) " em amarelo e "Consultar preco e descricao a partir de codigo de produto" em branco
        cor_amarela "d) " cor_branca "Calcular media de preco dos produtos\n" // mostrando "d) " em amarelo e "Calcular media de preco dos produtos" em branco
        cor_amarela "e) " cor_branca "Sair\n"); // mostrando "e) " em amarelo e "Sair" em branco

        printf(cor_amarela "\n>> " cor_branca); // mostrando ">> " em amarelo 
        fgets(resposta, 2, stdin); // uso do fgets para registrar a resposta do usuário na variável "resposta"

        fflush(stdin); // limpar o buffer do teclado

        verificacao_resposta(resposta);

        if (resposta[0] == 'A' || resposta[0] == 'a'){ // se "resposta" for igual a "A" ou "a"
            cadastrar(&contador_produtos, tamanho, produto_original);
        }

        if (resposta[0] == 'B' || resposta[0] == 'b'){ // se "resposta" for igual a "B" ou "b"
            listar(contador_produtos, produto_original);
        }

        if (resposta[0] == 'C' || resposta[0] == 'c'){ // se "resposta" for igual a "C" ou "c"
            encontrar_produto(contador_produtos, produto_original);
        }

        if (resposta[0] == 'D' || resposta[0] == 'd'){ // se "resposta" for igual a "D" ou "d"
            media_precos(contador_produtos, produto_original);
        }

    }

    printf("\n================================================================\n\n" cor_branca);

    return 0;
}
