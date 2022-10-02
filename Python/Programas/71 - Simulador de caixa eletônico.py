print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"71 - SIMULADOR DE CAIXA ELETRÔNICO" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que simule o funcionamento 
de um caixa eletrônico. No início, pergunte 
ao usuário qual será o valor a ser sacado 
(número inteiro) e o programa vai informar 
quantas cédulas de cada valor serão 
entregues.
OBS: considere que o caixa possui cédulas 
de R$50, R$20, R$10 e R$1.\033[m\n""")

sacar = 0
notas = 0

while True:
    sacar = int(input('Digite o valor a ser sacado: '))

    div50 = sacar // 50
    n50 = div50
    if n50 > 0:
        rest50 = sacar - n50 * 50
    elif n50 == 0:
        rest50 = sacar

    div20 = rest50 // 20
    n20 = div20
    if n20 > 0:
        rest20 = rest50 - n20 * 20
    elif n20 == 0:
        rest20 = rest50

    div10 = rest20 // 10
    n10 = div10
    if n10 > 0:
        rest10 = rest20 - n10 * 10
    elif n10 == 0:
        rest10 = rest20

    div5 = rest10 // 5
    n5 = div5
    if n5 > 0:
        rest5 = rest10 - n5 * 5
    elif n5 == 0:
        rest5 = rest10

    div1 = rest5 // 1
    n1 = div1
    if n1 > 0:
        rest1 = rest5 - n1 * 1
    elif n1 == 0:
        rest1 = rest5
    break

print('Você sacou: ')
if n50 > 0:
    print(f'{n50} notas de R$ 50.00')
if n20 > 0:
    print(f'{n20} notas de R$ 20.00')
if n10 > 0:
    print(f'{n10} notas de R$ 10.00')
if n5 > 0:
    print(f'{n5} notas de R$ 5.00')
if n1 > 0:
    print(f'{n1} notas de R$ 1.00')
