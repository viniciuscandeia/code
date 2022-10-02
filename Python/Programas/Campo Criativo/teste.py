import imp
from funcoesSecundarias import *

meuArquivo = open("informacoes.txt", "r")

for linha in meuArquivo:
      if "producoes" in linha:
            fecharArquivo(meuArquivo)
      print(linha)