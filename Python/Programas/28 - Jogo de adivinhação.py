from random import randint

print('\033[35m{:=^45}\033[m'.format('='))
print('\033[35m{:^45}\033[m'.format(' JOGO DE ADIVINHAÇÃO '))
print('''\n\033[33mEscreva um programa que faça o computador 
"pensar" em um número inteiro entre 0 e 5 e 
peça para o usuário tentar descobrir qual foi
o número escolhido pelo computador.
O programa deverá escrever na tela se o  
usuário venceu ou perdeu.\033[m''')
print('\033[35m{:=^45}\033[m'.format('='))

print('''\n"Eu (computador) vou escolher um número 
entre 0 e 5 e você (usuário) deverá 
descobrir qual foi número através de palpites." ''')

n = int(input('\n--> Qual número você acha que pensei? '))
lista = randint(0, 5)
if n == lista:
    print(f'Parabéns! Pensei mesmo no número \033[31m{n}\033[m.')
else:
    print(f'Lamento, mas você errou. Pensei no número \033[34m{lista}\033[m.')
