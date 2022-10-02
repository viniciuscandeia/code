print("\033[35m{:=^40}\033[m".format(' PINTANDO PAREDE '))

l = float(input('Qual a largura da parede (em metros)? '))
c = float(input('Qual o comprimento da parede (em metros)? '))
print(f'A parede possui uma área de \033[31m{c * l :.2f}m²\033[m.')
print(f'E precisará de \033[34m{(c * l) / 2 :.2f} litros\033[m para ser pintada.')