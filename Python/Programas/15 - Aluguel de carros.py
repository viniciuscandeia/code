print('\033[35m{:=^40}\033[m'.format(' ALUGUEL DE CARROS '))

d = int(input('Quantos dias alugados? '))
km = float(input('Quandos Km rodados? '))
print(f'O total a pagar é \033[31mR${d * 60 + km * 0.15 :.1f}\033[m.')