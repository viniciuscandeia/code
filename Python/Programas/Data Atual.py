print('\033[33m{:=^45}\033[m'.format(' ANIVERSÁRIO? '))

from datetime import date
from time import sleep

year_a = date.today().year
month_a = date.today().month
day_a = date.today().day

day_b = int(input('\nQual o \033[4:36mDIA\033[m que você nasceu? '))
month_b = int(input('Qual o \033[4:36mMÊS\033[m que você nasceu? '))
year_b = int(input('Qual o \033[4:36mANO\033[m que você nasceu? '))
print('\nCalma aí corno, pensando aqui...')
sleep(3)

if month_a == month_b and day_a == day_b:
    idade = year_a - year_b
    print('\n\033[34mPARABÉNS! Feliz Aniversário.\033[m')
    print(f'\033[34mVocê está fazendo {idade} anos.\033[m')
else:
    print('\n\033[31mQue dia de bosta!\033[m')
