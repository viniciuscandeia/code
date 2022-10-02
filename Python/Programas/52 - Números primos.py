print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' 50 - NÚMEROS PRIMOS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mFaça um programa que leia um número 
inteiro e diga se ele é ou não um número primo.\033[m""")

print('\n')

n = int(input('Digite um número: '))

s = 0
for c in range(1, n + 1):
    if n % c == 0:
        print('\033[34m', end='')
        s += 1
    else:
        print('\033[31m', end='')
    print(c, end=' ')

print(f'\n\033[35mO número {n} foi divisível {s} vezes\033[33m')
if s == 2:
    print('Logo, ele é primo.')
else:
    print('Assim, ele não é primo.')