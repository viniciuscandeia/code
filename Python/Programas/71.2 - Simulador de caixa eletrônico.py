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

nota = 50
tot_notas: int = 0
total = int(input('Digite o valor a ser sacado: '))

while True:
    if total >= nota:
        total -= nota
        tot_notas += 1
    else:
        if tot_notas > 0:
            print(f'Você sacou {tot_notas} de R$ {nota :.2f}')
        if nota == 50:
            nota = 20
        elif nota == 20:
            nota = 10
        elif nota == 10:
            nota = 5
        elif nota == 5:
             nota = 1
        tot_notas = 0
        if total == 0:
            break
