from math import sqrt

print('\033[35m{:=^53}\033[m'.format('='))
print('\033[35m{:^53}\033[m'.format(' DOBRO, TRIPLO E RAIZ QUADRADA '))
print('''\033[33mCrie um algoritmo que leia um número e mostre o seu
dobro, triplo e raiz quadrada.\033[m''')
print('\033[35m{:=^53}\033[m'.format('='))

n = int(input('\n\033[34mDigite um número:\033[m '))
print(f'''O dobro de \033[32m{n}\033[m é \033[31m{n * 2}\033[m.
O triplo de \033[32m{n}\033[m é \033[33m{n * 3}\033[m.
A raiz quadrada de \033[32m{n}\033[m é \033[36m{sqrt(n) :.0f}\033[m.''')
