from time import sleep

print("\033[35m{:=^40}\033[m".format('='))
print('\033[35m{:^40}\033[m'.format(' CONTAGEM REGRESSIVA '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mFaça um programa que mostre na tela uma 
contagem regressiva para o estouro de 
fogos de artifício, indo de 10 até 0, 
com uma pausa de 1 segundo entre eles.\033[m""")

print('\n')

for c in range(10, 0, -1):
    print(c)
    sleep(1)
print('\033[33mHAPPY NEW YEAR\033[m')