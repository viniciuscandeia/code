print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' SOMA DOS PARES '))
print('\033[35m{:=^40}\033[35m'.format('='))
print("""\033[33mDesenvolva um programa que leia seis números 
inteiros e mostre a soma apenas daqueles que 
forem pares. Se o valor digitado for ímpar, 
desconsidere-o.\033[m""")

print('\n')

s = 0
for c in range(0, 6):
    n = int(input('Digite um número: '))
    if n % 2 == 0:
        s += n
print(s)