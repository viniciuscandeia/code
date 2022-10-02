import os
from random import randint
from time import sleep
from funcoesSecundarias import *

# * Definindo cores para usar no terminal.
corBranca = str("\033[0m")
corVermelha = str("\033[31m")
corVerde = str("\033[32m")
corAmarela = str("\033[33m")
corAzul = str("\033[34m")
corMagenta = str("\033[35m")
corCiano = str("\033[36m")

# * Função para limpar o terminal.
def limparTerminal():

    command = 'clear'

    # ! Se o código for compilado em uma máquina com Windows
    if os.name in ('nt', 'dos'):
        command = 'cls'
    os.system(command)

# * Função para criar uma linha, com o objetivo de organizar o código.
def tracoLinha(valor: int):

    print(corCiano + "\n" * valor + ">" + corBranca + "-", end='')

    for contador in range(0, 24):

        if contador % 2 == 0:
            print(corVermelha + "<>" + corBranca, end='')
        else:
            print(corCiano + "<>" + corBranca, end='')

        print("-", end='')

    print(corCiano + "<" + corBranca + "\n")

# * Função para verificar se o número passado está dentro do intervalo.
def verificadorNumero(ladoEsquerdo: int, ladoDireito: int, numero: int):

    if numero < ladoEsquerdo or numero > ladoDireito:

        tracoLinha(1)
        print(corVermelha + "Resposta inválida!" + corBranca)
        tracoLinha(1)

        while numero < ladoEsquerdo or numero > ladoDireito:
            numero = int(input(" >> Opção: "))

            if numero < ladoEsquerdo or numero > ladoDireito:

                tracoLinha(1)
                print(corVermelha + "Resposta inválida!" + corBranca)
                tracoLinha(1)

    return numero

# * Função para verificar a resposta passada.
def verificadorResposta(resposta: str, caso: int):

    if caso == 0:

        if resposta != "0" and resposta != "1" and resposta != "2" and resposta != "3":

            tracoLinha(1)
            print(corVermelha + "Resposta inválida!" + corBranca)
            tracoLinha(1)

            while resposta != "0" and resposta != "1" and resposta != "2" and resposta != "3":
                resposta = str(input(f" >> Opção: ")).upper()

                if resposta != "0" and resposta != "1" and resposta != "2" and resposta != "3":

                    tracoLinha(1)
                    print(corVermelha + "Resposta inválida!" + corBranca)
                    tracoLinha(1)

    if caso == 1:

        if resposta != "S" and resposta != "N":

            tracoLinha(1)
            print(corVermelha + "Resposta inválida!" + corBranca)
            tracoLinha(1)

            while resposta != "S" and resposta != "N":
                resposta = str(input(f" >> Opção: ")).upper()

                if resposta != "S" and resposta != "N":

                    tracoLinha(1)
                    print(corVermelha + "Resposta inválida!" + corBranca)
                    tracoLinha(1)

    return resposta

