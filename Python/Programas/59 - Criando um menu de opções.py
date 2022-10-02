import time

print("\033[35m=\033[m" * 45)
print(f'\033[35m{"59 - CRIANDO UM MENU COM OPÇÕES" :^45}\033[m')
print('\033[35m=\033[m' * 45)
print("""\033[33mExercício Python 059: Crie um programa 
que leia dois valores e mostre um 
menu na tela:
[ 1 ] somar
[ 2 ] multiplicar
[ 3 ] maior
[ 4 ] novos números
[ 5 ] sair do programa
Seu programa deverá realizar a operação 
solicitada em cada caso.
\033[m""")


n1 = int(input("Primeiro valor: "))
n2 = int(input("Segundo valor: "))

resposta = 0

while resposta != 5:
    print("""    [ 1 ] somar
    [ 2 ] multiplicar
    [ 3 ] maior
    [ 4 ] novos números
    [ 5 ] sair do programa""")
    resposta = int(input(">>>>> Qual é a sua opação? "))
    if resposta == 1:
        print(f'{n1} + {n2} = {n1 + n2}')
        print(f'{"=" * 30}')
    if resposta == 2:
        print(f'{n1} * {n2} = {n1 * n2}')
        print(f'{"=" * 30}')
    if resposta == 3:
        if n1 > n2:
            print(f"{n1} > {n2}")
            print(f'{"=" * 30}')
        if n2 > n1:
            print(f"{n2} > {n1}")
            print(f'{"=" * 30}')
        if n1 == n2:
            print('Os dois valores são iguais.')
            print(f'{"=" * 30}')
    if resposta == 4:
        n1 = int(input('Primeiro valor: '))
        n2 = int(input('Segundo valor: '))
    if resposta <= 0 or resposta > 5:
        print('\033[31mRESPOSTA INVÁLIDA\033[m')
        print(f'{"=" * 30}')
    time.sleep(2)
print(f'{"=" * 30}')
print('\033[33mFIM!\033[m')
