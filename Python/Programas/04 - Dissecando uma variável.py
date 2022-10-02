print('\033[35m{:=^50}\033[m'.format('='))
print('\033[35m{:^50}\033[m'.format(' DISSECANDO UMA VARIÁVEL '))
print("""\033[33mFaça um programa que leia algo pelo teclado
e mostre na tela o seu tipo primitivo e todas as 
informações possíveis sobre ele.\033[m""")
print('\033[35m{:=^50}\033[m'.format('='))

n = input('\n\033[34mDigite algo: \033[m')
print('\033[31m O valor primitivo desse valor é:\033[m', type(n))
print('\033[31m Só tem espaços?\033[m', n.isspace())
print('\033[31m É um número?\033[m', n.isnumeric())
print('\033[31m É alfanumérico?\033[m', n.isalnum())
print('\033[31m Está em minúsculas?\033[m', n.islower())
print('\033[31m Está em maiúsculas?\033[m', n.isupper())
print('\033[31m É alfabético?\033[m', n.isalpha())
