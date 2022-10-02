import datetime

print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' ALISTAMENTO MILITAR '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mFaça um programa que leia o ano de nascimento 
de um jovem e informe, de acordo com a 
sua idade, se ele ainda vai se alistar ao 
serviço militar, se é a hora exata de se 
alistar ou se já passou do tempo do 
alistamento. Seu programa também deverá 
mostrar o tempo que falta ou que passou 
do prazo. \033[m""")

ano_n = int(input('\nQual o ANO que você nasceu? '))
print('=' * 40)

ano_a = datetime.date.today().year
dif_a = ano_a - ano_n

if dif_a < 18:
    print('Você ainda não precisa de alistar.')
    tempo1 = 18 - dif_a
    if tempo1 == 1:
        print('Falta \033[33m1 ano\033[m para você se alistar.')
    else:
        print(f'Faltam \033[33m{tempo1} anos\033[m para você se alistar.')
elif dif_a == 18:
    print('Você precisa se alistar.')
else:
    tempo2 = dif_a - 18
    if tempo2 == 1:
        print('Já tem \033[33m1 ano\033[m que passou do período de alistamento.')
    else:
        print(f'Já tem \033[33m{tempo2} anos\033[m que passou do período de alistamento.')
