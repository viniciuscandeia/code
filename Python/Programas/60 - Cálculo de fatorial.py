print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"60 - CÁLCULO DE FATORIAL":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33m
Exercício Python 060: Faça um programa que 
leia um número qualquer e mostre o seu 
fatorial.

Ex: 5! = 5 x 4 x 3 x 2 x 1 = 120\033[m\n""")

n = int(input('Digite un número: '))
cont = n

f = 1
print(f'Calculando {n}!: ', end='')
while cont > 0:
    print(f'{cont}', end='')
    print(' x ' if cont > 1 else " = ", end='')
    f *= cont
    cont -= 1
print(f)

f = 1
print(f'Calculando {n}!: ', end='')
for c in range(n, 0, -1):
    print(f'{c} ', end='')
    print('x ' if c > 1 else "= ", end='')
    f *= c
print(f)
