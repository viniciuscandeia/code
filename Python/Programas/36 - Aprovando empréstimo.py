print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' APROVANDO EMPRÉSTIMO '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mEscreva um programa para aprovar o empréstimo 
bancário para a compra de uma casa. Pergunte o 
valor da casa, o salário do comprador e em 
quantos anos ele vai pagar. 
A prestação mensal não pode exceder 30% 
do salário ou então o empréstimo será negado.
\033[m""")

preco = float(input('Qual o valor do imóvel? R$ '))
sal = float(input('Qual o salário do comprador? R$ '))
tempo = int(input('Em quantos anos é pretendido pagar? '))

parcela = preco / (tempo * 12)

if parcela <= 0.3 * sal:
    print('\n\033[33mSTATUS: FINANCIAMENTO DISPONÍVEL\033[m')
else:
    print('\n\033[33mSTATUS: FINANCIAMENTO INDISPONÍVEL\033[m')
    tempo_m = preco / (3.6 * sal)
    print(f'Será preciso, no mínimo, \033[31m{tempo_m + 1 :.0f} anos\033[m.')
