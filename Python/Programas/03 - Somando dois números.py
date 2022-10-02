print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' SOMANDO DOIS NÚMEROS '))
print("""\033[33mCrie um programa que leia dois números e mostre 
a soma entre eles.""")
print('\033[35m{:=^40}\033[m'.format('='))

n1 = int(input('\n\033[35mDigite o primeiro número: '))
n2 = int(input('Digite o segundo número: \033[m'))
print(f'A soma entre \033[32m{n1}\033[m e \033[32m{n2}\033[m é \033[4;34m{n1 + n2}\033[m.')

print('\033[31m-\033[m' * 30)
print('\033[30m{:>12}'.format(n1))
print('+', '{:>10}'.format(n2))
print('-' * 12)
print('{:>12}\033[m'.format(n1 + n2))
