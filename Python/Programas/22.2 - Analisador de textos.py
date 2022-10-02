print('\033[35m{:=^40}\033[m'.format("="))
print('\033[35m{:^40}\033[m'.format(' ANALISADOR DE TEXTOS '))
print("""\033[33mCrie um programa que leia o nome completo de uma pessoa e mostre: 
- O nome com todas as letras maiúsculas.
- O nome com todas as letras minúsculas.
- Quantas letras ao todo (sem considerar espaços).
- Quantas letras tem o primeiro nome.\033[m""")
print('\033[35m{:=^40}\033[m'.format('='))

nome = str(input('Qual o seu nome completo? \n')).strip()
nome_div = nome.split()
print(f'\nO seu nome em maiúsculas é \033[31m{nome.upper()}\033[m.')
print(f'O seu nome em minúsculas é \033[34m{nome.lower()}\033[m.')
print(f'O seu nome tem \033[32m{len(nome) - len(nome_div) + 1} letras\033[m.')
print(f'O seu primeiro nome tem \033[33m{len(nome_div[0])} letras\033[m.')
