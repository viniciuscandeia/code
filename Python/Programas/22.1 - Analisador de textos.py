print('\033[35m{:=^40}\033[m'.format("="))
print('\033[35m{:^40}\033[m'.format(' ANALISADOR DE TEXTOS '))
print("""\033[33mCrie um programa que leia o nome completo de uma pessoa e mostre: 
- O nome com todas as letras maiúsculas.
- O nome com todas as letras minúsculas.
- Quantas letras ao todo (sem considerar espaços).
- Quantas letras tem o primeiro nome.\033[m""")
print('\033[35m{:=^40}\033[m'.format('='))

nome_completo = str(input('Qual seu nome completo? \n')).strip()
nome_div = nome_completo.split()
n_letras_nomes = len(nome_completo) - nome_completo.count(' ')
print(f'\nO seu nome em letras maiúsculas é: \033[31m{nome_completo.upper()}\033[m.')
print(f'O seu nome em letras minúsculas é: \033[36m{nome_completo.lower()}\033[m.')
print(f'O seu nome completo tem \033[32m{n_letras_nomes} letras\033[m.')
print(f'O seu primeiro nome é \033[34m{nome_div[0]}\033[m e tem \033[34m{len(nome_div[0])}\033[m letras.')
