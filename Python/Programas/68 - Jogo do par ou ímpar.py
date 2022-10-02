from random import randint
from time import sleep

print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"68 - JOGO DO PAR OU ÍMPAR" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que jogue par ou ímpar 
com o computador. O jogo só será interrompido 
quando o jogador perder, mostrando o total 
de vitórias consecutivas que ele conquistou 
no final do jogo.  \033[m\n""")

cont = 0
num = 0
paridade = 0
while True:
    while paridade != "P" and paridade != "I":
        print('\033[33m[ P ]\033[m Par \n\033[33m[ I ]\033[m ímpar')
        paridade = str(input('Qual você quer ser? ')).upper().strip()
        if paridade == "P" or paridade == 'I':
            print(f'Você optou por ser \033[33m{paridade}\033[m.\n')
        else:
            print('\033[31mResposta inválida!Tente novamente.\033[m\n')

    num_pc = randint(1, 10)
    num = int(input('Digite um número [1 a 10]: '))
    print('Processando... ')
    sleep(1)
    resultado = num + num_pc
    resto_r = resultado % 2

    if paridade == "P":
        if resto_r == 0:
            print('\033[32mVocê ganhou!\033[m')
            cont += 1
        else:
            print('\033[31mVocê perdeu!\033[m')
            break
    if paridade == "I":
        if resto_r == 0:
            print('\033[31mVocê perdeu!\033[m')
            break
        else:
            print('\033[32mVocê ganhou!\033[m')
            cont += 1
    paridade = 0

if cont == 0:
    print('Você não ganhou nenhuma vez')
elif cont == 1:
    print('Você ganhpu 1 vez.')
elif cont > 1:
    print(f'Você ganhou {cont} vezes.')
