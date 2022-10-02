print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"61 - PROGRESSÃO ARITMÉICA V2.0" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mRefaça o DESAFIO 051, lendo o primeiro 
termo e a razão de uma PA, mostrando os 
10 primeiros termos da progressão usando 
a estrutura while.\033[m""")

a1 = int(input('Primeiro termo: '))
r = int(input('Razão: '))
cont = 1
an = a1

while cont <= 10:
    print(f'{an}', end='')
    print(' > ' if cont < 10 else '', end='')
    an += r
    cont += 1
