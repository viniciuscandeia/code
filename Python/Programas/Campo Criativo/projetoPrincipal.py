# Tema 2 : Gerador de Cadeia Livre de Contexto
# Aluna : Caroliny Santos Arruda
# Aluno : Vinicius Candeia Pereira Vieira

from os import *
from funcoesPrincipais import *

listaArquivos = os.listdir(".")
for arquivo in listaArquivos:
    caminhoArquivo = os.path.abspath(arquivo)
    if "informacoes.txt" in caminhoArquivo:
        enderecoArquivo: str = caminhoArquivo

while True:

    limparTerminal()
    tracoLinha(0)
    print(corVermelha + "Importante: ao responder, coloque apenas números!" + corBranca)
    tracoLinha(1)

    print(" 1 : " + corAmarela + "Modo Rápido" + corBranca)
    print(" 2 : " + corAmarela + "Modo Detalhado" + corBranca)
    print(" 3 : " + corAmarela + "Instruções para o arquivo" + corBranca)
    print(" 0 : " + corAmarela + "Sair" + corBranca)

    numero = str(input("\n >> Opção: "))
    numero = verificadorResposta(numero, 0)

    if numero == "1":

        cadeia = gerarCadeiaRapido(enderecoArquivo)

        if cadeia == -1:
            print(corVermelha + f"O arquivo não está pronto!" + corBranca)
            break
        else:
            print(f"Cadeia : " + corVerde + f"{cadeia}" + corBranca)

        tracoLinha(1)

    elif numero == "2":

        cadeia = gerarCadeiaDetalhado(enderecoArquivo)

        if cadeia == -1:
            print(corVermelha + f"O arquivo não está pronto!" + corBranca)
            break
        else:
            print(f"Cadeia : " + corVerde + f"{cadeia}" + corBranca)

        tracoLinha(1)

    elif numero == "3":
        
        tracoLinha(1)
        instrucoesGramatica()
        tracoLinha(1)

    elif numero == "0":
        break

    else:
        tracoLinha(1)
        print(corVermelha + "Número inválido!" + corBranca)
        tracoLinha(1)

    print(corVermelha + "Importante: ao responder, coloque apenas uma letra!" + corBranca)
    tracoLinha(1)

    print("Voltar ao menu? \n")
    print(" N : " + corAmarela + "Não" + corBranca)
    print(" S : " + corAmarela + "Sim" + corBranca)

    resposta = str(input(f"\n >> Opção: ")).upper()
    resposta = verificadorResposta(resposta, 1)

    if resposta == "N":
        break

tracoLinha(1)
print(corVerde + "Fim da execução" + corBranca)
tracoLinha(1)
