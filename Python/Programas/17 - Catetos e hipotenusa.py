from math import sqrt, pow, hypot

print('\033[35m{:=^40}\033[m'.format(' CATETOS E HIPOTENUSA '))

b = float(input('Qual o lado do cateto? '))
c = float(input('Qual o lado do outro cateto? '))
print(f"O triângulo de catetos \033[33m{b}\033[m e \033[33m{c}\033[m",  end=' ')
print(f'tem a hipotenusa \033[31m{sqrt(pow(b, 2) + pow(c, 2)) :.1f}\033[m.')

# print(f'\033[31m{hypot(b, c)}\033[m')
