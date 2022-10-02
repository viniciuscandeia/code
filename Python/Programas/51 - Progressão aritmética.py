print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' PROGRESSÃO ARITMÉTICA '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mDesenvolva um programa que leia o primeiro termo 
e a razão de uma PA. No final, mostre 
os 10 primeiros termos dessa progressão.\033[m""")

print('\n')

a1 = int(input('Primeiro termo: '))
r = int(input('Razão: '))
print('=' * 45)

for c in range(a1, a1 + 9 * r + r, r):
    print(c)

print('=' * 45)