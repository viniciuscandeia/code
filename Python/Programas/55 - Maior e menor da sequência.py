print('\033[35m=\033[m' * 45)
print(f'\033[35m{" 55 - MAIOR E MENOR DA SEQUÊNCIA " :^45}\033[m')
print('\033[35m=\033[m' * 45)
print("""\033[33mFaça um programa que leia o peso de cinco 
pessoas. No final, mostre qual foi o maior 
e o menor peso lidos.\033[m""")

menor = 0
maior = 0

for c in range(1, 6):
    peso = float(input('Peso (kg): '))
    if c == 1:
        maior = peso
        menor = peso
    else:
        if peso > maior:
            maior = peso
        elif menor < peso:
            menor = peso

print(maior)
print(menor)
