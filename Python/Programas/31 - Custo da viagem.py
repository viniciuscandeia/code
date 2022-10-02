print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' CUSTO DA VIAGEM '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mDesenvolva um programa que pergunte a 
distância de uma viagem em km.
Calcule o preço da passagem cobrando 
R$0.50 por km para viagens de até 200km 
e R$0.45 para viagens mais longas.\033[m''')

d = int(input('\nQual a distância da viagem? '))
if d <= 200:
    v1 = d * 0.5
    print(f'O preço da viagem é \033[31m{v1 :.1f}\033[m.')
else:
    v2 = d * 0.45
    print(f'O preço da viagem é \033[31m{v2 :.1f}\033[m.')
