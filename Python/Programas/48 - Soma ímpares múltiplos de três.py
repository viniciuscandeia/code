print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' SOMA ÍMPARES MÚLTIPLOS DE TRÊS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mFaça um programa que calcule a soma 
entre todos os números que são múltiplos de 
três e que se encontram no intervalo de 
1 até 500.
\033[m""")

s = 0
n = 0
for c in range(1, 501, 2):
    if c % 3 == 0:
        s += c
        n += 1
print(s, n)
