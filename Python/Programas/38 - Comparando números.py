print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' COMPARANDO NÚMEROS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mEscreva um programa que leia dois números 
inteiros e compare-os. mostrando na tela 
uma mensagem:
- O primeiro valor é maior
- O segundo valor é maior
- Não existe valor maior, os dois são iguais\033[m""")

n1 = int(input('\nEscreva um número: '))
n2 = int(input('Escreva outro número: '))

if n1 > n2:
    print(f'{n1} > {n2}')
    print('O PRIMEIRO número é o maior.')
elif n1 == n2:
    print(f'{n1} = {n2}')
    print('Os DOIS números são iguais.')
else:
    print(f'{n1} < {n2}')
    print('O SEGUNDO número é o maior.')
