print("\033[35m{:=^40}\033[m".format('='))
print('\033[35m{:^40}\033[m'.format(' CONTAGEM DE PARES'))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mCrie um programa que mostre na tela todos 
os números pares que estão no intervalo 
entre 1 e 50.\033[m""")

for c in range(0, 51, 2):
    print(c, end=' ')
