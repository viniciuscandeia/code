print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' RESPONDENDO AO USUÁRIO '))
print("""\033[33mFaça um programa que leia o nome de uma pessoa 
e mostre uma mensagem de boas vindas.\033[m""")
print('\033[35m{:=^40}\033[m'.format('='))

nome = input('\n\033[34mDigite o seu nome: \033[m')
print(f'\033[33mMuito prazer em te conhecer,\033[m \033[31m{nome}\033[m\033[33m!\033[m')
