print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' AQUELE CLÁSSICO DE MÉDIA '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mCrie um programa que leia duas notas 
de um aluno e calcule sua média, 
mostrando uma mensagem no final, 
de acordo com a média atingida:
- Média abaixo de 5.0: REPROVADO
- Média entre 5.0 e 6.9: RECUPERAÇÃO
- Média 7.0 ou superior: APROVADO \033[m""")

n1 = float(input('\nQual o valor da primeira nota? '))
n2 = float(input('Qual o valor da segunda nota? '))
m = (n1 + n2) / 2
print('=' * 30)

if m < 5:
    print('\033[31mSTATUS: REPROVADO\033[m')
elif 5 <= m < 7:
    print('\033[33mSTATUS: RECUPERAÇÃO\033[m')
    if n1 > n2:
        N2 = 14 - n1
        print(f'Você tem que tirar, pelo menos, \033[33m{N2}\033[m.')
    elif n1 == n2:
        N2 = 14 - n1
        print(f'Você tem que tirar, pelo menos, \033[33m{N2}\033[m.')
    else:
        N1 = 14 - n2
        print(f'Você tem que tirar, pelo menos, \033[33m{N1}\033[m.')
else:
    print('\033[34mSTATUS: APROVADO\033[m')