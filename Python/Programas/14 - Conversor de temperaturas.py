print('\033[35m{:=^40}\033[m'.format(' CONVERSOR DE TEMPERATURAS '))

t = float(input('Informe a temperatura em °C: '))
print(f'A temperatura \033[31m{t}°C\033[m é \033[33m{(t * 1.8) + 32 :.1f}°F\033[m.')
