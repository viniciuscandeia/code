print("\033[35m{:=^40}\033[m".format('='))
print('\033[35m{:^40}\033[m'.format(' RADAR ELETRÔNICO '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mEscreva um programa que leia a velocidade 
de um carro.
Se ele ultrapassar 80km/h, mostre uma 
mensagem dizendo que ele foi multado.
A multa vai custar R$7.00 por cada km 
acima do limite.\033[m''')

v = float(input('Qual a velocidade que o motorista passou? '))
if v <= 80.0:
    print('Velocidade dentro do limite. Não há multa!')
else:
    multa = (v - 80) * 7
    print(f'Velocidade acima do limite. Multa de \033[31mR${multa :.1f}\033[m.')
