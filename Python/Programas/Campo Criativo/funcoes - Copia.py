import os
from random import randint
from time import sleep

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

    # * Abrindo o arquivo com as informações
    meuArquivo = open(enderecoArquivo, "r")

    numeroLinhas: int = 0
    for linha in meuArquivo:

        # Teste 1 : Há, pelo menos, 1 espaço no arquivo.
        cadeia: str = linha[:linha.find("\n")]
        if cadeia.find(" ") != -1:
            print(corVermelha + f"ERRO : 1" + corBranca)
            print(f" >> Há, pelo menos, 1 espaço no arquivo. \n")

            # * Fechando o arquivo
            meuArquivo.close()

            return 0

        numeroLinhas += 1

    # * Fechando o arquivo
    meuArquivo.close()
    
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
    listaTemporaria: list = []
    listaCaminhoEpsilon: list = []
    listaAuxiliar: list = []
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
            if linha[0:10] != "terminais=":
                print(corVermelha + f"ERRO : 2" + corBranca)
                print(f" >> \"terminais=\" não ocupar a posição [0:10]")
                print(f"Atual: {linha[0:10]} \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 3 : Não ter nenhum terminal (= )
            if tamanhoLinha == 0:
                print(corVermelha + f"ERRO : 3" + corBranca)
                print(f" >> Não ter nenhum terminal (= ) \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 4 : Sem nenhum terminal após uma vírgula (=1,)
            if linha[linha.find("\n") - 1] == ",":
                print(corVermelha + f"ERRO : 4" + corBranca)
                print(f" >> Sem nenhum terminal após uma vírgula (=1,) \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 5 : Mais vírgulas do que terminais (=1,,)
            if numeroTerminais < numeroVirgula:
                print(corVermelha + f"ERRO : 5" + corBranca)
                print(" >> Mais vírgulas do que terminais (=1,,)")
                print(f"Número de terminais: {numeroTerminais}")
                print(f"Número de vírgulas: {numeroVirgula} \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 6 : O cenário: =,0
            if linha[10] == ",":
                print(corVermelha + f"ERRO : 6" + corBranca)
                print(" >> O cenário: =,0 \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 7 : Ter mais de 1 terminal entre vírgulas (,01,)
            # Teste 8 : Ter mais de 1 terminal igual (1,1)
            for elemento in listaTerminais:
                if len(elemento) > 1:
                    print(corVermelha + f"ERRO : 7" + corBranca)
                    print(" >> Ter mais de 1 terminal entre vírgulas (,01,) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0

                if listaTerminais.count(elemento) > 1:
                    print(corVermelha + f"ERRO : 8" + corBranca)
                    print(" >> Ter mais de 1 terminal igual (1,1) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0

            # Teste 9 : Ter 2 vírgulas seguidas (,,)
            for contador in range(10, len(linha[: linha.find("\n")])):
                if linha[contador] == "," and linha[contador + 1] == ",":
                    print(corVermelha + f"ERRO : 9" + corBranca)
                    print(" >> Ter 2 vírgulas seguidas (,,) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

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

            # Teste 10 : "variaveis=" não ocupar a posição [0:10]
            if linha[0:10] != "variaveis=":
                print(corVermelha + f"ERRO : 10" + corBranca)
                print(f" >> \"variaveis=\" não ocupar a posição [0:10]")
                print(f"Atual: {linha[0:10]} \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 11 : Não ter nenhuma variável (= )
            if tamanhoLinha == 0:
                print(corVermelha + f"ERRO : 11" + corBranca)
                print(f" >> Não ter nenhuma variável (= ) \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 12 : Sem nenhuma variável após uma vírgula (=1,)
            if linha[linha.find("\n") - 1] == ",":
                print(corVermelha + f"ERRO : 12" + corBranca)
                print(f" >> Sem nenhuma variável após uma vírgula (=1,) \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 13 : Mais vírgulas do que variáveis (=1,,)
            if numeroVariaveis < numeroVirgula:
                print(corVermelha + f"ERRO : 13" + corBranca)
                print(" >> Mais vírgulas do que variáveis (=1,,)")
                print(f"Número de variáveis: {numeroVariaveis}")
                print(f"Número de vírgulas: {numeroVirgula} \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 14 : O cenário: =,0
            if linha[10] == ",":
                print(corVermelha + f"ERRO : 14" + corBranca)
                print(" >> O cenário: =,0 \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 15 : Ter mais de 1 variável entre vírgulas (,01,)
            # Teste 16 : Ter mais de 1 variável igual (1,1)
            for elemento in listaVariaveis:
                if len(elemento) > 1:
                    print(corVermelha + f"ERRO : 15" + corBranca)
                    print(" >> Ter mais de 1 variável entre vírgulas (,01,) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0
                if listaVariaveis.count(elemento) > 1:
                    print(corVermelha + f"ERRO : 16" + corBranca)
                    print(" >> Ter mais de 1 variável igual (1,1) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0

            # Teste 17 : Ter 2 vírgulas seguidas (,,)
            for contador in range(10, len(linha[: linha.find("\n")])):
                if linha[contador] == "," and linha[contador + 1] == ",":
                    print(corVermelha + f"ERRO : 17" + corBranca)
                    print(" >> Ter 2 vírgulas seguidas (,,) \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0

        elif contadorLinha == 2:

            inicial = linha[8: linha.find("\n")]

            # Teste 18 : "inicial=" não ocupar a posição [0:8]
            if linha[0:8] != "inicial=":
                print(corVermelha + f"ERRO : 18" + corBranca)
                print(f" >> \"inicial=\" não ocupar a posição [0:8] \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 19 : Ter mais de uma variável
            if len(inicial) > 1:
                print(corVermelha + f"ERRO : 19" + corBranca)
                print(f" >> Ter mais de uma variável \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 20 : Não ter nada além do "="
            if len(inicial) == 0:
                print(corVermelha + f"ERRO : 20" + corBranca)
                print(f" >> Não ter nada além do \"=\" \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 21 : O inicial não está na lista de variáveis
            if inicial not in listaVariaveis:
                print(corVermelha + f"ERRO : 21" + corBranca)
                print(f" >> O inicial não está na lista de variáveis \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

        elif contadorLinha == 3:

            # Teste 22 : "producoes" não ocupar a posição [0:9]
            if linha[0:9] != "producoes":
                print(corVermelha + f"ERRO : 22" + corBranca)
                print(f" >> \"producoes\" não ocupar a posição [0:9] \n")
                print(f"Atual: {linha[0:9]} \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 23 : Não ter apenas "producoes"
            if len(linha[: linha.find("\n")]) > len("producoes"):
                print(corVermelha + f"ERRO : 23" + corBranca)
                print(f" >> Não ter apenas \"producoes\" \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

        else:

            # Teste 24 : Ter uma variável que não está na lista de variáveis
            if linha[0] not in listaVariaveis:
                print(corVermelha + f"ERRO : 24" + corBranca)
                print(f" >> Ter uma variável que não está na lista de variáveis \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 25 : "->" não ocupar a posição [1:3]
            if linha[1:3] != "->":
                print(corVermelha + f"ERRO : 25" + corBranca)
                print(f" >> \"->\" não ocupar a posição [1:3] \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 26 : Nada após "->"
            if len(linha[: linha.find("\n")]) == 3:
                print(corVermelha + f"ERRO : 26" + corBranca)
                print(f" >> Nada após \"->\" \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

            # Teste 27 : A nova parte não está presente na lista de terminais, nem na de variáveis.
            parteFinal: str = linha[3: linha.find("\n")]
            if "epsilon" not in parteFinal:
                for letra in parteFinal:
                    if letra not in listaTerminais and letra not in listaVariaveis:
                        print(corVermelha + f"ERRO : 27" + corBranca)
                        print(
                            f" >> A nova parte não está presente na lista de terminais, nem na de variáveis\n")

                        # * Fechando o arquivo
                        meuArquivo.close()

                        return 0

            # Teste 28 : Produção repetida
            if linha[0] in dicionarioProducoes:
                if parteFinal in dicionarioProducoes[linha[0]]:
                    print(corVermelha + f"ERRO : 28" + corBranca)
                    print(f" >> Produção repetida \n")

                    # * Fechando o arquivo
                    meuArquivo.close()

                    return 0
                else:
                    listaTemporaria = dicionarioProducoes.get(linha[0])
                    listaTemporaria.append(parteFinal)
                    dicionarioProducoes[linha[0]] = listaTemporaria.copy()
                    listaTemporaria.clear()
            else:
                dicionarioProducoes[linha[0]] = [parteFinal]

            if contadorLinha == numeroLinhas - 1:
                for variavel in listaVariaveis:

                    if variavel in dicionarioProducoes:
                        if "epsilon" in dicionarioProducoes[variavel]:
                            presencaEpsilon = True
                            listaEpsilon.append(variavel)

                    # Teste 29 : Variável não usada
                    if variavel not in dicionarioProducoes:
                        print(corVermelha + f"ERRO : 29" + corBranca)
                        print(f" >> Variável não usada \n")

                        # * Fechando o arquivo
                        meuArquivo.close()

                        return 0

        contadorLinha += 1

    # Teste 30 : Não tem "epsilon"
    if presencaEpsilon == False:
        print(corAmarela + f"ALERTA : 1" + corBranca)
        print(f" >> Não tem \"epsilon\" \n")
        print("O uso de epsilon em, pelo menos, uma das produções é recomendado.")
        print("Pois o programa pode entrar em um loop, sem encontrar um caminho para finalizar.\n")

    if presencaEpsilon == True:

        if contadorLinha == numeroLinhas:

            # ! Criando 2 listas cópias
            listaAuxiliar = listaEpsilon.copy()
            listaCaminhoEpsilon = listaEpsilon.copy()

            while True:

                # * Pegando o 1° elemento da lista
                elemento: str = listaAuxiliar[0]

                # ! Pegando cada variável da lista de Variáveis
                for variavel in listaVariaveis:

                    if variavel not in listaAuxiliar and variavel not in listaCaminhoEpsilon:

                        # * Verificando se dentro de cada produção há o elemento
                        for letra in dicionarioProducoes[variavel]:
                            if elemento in letra:

                                # ? Adicionando a variável nas listas
                                listaAuxiliar.append(variavel)
                                listaCaminhoEpsilon.append(variavel)

                # * Removendo o 1° elemento da lista
                listaAuxiliar.pop(0)

               # * Se o tamanho da lista for igual a 0
                if len(listaAuxiliar) == 0:
                    break

            # Teste 31 : Tem que ter um caminho que chegue no "epsilon"
            if inicial not in listaCaminhoEpsilon:
                print(corVermelha + f"ERRO : 31" + corBranca)
                print(f" >> Tem que ter um caminho que chegue no \"epsilon\" \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0

    # * Fechando o arquivo
    meuArquivo.close()

    return 1

# * Função para gerar a cadeia utilizando o "Modo Rápido"
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
    listaTemporaria = []
    listaVariaveis = []

    informacoes = {}

    # * Lendo cada linha do arquivo
    for linha in meuArquivo:

        # ! Adicionando cada variável passada em uma lista.
        if "variaveis" in linha:
            variaveis = str(linha[10:len(linha) - 1])
            listaVariaveis = variaveis.split(",")

        # ! Pegando qual é o não terminal inicial.
        elif "inicial" in linha:
            inicial = str(linha[8:len(linha) - 1])

        # ! Manipulação das produções.
        else:
            if "producoes" not in linha:

                # & Uma lista contendo todas as produções.
                listaProducoesFim.append(str(linha[:len(linha) - 1]))

    # * Criando um dicionário, separando o que cada não terminal produz.
    for variavel in listaVariaveis:
        for producao in listaProducoesFim:
            if producao[0] == variavel:
                listaTemporaria.append(producao[3:])
        informacoes[variavel] = listaTemporaria.copy()
        listaTemporaria.clear()

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

    # * Fechando o arquivo
    meuArquivo.close()

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
    listaTemporaria = []
    listaVariaveis = []

    informacoes = {}

    # * Lendo cada linha do arquivo
    for linha in meuArquivo:

        # ! Adicionando cada variável passada em uma lista.
        if "variaveis" in linha:
            variaveis = str(linha[10:len(linha) - 1])
            listaVariaveis = variaveis.split(",")

        # ! Pegando qual é o não terminal inicial.
        elif "inicial" in linha:
            inicial = str(linha[8:len(linha) - 1])

        # ! Manipulação das produções.
        else:
            if "producoes" not in linha:

                # & Uma lista contendo todas as produções.
                listaProducoesFim.append(str(linha[:len(linha) - 1]))

    # * Criando um dicionário, separando o que cada não terminal produz.
    for variavel in listaVariaveis:
        for producao in listaProducoesFim:
            if producao[0] == variavel:
                listaTemporaria.append(producao[3:])
        informacoes[variavel] = listaTemporaria.copy()
        listaTemporaria.clear()

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
