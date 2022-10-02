from random import randint
from time import sleep

print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"88 - PALPITES PARA A MEGA SENA":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que ajude um jogador da 
MEGA SENA a criar palpites. O programa vai 
perguntar quantos jogos serão gerados e vai 
sortear 6 números entre 1 e 60 para cada 
jogo, cadastrando tudo em uma lista 
composta.\033[m\n""")

jogo = []
main = []
print("-" * 45, f'\n{"JOGA NA MEGA SENA":^45}', f'\n{"-" * 45 }')
jogos = int(input('Digite o número de jogos: '))
print("-=" * 6, f'SORTEANDO {jogos} JOGOS', '-=' * 7)
cont = cont2 = 0
while cont < jogos:
    print(f'Jogo {cont + 1}: ', end='')
    cont2 = 0
    while True:
        n = randint(1, 60)
        if n not in jogo:
            jogo.append(n)
            cont2 += 1
        if cont2 == 6:
            break
    jogo.sort()
    main.append(jogo)
    print(main[cont])
    sleep(1)
    jogo.clear()
    cont += 1
print('-=' * 7, ' <BOA SORTE!> ', '=-' * 8)
