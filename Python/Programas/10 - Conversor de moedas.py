print("\033[35m{:=^40}\033[m".format(' CONVERSOR DE MOEDAS '))

m = float(input('Quantos reais você possui? '))
print(f'Você pode comprar \033[31m{m / 3.27 :.2f}\033[m dólares.')