# * Função para verificar se o arquivo está seguindo o padrão.
# Esta função fará, ao todo, 31 testes para verificar se o arquivo foi construído
# de maneira correta.
def verificadorArquivo(enderecoArquivo: str):

    numeroLinhas: int = 0
    retorno: int = 0

    numeroLinhas, retorno = testeEspacos(enderecoArquivo)
    if retorno == 0:
        return 0

    # * Abrindo o arquivo com as informações
    meuArquivo = open(enderecoArquivo, "r")

    tamanhoLinha: int = 0
    numeroVirgula: int = 0
    numeroVariaveis: int = 0
    numeroTerminais: int = 0
    contadorLinha: int = 0

    presencaEpsilon: bool = False

    listaTerminais: list = []
    listaVariaveis: list = []
    listaEpsilon: list = []
    dicionarioProducoes: dict = {}

    for linha in meuArquivo:

        if contadorLinha == 0:

            tamanhoLinha = len(linha[10: linha.find("\n")])
            numeroVirgula = linha[10: linha.find("\n")].count(",")
            listaTerminais = linha[10: linha.find("\n")].split(",")

            while(True):
                if "" in listaTerminais:
                    listaTerminais.remove("")
                if listaTerminais.count("") == 0:
                    break

            numeroTerminais = len(listaTerminais)

            # Teste 2 : "terminais=" não ocupar a posição [0:10]
            retorno = grupoTesteNomes(linha, "terminais=", meuArquivo)
            if retorno == 0:
                return 0

            # Teste 3 : Não ter nenhum terminal (= )
            retorno = grupoTesteDois(tamanhoLinha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 4 : Sem nenhum terminal após uma vírgula (=1,)
            retorno = grupoTesteTres(linha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 5 : Mais vírgulas do que terminais (=1,,)
            retorno = grupoTesteQuatro(numeroTerminais, numeroVirgula, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 6 : O cenário: =,0
            retorno = grupoTesteCinco(linha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 7 : Ter mais de 1 terminal entre vírgulas (,01,)
            # Teste 8 : Ter mais de 1 terminal igual (1,1)
            retorno = grupoTesteSete(listaTerminais, "terminal",meuArquivo)
            if retorno == 0:
                return 0

            # Teste 9 : Ter 2 vírgulas seguidas (,,)
            retorno = grupoTesteSeis(linha, meuArquivo)
            if retorno == 0:
                return 0

        elif contadorLinha == 1:

            tamanhoLinha = len(linha[10: linha.find("\n")])
            numeroVirgula = linha[10: linha.find("\n")].count(",")
            listaVariaveis = linha[10: linha.find("\n")].split(",")

            while(True):
                if "" in listaVariaveis:
                    listaVariaveis.remove("")
                if listaVariaveis.count("") == 0:
                    break

            numeroVariaveis = len(listaVariaveis)

            # Teste 2 : "variaveis=" não ocupar a posição [0:10]
            retorno = grupoTesteNomes(linha[0:10], "variaveis=", meuArquivo)
            if retorno == 0:
                return 0

            # Teste 3 : Não ter nenhuma variável (= )
            retorno = grupoTesteDois(tamanhoLinha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 4 : Sem nenhuma variável após uma vírgula (=1,)
            retorno = grupoTesteTres(linha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 5 : Mais vírgulas do que variáveis (=1,,)
            retorno = grupoTesteQuatro(numeroVariaveis, numeroVirgula, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 6 : O cenário: =,0
            retorno = grupoTesteCinco(linha, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 7 : Ter mais de 1 variável entre vírgulas (,01,)
            # Teste 8 : Ter mais de 1 variável igual (1,1)
            retorno = grupoTesteSete(listaTerminais, "variáveis",meuArquivo)
            if retorno == 0:
                return 0

            # Teste 9 : Ter 2 vírgulas seguidas (,,)
            retorno = grupoTesteSeis(linha, meuArquivo)
            if retorno == 0:
                return 0

        elif contadorLinha == 2:

            inicial = linha[8: linha.find("\n")]

            # Teste 2 : "inicial=" não ocupar a posição [0:8]
            retorno = grupoTesteNomes(linha[0:8], "inicial=", meuArquivo)
            if retorno == 0:
                return 0

            # Teste 10 : Ter mais de uma variável
            # Teste 11 : Não ter nada além do "="
            # Teste 12 : O inicial não está na lista de variáveis
            retorno = testeInicial(inicial, listaVariaveis, meuArquivo)
            if retorno == 0:
                return 0

        elif contadorLinha == 3:

            # Teste 2 : "producoes" não ocupar a posição [0:9]
            retorno = grupoTesteNomes(linha[0:9], "producoes", meuArquivo)
            if retorno == 0:
                return 0

            # Teste 13 : Não ter apenas "producoes"
            retorno = testeProducoes(linha, meuArquivo)
            if retorno == 0:
                return 0

        else:

            # Teste 14 : Ter uma variável que não está na lista de variáveis
            # Teste 15 : "->" não ocupar a posição [1:3]
            # Teste 16 : Nada após "->"
            retorno = grupoTesteProducoes(linha, listaVariaveis, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 17 : A nova parte não está presente na lista de terminais, nem na de variáveis.
            parteFinal: str = linha[3: linha.find("\n")]
            retorno = testeProducoes2(parteFinal, listaTerminais, listaVariaveis, meuArquivo)
            if retorno == 0:
                return 0

            # Teste 18 : Produção repetida
            retorno, dicionarioProducoes = testeProducoes3(linha, parteFinal, dicionarioProducoes, meuArquivo)
            if retorno == 0:
                return 0
            
            if contadorLinha == numeroLinhas - 1:
                for variavel in listaVariaveis:

                    if variavel in dicionarioProducoes:
                        if "epsilon" in dicionarioProducoes[variavel]:
                            presencaEpsilon = True
                            listaEpsilon.append(variavel)

                    # Teste 19 : Variável não usada
                    retorno = testeProducoes4(variavel, dicionarioProducoes, meuArquivo)
                    if retorno == 0:
                        return 0
           
        contadorLinha += 1

    # Teste 20 : Não tem "epsilon"
    # Teste 21 : Tem que ter um caminho que chegue no "epsilon"
    retorno = testeProducoes5(presencaEpsilon, contadorLinha, numeroLinhas, listaEpsilon, listaVariaveis, dicionarioProducoes, inicial, meuArquivo)
    if retorno == 0:
        return 0
    
    # * Fechando o arquivo
    meuArquivo.close()

    return 1

# * Função para gerar a cadeia utilizando o "Modo Rápido".
# ! Como funciona?
# O programa irá ler as produções e criar um dicionário com elas.
# Após isso, será criado uma cadeia de maneira aleatória, de forma automática.
def gerarCadeiaRapido(enderecoArquivo: str):

    limparTerminal()
    tracoLinha(0)

    # * Abrindo o arquivo com as informações
    arquivoPronto: int = verificadorArquivo(enderecoArquivo)
    if arquivoPronto == 0:
        return - 1

    meuArquivo = open(enderecoArquivo, "r")

    listaProducoesFim = []
    listaVariaveis = []
    informacoes = {}

    listaVariaveis, inicial, listaProducoesFim, informacoes = informacoesArquivos(meuArquivo, listaVariaveis, listaProducoesFim, informacoes)

    # * Fechando o arquivo
    meuArquivo.close()

    cadeia: str = inicial
    variavel: str = inicial
    valor: int = -1

    listaDerivacoes = [inicial]

    # * Fazendo todas as derivações.
    while True:

        valor += 1

        # ! Gerando um valor aleatório.
        numeroGerado = randint(0, len(informacoes[variavel]) - 1)

        # ! Trocando a 1° "variavel" encontrado por uma das derivações de "variavel" que está no dicionário.
        simulacao = cadeia.replace(
            variavel, informacoes[variavel][numeroGerado], 1)

        # ! Se a derivação resultar em adicionar o "epsilon" à cadeia, irá remover o 1° "epsilon" por "".
        if "epsilon" in simulacao:
            simulacao = simulacao.replace("epsilon", "", 1)

        # ! Se a cadeia gerada estiver na lista que contém todas as derivações, gerará uma nova cadeia.
        if simulacao in listaDerivacoes:

            # & Ficará em loop até que a cadeia gerada não esteja na lista.

            """ 
            Note que, caso a gramática seja ambígua, é possível que uma mesma cadeia possa ser 
            gerada por múltiplas derivações mais à esquerda. Entretanto, o programa não deve 
            mostrar a mesma derivação mais de uma vez, o que implica que a geração da cadeia 
            não pode ser feita de forma aleatória.
            """

            while simulacao in listaDerivacoes:
                simulacao = cadeia

                numeroGerado = randint(
                    0, len(informacoes[variavel]) - 1)

                simulacao = cadeia.replace(
                    variavel, informacoes[variavel][numeroGerado], 1)

                if "epsilon" in simulacao:
                    simulacao = simulacao.replace("epsilon", "", 1)

        # ! Adicionando a cadeia gerada na lista.
        listaDerivacoes.append(simulacao)

        frase = f"{valor : 3} : " + cadeia
        print(frase + f'{" " * (55 - len(frase))}' +
              f' ( {variavel} -> {informacoes[variavel][numeroGerado]} ) ')

        cadeia = simulacao

        sleep(0.1)

        # ! Contagem para verificar se ainda existe algum não terminal na cadeia.
        contadorSucesso: int = 0
        contadorTotal: int = 0
        for variavelTeste in listaVariaveis:
            if variavelTeste not in cadeia:
                contadorSucesso += 1
            contadorTotal += 1

        if contadorSucesso == contadorTotal:
            break

        menorPos: int = -2
        contador: int = 0

        # ! A substituição deve sempre ocorrer no não terminal mais à esquerda da cadeia.
        # ! Então, é preciso identificar qual é ele.
        for variavel2 in listaVariaveis:
            if contador == 0:

                if cadeia.find(variavel2) != -1:
                    menorPos = cadeia.find(variavel2)

            else:
                if cadeia.find(variavel2) != -1:

                    if menorPos == -2:
                        menorPos = cadeia.find(variavel2)

                    elif cadeia.find(variavel2) < menorPos:
                        menorPos = cadeia.find(variavel2)

            contador += 1

        variavel = cadeia[menorPos]

    print(f"{valor + 1 : 3} : " + cadeia)

    tracoLinha(1)

    return cadeia

# * Função para gerar a cadeia utilizando o "Modo Detalhado".
# ! Como funciona?
# O programa irá ler as produções e criar um dicionário com elas.
# Após isso, vai aparecer para o usuário escolher a produção, baseada no não terminal
# mais à esquerda.
def gerarCadeiaDetalhado(enderecoArquivo: str):

    limparTerminal()
    tracoLinha(0)
    print(corVermelha + "Importante: ao responder, coloque apenas números!" + corBranca)
    print(corVermelha + "Sempre pelo não terminal mais à esquerda. " + corBranca)

    # * Abrindo o arquivo com as informações
    meuArquivo = open(enderecoArquivo, "r")

    listaProducoesFim = []
    listaVariaveis = []
    informacoes = {}
    
    listaVariaveis, inicial, listaProducoesFim, informacoes = informacoesArquivos(meuArquivo, listaVariaveis, listaProducoesFim, informacoes)
    
    # * Fechando o arquivo
    meuArquivo.close()
    
    cadeia = inicial
    variavel: str = inicial

    while True:

        tracoLinha(1)

        print("Cadeia : " + corVerde + f"{cadeia}" + corBranca)

        # ! Apenas para organizar o terminal.
        if len(informacoes[variavel]) == 1:
            print(f"\nSubstituição disponível para " +
                  corCiano + f"{variavel}" + corBranca + ": \n")
        else:
            print(f"\nSubstituições disponíveis para " +
                  corCiano + f"{variavel}" + corBranca + ": \n")

        # ! Mostrando o que cada não terminal pode produzir.
        contador: int = 1
        for elemento in informacoes[variavel]:
            print(f" {contador} : " + corAmarela + f"{elemento}" + corBranca)
            contador += 1

        resposta = int(input("\n >> Opção: "))
        resposta = verificadorNumero(1, len(informacoes[variavel]), resposta)

        cadeia = cadeia.replace(
            variavel, informacoes[variavel][resposta - 1], 1)

        if "epsilon" in cadeia:
            cadeia = cadeia.replace("epsilon", "", 1)

        # ! Contagem para verificar se ainda existe algum não terminal na cadeia.
        contadorSucesso: int = 0
        contadorTotal: int = 0
        for variavelTeste in listaVariaveis:
            if variavelTeste not in cadeia:
                contadorSucesso += 1
            contadorTotal += 1

        if contadorSucesso == contadorTotal:
            break

        menorPos: int = -2
        contadorPos: int = 0

        # ! A substituição deve sempre ocorrer no não terminal mais à esquerda da cadeia.
        # ! Então, é preciso identificar qual é ele.
        for variavel2 in listaVariaveis:
            if contadorPos == 0:

                if cadeia.find(variavel2) != -1:
                    menorPos = cadeia.find(variavel2)

            else:
                if cadeia.find(variavel2) != -1:

                    if menorPos == -2:
                        menorPos = cadeia.find(variavel2)

                    elif cadeia.find(variavel2) < menorPos:
                        menorPos = cadeia.find(variavel2)

            contadorPos += 1

        variavel = cadeia[menorPos]

    tracoLinha(1)

    return cadeia

# * Função que contém as instruções para criar o arquivo da gramática.
def instrucoesGramatica():
    print(corVerde + "Instruções para criar o arquivo da gramática \n" + corBranca)
    print(corBranca + f"Nome do Arquivo : " +
          corVerde + "informacoes.txt \n" + corVerde)
    print(corVerde + f"1" + corBranca + f" : 1° linha: \n"
          + corVerde + f"\t1.1" + corBranca + f" : Coloque " + corVerde +
          "terminais=" + corBranca + " no início da linha. \n"
          + corVerde + f"\t1.2" + corBranca + f" : Após o " + corVerde + "=" +
          corBranca + ", coloque todos os terminais, separados por vírgulas. \n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Apenas 1 terminal entre vírgulas.\n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não coloque espaços.\n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não é necessário colocar o epsilon.\n"
          + corVerde + f"\tExemplo" + corBranca + f" : terminais=0,1 \n")
    print(corVerde + f"2" + corBranca + f" : 2° linha: \n"
          + corVerde + f"\t2.1" + corBranca + f" : Coloque " + corVerde +
          "variaveis=" + corBranca + " no início da linha. \n"
          + corVerde + f"\t2.2" + corBranca + f" : Após o " + corVerde + "=" +
          corBranca + ", coloque todas as variáveis, separados por vírgulas. \n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Apenas 1 variável entre vírgulas.\n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não coloque espaços.\n"
          + corVerde + f"\tExemplo" + corBranca + f" : variaveis=S,A \n")
    print(corVerde + f"3" + corBranca + f" : 3° linha: \n"
          + corVerde + f"\t3.1" + corBranca + f" : Coloque " + corVerde +
          "terminais=" + corBranca + " no início da linha. \n"
          + corVerde + f"\t3.2" + corBranca + f" : Após o " + corVerde + "=" +
          corBranca + ", coloque a variável inicial que começará as derivações. \n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Geralmente, adotado o S como inicial.\n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não coloque espaços.\n"
          + corVerde + f"\tExemplo" + corBranca + f" : inicial=S \n")
    print(corVerde + f"4" + corBranca + f" : 4° linha: \n"
          + corVerde + f"\t1.1" + corBranca + f" : Coloque apenas " + corVerde +
          "producoes" + corBranca + " na linha. \n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não coloque espaços.\n"
          + corVerde + f"\tExemplo" + corBranca + f" : producoes \n")
    print(corVerde + f"5" + corBranca + f" : Restante das linhas: \n"
          + corVerde + f"\t5.1" + corBranca + f" : Coloque uma das " + corVerde +
          "variáveis" + corBranca + " no início da linha. \n"
          + corVerde + f"\t5.2" + corBranca +
          f" : Coloque em seguida " + corVerde + "-> \n" + corBranca
          + corVerde + f"\t5.3" + corBranca + f" : Após a setinha, coloque a concatenação das " + corVerde +
          "variáveis" + corBranca + " e dos " + corVerde + "terminais. \n"
          + corVerde + f"\t\t Importante" + corBranca +
          f" : Não coloque espaços.\n"
          + corAmarela + f"\t\t Importante" + corBranca +
          f" : O uso de epsilon em, pelo menos, uma das produções é recomendado.\n"
          "\t\t\t      Pois o programa pode entrar em um loop, sem encontrar um caminho para finalizar.\n"
          + corVerde + f"\tExemplo" + corBranca + f" : S->01S \n")
    print(corVermelha + f"IMPORTANTE" + corBranca +
          "  : após todas as produções, adicione uma linha vazia. \n")
    print(corVerde + " -> Exemplo de uma Gramática: \n" + corBranca +
          "\n\t terminais=0,1"
          "\n\t variaveis=S,A"
          "\n\t inicial=S"
          "\n\t producoes"
          "\n\t S->0S"
          "\n\t S->1S"
          "\n\t S->1A"
          "\n\t S->SS"
          "\n\t S->epsilon"
          "\n")
