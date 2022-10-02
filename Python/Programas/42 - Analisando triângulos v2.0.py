print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' ANALISANDO TRIÂNGULOS v2.0 '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mRefaça o DESAFIO 035 dos triângulos, 
acrescentando o recurso de mostrar 
que tipo de triângulo será formado:
- EQUILÁTERO: todos os lados iguais
- ISÓSCELES: dois lados iguais, um diferente
- ESCALENO: todos os lados diferentes \033[m""")

l1 = float(input('\nDigite o comprimento da primeira reta: '))
l2 = float(input('Digite o comprimento da segunda reta: '))
l3 = float(input('Digite o comprimento da terceira reta: '))

if l1 + l2 > l3 and l2 + l3 > l1 and l1 + l3 > l2:
    print(f'''\nÉ possível formar um triângulo com os 
lados {l1}, {l2} e {l3}.''')
    if l1 == l2 == l3:
        print('O triângulo será \033[33mEQUILÁTERO\033[m.')
    elif l1 == l2 != l3 or l1 == l3 != l2 or l2 == l3 != l1:
        print('O triângulo será \033[33mISÓSCELES\033[m.')
    elif l1 != l2 != l3:
        print('O triângulo será \033[33mESCALENO\033[m.')
else:
    print(f'''Não é possível formar um triângulo com os 
lados {l1}, {l2} e {l3}.''')
