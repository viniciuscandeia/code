print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' CONVERSOR DE BASES NUMÉRICAS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mEscreva um programa em Python que leia 
um número inteiro qualquer e peça para o 
usuário escolher qual será a base de 
conversão: 1 para binário, 2 para octal e 
3 para hexadecimal. \033[m""")

num = int(input('\nDigite um número inteiro: '))

print("""Escolha uma das opções para converter... 
\033[31m( 1 ) para BINÁRIO\033[m
\033[33m( 2 ) para OCTAL\033[m
\033[34m( 3 ) para HEXADECIMAL\033[m""")
opcao = int(input('Sua opção: '))

if opcao == 1:
    print(f'\033[32m{num}\033[m em BINÁRIO é \033[35m{bin(num)[2:]}\033[m')
elif opcao == 2:
    print(f'\033[32m{num}\033[m em OCTAL é \033[35m{oct(num)[2:]}\033[m')
elif opcao == 3:
    print(f'\033[32m{num}\033[m em HEXADECIMAL é \033[35m{hex(num)[2:]}\033[m')
else:
    print('OPÇÃO INVÁLIDA!')
