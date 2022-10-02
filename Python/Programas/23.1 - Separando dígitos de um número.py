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

num = int(input('Digite um número de 0 a 9999: '))
u = num // 1 % 10
d = num // 10 % 10
c = num // 100 % 10
m = num // 1000 % 10
print(f'Unidade: {u}')
print(f'Dezena: {d}')
print(f'Centena: {c}')
print(f'Milhar: {m}')

