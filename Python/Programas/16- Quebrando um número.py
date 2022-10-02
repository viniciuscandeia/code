from math import trunc

print('\033[35m{:=^40}\033[m'.format(' QUEBRANDO NÚMEROS '))

n = float(input('Digite um número real: '))
print(f'A parte inteira do número \033[31m{n}\033[m é \033[33m{trunc(n)}\033[m.')

# print(f'A parte inteira do número \033[31m{n}\033[m é \033[33m{n :.0f}\033[m. ')
