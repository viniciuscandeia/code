print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' SEPARANDO DÍGITOS DE UM NÚMERO '))
print("""\033[33mFaça um programa que leia um número 
de 0 a 9999 e mostre na tela cada um dos 
dígitos separados.

Ex:
Digite um número: 1834
Unidade: 4
Dezena: 3
Centena: 8
Milhar: 1\033[m""")
print('\033[35m{:=^40}\033[m'.format('='))

n = int(input('Digite um número de 1000 a 9999: '))
num = str(n)
print(f'Unidade: {num[len(num) - 1]}')
print(f'Dezena: {num[len(num) - 2]}')
print(f'Centena: {num[len(num) - 3]}')
print(f'Milhar: {num[len(num) - 4]}')
