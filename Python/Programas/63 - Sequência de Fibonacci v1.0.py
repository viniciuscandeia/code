print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"63 - SEQUÊNCIA DE FIBONACCI V1.0":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mEscreva um programa que leia um número N 
inteiro qualquer e mostre na tela os N 
primeiros elementos de uma Sequência de 
Fibonacci. 
Ex: 0 - 1 - 1 - 2 - 3 - 5 - 8\033[m\n""")

n = int(input('Quantos termos da Sequência de Fibonacci \ndesejar ver? '))

a1 = 0
a2 = 1
print(f'\033[34m{"~" * 45}\033[m')
print(f'\033[32m{a1} -> {a2}', end='')
cont = 3

while cont <= n:
    a3 = a1 + a2
    print(f' -> {a3}', end='')
    cont += 1
    a1 = a2
    a2 = a3
print(' -> FIM\033[m')
print(f'\033[34m{"~" * 45}\033[m')
