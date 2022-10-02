print('\033[35m{:=^50}\033[m'.format('='))
print('\033[35m{:^50}\033[m'.format(' MÉDIA ARITMÉTICA '))
print('''\033[33mDesenvolva um programa que leia as duas notas de
um aluno, calcule e mostre a sua média.\033[m''')
print('\033[35m{:=^50}\033[m'.format('='))

n1 = float(input('\nDigite a primeira nota: '))
n2 = float(input('Digite a segunda nota: '))
print(f'A média com notas {n1} e {n2} foi \033[33m{(n1 + n2) / 2 :.1f}\033[m.')