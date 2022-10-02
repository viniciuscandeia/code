print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' ANALISANDO TRIÂNGULO v1.0'))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mDesenvolva um programa que leia o 
comprimento de três retas e diga ao 
usuário se elas podem ou não formar um 
triângulo.\033[m''')

a = float(input('\nDigite o comprimento da primeira reta: '))
b = float(input('Digite o comprimento da segunda reta: '))
c = float(input('Digite o comprimento da terceira reta: '))

if a + b > c and a + c > b and b + c > a:
    print(f'É possível formar o triângulo!')
else:
    print(f'Não é possível formar o triângulo!')
