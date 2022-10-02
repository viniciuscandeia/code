print('\033[35m{:=^45}\033[m'.format('='))
print('\033[35m{:=^45}\033[m'.format(' VERIFICANDO AS PRIMEIRAS LETRAS DE UM TEXTO '))
print("""\033[33mCrie um programa que leia o nome de uma 
cidade e diga se ela começa ou não com o 
nome "Santo".\033[m""")
print('\033[35m{:=^45}\033[m'.format('='))

nome = str(input('Qual o nome da cidade? ')).strip()
nome_U = nome.upper()
print(f'O nome da cidade tem "Santo"? \033[34m{"SANTO" in nome_U}\033[m.')