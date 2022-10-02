print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' MAIOR E MENOS VALORES '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mFaça um programa que leia três 
números qual é o maior e qual é o menor.\033[m''')

n1 = float(input('\nDigite o primeiro número: '))
n2 = float(input('Digite o segundo número: '))
n3 = float(input('Digite o terceiro número: '))

menor = n1

if n2 < n1 and n2 < n3:
    menor = n2
if n3 < n1 and n3 < n2:
    menor = n3

maior = n1

if n1 < n2 and n3 < n2:
    maior = n2
if n2 < n1 and n2 < n3:
    maior = n3

print(f'O MAIOR valor é {maior}.')
print(f'O MENOR valor é {menor}.')