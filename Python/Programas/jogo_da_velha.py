from colorama import Fore

cor_preta = Fore.BLACK
cor_vermelha = Fore.RED
cor_verde = Fore.GREEN
cor_amarela = Fore.YELLOW
cor_azul = Fore.BLUE
cor_magenta = Fore.MAGENTA
cor_ciano = Fore.LIGHTCYAN_EX
cor_branca = Fore.WHITE

linha = ("1", "2", "3", "4", "5", "6", "7", "8", "9")

i = 0
j = 0
cont = 0
rodadas = 0

while(True):

    rodadas += 1

    print(f'  {linha[0]} | {linha[1]} | {linha[2]} ')
    print(' ----------- ')
    print(f'  {linha[3]} | {linha[4]} | {linha[5]} ')
    print(' ----------- ')
    print(f'  {linha[6]} | {linha[7]} | {linha[8]} ')

    valor = int(input("\nVez do X: "))
    print(valor)

    posicao = valor - 1

    if (rodadas == 1):
        linha[1] = "X"

    if (rodadas != 1):
        if (linha[1] == "X" or linha[1] == "O"):
            print(cor_vermelha + 'OPCAO INVALIDA' + cor_branca)

    if (rodadas == 2):
        break