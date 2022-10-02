print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"75 - ANÁLISE DE DADOS DE UMA TUPLA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mDesenvolva um programa que leia quatro 
valores pelo teclado e guarde-os em uma 
tupla. No final, mostre:

A) Quantas vezes apareceu o valor 9.
B) Em que posição foi digitado o primeiro 
valor 3.
C) Quais foram os números pares.\033[m\n""")

a = int(input('Digite o 1º número: '))
b = int(input('Digite o 2º número: '))
c = int(input('Digite o 3º número: '))
d = int(input('Digite o 4º número: '))

par = num_9 = 0
pos_3 = 0
tupla = (a, b, c, d)

for c in tupla:
    if c == 9:
        num_9 += 1
    if c % 2 == 0:
        par += 1

print(f'Você digitou os valores {tupla}')
if num_9 > 0:
    print(f'O valor 9 apareceu {num_9} vezes.')
if 3 in tupla:
    print(f'O valor 3 apareceu na {tupla.index(3) + 1}º posição')
if par > 0:
    print(f'Os valores pares digitados foram: ', end='')
    for d in tupla:
        if d % 2 == 0:
            print(d, end=' ')
