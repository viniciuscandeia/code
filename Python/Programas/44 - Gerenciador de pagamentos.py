print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' GERENCIADOR DE PAGAMENTOS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mElabore um programa que calcule o valor 
a ser pago por um produto, considerando 
o seu preço normal e condição de pagamento:
- à vista dinheiro/cheque: 10% de desconto
- à vista no cartão: 5% de desconto
- em até 2x no cartão: preço formal
- 3x ou mais no cartão: 20% de juros
 \033[m""")

preco = float(input('Qual o preço do produto? R$'))

print('=' * 40)
print("""( 1 ) À vista (dinheiro/cheque): 10% de desconto
( 2 ) À vista (cartão): 5% de desconto
( 3 ) Em 2x (cartão): preço normal
( 4 ) 3x ou mais (cartâo): 20% de juros""")
print('=' * 40)
pag = int(input('Qual a opção de pagamento? '))

if pag == 1:
    valor = 0.9 * preco
    print(f'VALOR: \033[31mR${valor :.2f}\033[m')
elif pag == 2:
    valor = 0.95 * preco
    print(f'VALOR: \033[31mR${valor :.2f}\033[m')
elif pag == 3:
    valor = preco
    print(f'VALOR TOTAL: \033[31mR${valor :.2f}\033[m')
    parcela = valor / 2
    print(f'PARCELA: \033[34mR${parcela :.2f}\033[m')
elif pag == 4:
    valor = 1.2 * preco
    print(f'VALOR TOTAL: \033[31mR${valor :.2f}\033[m')
    num_p = int(input('Em quantas vezes você quer dividir? '))
    parcela = valor / num_p
    print(f'PARCELA: \033[34mR${parcela}\033[m')
else:
    print('\033[33mOPÇÃO INVÁLIDA!\033[m')
