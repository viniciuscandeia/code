import math

print('\033[35m{:=^40}\033[m'.format(' SENO, COSSENO E TANGENTE '))

ang = float(input('Digite o ângulo: '))
# O valor entra em graus
# Torna-se necessário uma conversão para radianos
print(f'O seno de \033[33m{ang}°\033[m é \033[36m{math.sin(math.radians(ang)) :.1f}\033[m.')
print(f'O cosseno de \033[33m{ang}°\033[m é \033[31m{math.cos(math.radians(ang)) :.1f}\033[m.')
print(f'A tangente de \033[33m{ang}°\033[m é \033[34m{math.tan((math.radians(ang))) :.1f}\033[m.')
