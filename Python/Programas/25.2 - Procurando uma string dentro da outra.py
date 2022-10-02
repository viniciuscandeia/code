print('\033[35m{:=^41}\033[m'.format('='))
print('\033[35m{:^41}\033[m'.format(' PROCURANDO UMA STRING DENTRA DA OUTRA'))
print("""\033[33mCrie um programa que leia o nome
de uma pessoa e diga se ela tem "Silva" no 
nome.\033[m""")
print("\033[35m{:=^41}\033[m".format('='))

nome = str(input('Qual o seu nome completo? ')).strip()
nome_U = nome.upper()
print(f'O seu nome tem "Silva"? \033[34m{"SILVA" in nome_U}\033[m.')
