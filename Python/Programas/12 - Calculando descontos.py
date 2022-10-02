print('\033[35m{:=^40}\033[m'.format(' CALCULANDO DESCONTOS '))

pa = float(input('Qual o preço atual do produto? R$'))
print(f'O produto ficará por \033[31m{pa * 0.95 :.2f} reais\033[m na promoção.')
