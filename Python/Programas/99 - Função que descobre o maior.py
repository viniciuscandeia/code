def maior(* num):
    lista = list()
    print('-=' * 20)
    print('Analisando os valores passados...')
    for c in range(0, len(num)):
        print(f'{num[c]} ', end='')
        lista.append(num[c])
    print(f'Foram informados {len(num)} ao todo.')
    maior_n = max(lista)
    print(f'O maior valor informado foi {maior_n}.')


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"99 - FUNÇÃO QUE DESCOBRE O MAIOR" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que tenha uma função chamada 
maior(), que receba vários parâmetros com 
valores inteiros. Seu programa tem que 
analisar todos os valores e dizer qual 
deles é o maior.\033[m\n""")

maior(2, 9, 4, 5, 7)
maior(4, 7, 0)
maior(1, 2)
maior(6)
maior(0)