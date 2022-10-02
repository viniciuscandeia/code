print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' PRIMEIRO E ÚLTIMO NOME DE UMA PESSOA'))
print("""\033[33mFaça um programa que leia o nome completo
de uma pessoa, mostrando em seguida 
o primeiro e o último nome separadamente.\033[m

\033[33mEx: Ana Maria de Souza
Primeiro: Ana
Último: Souza\033[m""")
print('\033[35m{:=^40}\033[m'.format('='))

nome = str(input('Qual o seu nome completo? \n')).strip()
nome_div = nome.split()
print(f'O seu primeiro nome é \033[31m{nome_div[0]}\033[m.')
print(f'O seu último nome é \033[34m{nome_div[len(nome_div) - 1]}\033[m.')