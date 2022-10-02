from io import TextIOWrapper

# * Definindo cores para usar no terminal.
corBranca = str("\033[0m")
corVermelha = str("\033[31m")
corVerde = str("\033[32m")
corAmarela = str("\033[33m")
corAzul = str("\033[34m")
corMagenta = str("\033[35m")
corCiano = str("\033[36m")

# Teste 1 : Há, pelo menos, 1 espaço no arquivo.
def testeEspacos(enderecoArquivo: str):
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

            return 0, 0

        numeroLinhas += 1

    # * Fechando o arquivo
    meuArquivo.close()

    return numeroLinhas, 1

# Teste 2 : "terminais=" não ocupar a posição [0:10]
# Teste 2 : "variaveis=" não ocupar a posição [0:10]
# Teste 2 : "inicial=" não ocupar a posição [0:8]
# Teste 2 : "producoes" não ocupar a posição [0:9]
def grupoTesteNomes(linha: str, comparar: str, meuArquivo: TextIOWrapper):
    if linha[0:10] != comparar:
        print(corVermelha + f"ERRO : 2" + corBranca)
        print(f" >> \"{comparar}\" não ocupar a posição")
        print(f"Atual: {linha} \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 3 : Não ter nenhum terminal (= )
# Teste 3 : Não ter nenhuma variável (= )
def grupoTesteDois(tamanhoLinha: int, meuArquivo: TextIOWrapper):
    if tamanhoLinha == 0:
        print(corVermelha + f"ERRO : 3" + corBranca)
        print(f" >> Não ter nenhum terminal (= ) \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 4 : Sem nenhum terminal após uma vírgula (=1,)
# Teste 4 : Sem nenhuma variável após uma vírgula (=1,)
def grupoTesteTres(linha: str, meuArquivo: TextIOWrapper):
    if linha[linha.find("\n") - 1] == ",":
        print(corVermelha + f"ERRO : 4" + corBranca)
        print(f" >> Sem nenhum terminal após uma vírgula (=1,) \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 5 : Mais vírgulas do que terminais (=1,,)
# Teste 5 : Mais vírgulas do que variáveis (=1,,)
def grupoTesteQuatro(numero: int, numeroVirgula: int, meuArquivo: TextIOWrapper):
    if numero < numeroVirgula:
        print(corVermelha + f"ERRO : 5" + corBranca)
        print(" >> Mais vírgulas do que terminais (=1,,)")
        print(f"Número de terminais: {numero}")
        print(f"Número de vírgulas: {numeroVirgula} \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 6 : O cenário: =,0
def grupoTesteCinco(linha: str, meuArquivo: TextIOWrapper):
    if linha[10] == ",":
        print(corVermelha + f"ERRO : 6" + corBranca)
        print(" >> O cenário: =,0 \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 9 : Ter 2 vírgulas seguidas (,,)
def grupoTesteSeis(linha: str, meuArquivo: TextIOWrapper):
    for contador in range(10, len(linha[: linha.find("\n")])):
        if linha[contador] == "," and linha[contador + 1] == ",":
            print(corVermelha + f"ERRO : 9" + corBranca)
            print(" >> Ter 2 vírgulas seguidas (,,) \n")

            # * Fechando o arquivo
            meuArquivo.close()

            return 0
    return 1

# Teste 7 : Ter mais de 1 terminal entre vírgulas (,01,)
# Teste 7 : Ter mais de 1 variável entre vírgulas (,01,)
# Teste 8 : Ter mais de 1 terminal igual (1,1)
# Teste 8 : Ter mais de 1 variável igual (1,1)
def grupoTesteSete(listaTerminais: list[str], tipo: str, meuArquivo: TextIOWrapper):
    for elemento in listaTerminais:
        if len(elemento) > 1:
            print(corVermelha + f"ERRO : 7" + corBranca)
            print(" >> Ter mais de 1 {tipo} entre vírgulas (,01,) \n")

            # * Fechando o arquivo
            meuArquivo.close()

            return 0

        if listaTerminais.count(elemento) > 1:
            print(corVermelha + f"ERRO : 8" + corBranca)
            print(" >> Ter mais de 1 {tipo} igual (1,1) \n")

            # * Fechando o arquivo
            meuArquivo.close()

            return 0
    return 1

# Teste 10 : Ter mais de uma variável
# Teste 11 : Não ter nada além do "="
# Teste 12 : O inicial não está na lista de variáveis
def testeInicial(inicial: str, listaVariaveis: list, meuArquivo: TextIOWrapper):
    if len(inicial) > 1:
        print(corVermelha + f"ERRO : 10" + corBranca)
        print(f" >> Ter mais de uma variável \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0

    if len(inicial) == 0:
        print(corVermelha + f"ERRO : 11" + corBranca)
        print(f" >> Não ter nada além do \"=\" \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0

    if inicial not in listaVariaveis:
        print(corVermelha + f"ERRO : 12" + corBranca)
        print(f" >> O inicial não está na lista de variáveis \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 13 : Não ter apenas "producoes"
def testeProducoes(linha: str, meuArquivo: TextIOWrapper):
    if len(linha[: linha.find("\n")]) > len("producoes"):
        print(corVermelha + f"ERRO : 13" + corBranca)
        print(f" >> Não ter apenas \"producoes\" \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 14 : Ter uma variável que não está na lista de variáveis
# Teste 15 : "->" não ocupar a posição [1:3]
# Teste 16 : Nada após "->"
def grupoTesteProducoes(linha: str, listaVariaveis: list, meuArquivo: TextIOWrapper):
    if linha[0] not in listaVariaveis:
        print(corVermelha + f"ERRO : 14" + corBranca)
        print(f" >> Ter uma variável que não está na lista de variáveis \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0

    if linha[1:3] != "->":
        print(corVermelha + f"ERRO : 15" + corBranca)
        print(f" >> \"->\" não ocupar a posição [1:3] \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0

    if len(linha[: linha.find("\n")]) == 3:
        print(corVermelha + f"ERRO : 16" + corBranca)
        print(f" >> Nada após \"->\" \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 17 : A nova parte não está presente na lista de terminais, nem na de variáveis.
def testeProducoes2(parteFinal: str, listaTerminais: list, listaVariaveis: list, meuArquivo: TextIOWrapper):
    if "epsilon" not in parteFinal:
        for letra in parteFinal:
            if letra not in listaTerminais and letra not in listaVariaveis:
                print(corVermelha + f"ERRO : 17" + corBranca)
                print(
                    f" >> A nova parte não está presente na lista de terminais, nem na de variáveis\n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0
    return 1

# Teste 18 : Produção repetida
def testeProducoes3(linha: str, parteFinal: str, dicionarioProducoes: dict, meuArquivo: TextIOWrapper):

    listaTemporaria: list = []

    if linha[0] in dicionarioProducoes:
        if parteFinal in dicionarioProducoes[linha[0]]:
            print(corVermelha + f"ERRO : 18" + corBranca)
            print(f" >> Produção repetida \n")

            # * Fechando o arquivo
            meuArquivo.close()

            return 0, dicionarioProducoes.clear()
        else:
            listaTemporaria = dicionarioProducoes.get(linha[0])
            listaTemporaria.append(parteFinal)
            dicionarioProducoes[linha[0]] = listaTemporaria.copy()
            listaTemporaria.clear()
    else:
        dicionarioProducoes[linha[0]] = [parteFinal]

    return 1, dicionarioProducoes.copy()

# Teste 19 : Variável não usada
def testeProducoes4(variavel: str, dicionarioProducoes: dict, meuArquivo: TextIOWrapper):
    
    if variavel not in dicionarioProducoes:
        print(corVermelha + f"ERRO : 19" + corBranca)
        print(f" >> Variável não usada \n")

        # * Fechando o arquivo
        meuArquivo.close()

        return 0
    return 1

# Teste 20 : Não tem "epsilon"
# Teste 21 : Tem que ter um caminho que chegue no "epsilon"
def testeProducoes5(presencaEpsilon: bool, contadorLinha: int, numeroLinhas: int, listaEpsilon: list, listaVariaveis: list, dicionarioProducoes: dict, inicial: str,meuArquivo: TextIOWrapper):

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

            if inicial not in listaCaminhoEpsilon:
                print(corVermelha + f"ERRO : 20" + corBranca)
                print(f" >> Tem que ter um caminho que chegue no \"epsilon\" \n")

                # * Fechando o arquivo
                meuArquivo.close()

                return 0
    return 1

# Função que retorna as informações contidas no arquivo
def informacoesArquivos(meuArquivo: TextIOWrapper, listaVariaveis: list, listaProducoesFim: list, informacoes: dict):

    listaTemporaria = []

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

    return listaVariaveis.copy(), inicial, listaProducoesFim.copy(), informacoes.copy()
