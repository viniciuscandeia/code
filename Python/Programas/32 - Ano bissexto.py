print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' ANO BISSEXTO '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mFaça um programa que leia um ano e 
mostre se ele é BISSEXTO.\033[m''')

ano = int(input('\nDigite um ano: '))
if ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0:
    print(f'O ano de {ano} é \033[31mBISSEXTO\033[m.')
else:
    print(f'O ano de {ano} não é \033[31mBISSEXTO\033[m.')
