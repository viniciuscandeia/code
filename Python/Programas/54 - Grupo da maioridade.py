from datetime import date

print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' 54 - GRUPO DA MAIORIDADE '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mCrie um programa que leia o ano de nascimento 
de sete pessoas. No final, mostre quantas 
pessoas ainda não atingiram a maioridade 
e quantas já são maiores.\033[m""")

print('\n')
s = 0
n = 0
for c in range(0, 6):
    ano = int(input('Digite sua idade: '))
    idade = date.today().year - ano
    if idade >= 21:
        s += 1
    else:
        n += 1

if s == 0:
    print('Não tem ninguém acima da maioridade.')
    print('Todos os 7 são têm menos de 21 anos.')
elif s == 1:
    print('Tem apenas 1 com mais de 21 anos.')
    print('Os outros 6 têm menos de 21 anos.')
elif 1 < s < 6:
    print(f'{s} pessoas tem mais de 21 anos.')
    print(f'{n} pessoas tem menos de 21 anos.')
elif s == 6:
    print(f'Tem 6 pessoas com mais de 21 anos.')
    print(f'Tem apenas 1 com menos de 21 anos.')
elif s == 7:
    print(f'Todos os 7 são acima de 21 anos.')
    print('Não tem ninguém abaixo de 21 anos.')
