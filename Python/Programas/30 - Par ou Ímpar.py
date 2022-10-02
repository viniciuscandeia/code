print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' PAR OU ÍMPAR '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mCrie um programa que leia um número 
inteiro e mostre na tela se ele é par
ou ímpar.\033[m''')

n = int(input('Digite um número: '))
if n % 2 == 0:
    print(f'O número {n} é \033[31mPAR\033[m.')
else:
    print(f'O número {n} é \033[31mÍMPAR\033[m')
