print('\033[35m{:=^45}\033[m'.format('='))
print('\033[35m{:=^45}\033[m'.format(' VERIFICANDO AS PRIMEIRAS LETRAS DE UM TEXTO '))
print("""\033[33mCrie um programa que leia o nome de uma 
cidade e diga se ela começa ou não com o 
nome "Santo".\033[m""")
print('\033[35m{:=^45}\033[m'.format('='))

cidade = str(input('Em qual cidade você nasceu? ')).strip()
cidade_U = cidade.upper()
print(f'A cidade tem o nome "Santo"? \033[31m{"SANTO" in cidade_U}\033[m')