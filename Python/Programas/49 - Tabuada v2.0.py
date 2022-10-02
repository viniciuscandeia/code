print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' TABUADA v2.0 '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mRefaça o DESAFIO 009, mostrando a tabuada 
de um número que o usuário escolher, 
só que agora utilizando um laço for.
\033[m""")

n = int(input('Qual o número? '))
i = int(input('Início: '))
f = int(input('Fim: '))
print('=' * 45)

for c in range(i, f + 1):
    print(f'{n} x {c :^3} = {n * c :^3}')
print('=' * 45)