print('\033[35m{:=^50}\033[m'.format('='))
print('\033[35m{:^50}'.format(" ANTECESSOR E SUCESSOR \033[m"))
print('''\033[33mFaça um programa que leia um número inteiro
e mostre na tela o seu sucessor e seu antecessor.\033[m''')
print('\033[35m{:=^50}\033[m'.format('='))

n = int(input('\n\033[34mDigite um número: \033[m'))
print(f'O antecessor de \033[31m{n}\033[m é \033[31m{n - 1}\033[m e o sucessor é \033[31m{n + 1}\033[m.')
