from random import choice

print('\033[35m{:=^40}\033[m'.format(' SORTEANDO UM ITEM DA LISTA '))

a = input('Primeiro aluno: ')
b = input('Segundo aluno: ')
c = input('Terceiro aluno: ')
d = input('Quarto aluno: ')

n = choice([a, b, c, d])
print(f'O sorteado foi \033[31m{n}\033[m.')
