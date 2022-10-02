print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' AUMENTOS MÚLTIPLOS '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mEscreva um programa que pergunte o 
salário de um funcionário e calcule o 
valor do seu aumento.
Para salários superiores a "R$1.250,00",
calcule um aumento de 10%.
Para inferiores ou iguais, o aumento é 
de 15%.\033[m''')

sal = float(input('\nQual o valor do salário? '))
if sal > 1250.00:
    sal_n = sal * 1.10
    print(f'O valor do novo salário é \033[31mR${sal_n}\033[m.')
else:
    sal_n = sal * 1.15
    print(f'O valor do novo salário é \033[31m{sal_n}\033[m.')
