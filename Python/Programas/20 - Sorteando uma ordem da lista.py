from random import shuffle

print('\033[35m{:=^40}\033[m'.format(' SORTEANDO UMA ORDEM DA LISTA '))

a = input('Primeiro aluno: ')
b = input('Segundo aluno: ')
c = input('Terceiro aluno: ')
d = input('Quarto aluno: ')

alunos = [a, b, c, d]
shuffle(alunos)
print(f'{alunos}')
