print('\033[35m{:=^40}\033[m'.format(' REAJUSTE SALARIAL '))

sa = float(input('Qual o seu salário atual? R$'))
print(f'O seu novo salário é \033[31m{sa * 1.15 :.2f} reais\033[m.')
