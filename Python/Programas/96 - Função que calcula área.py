def area(larg, comp):
    v_area = larg * comp
    print(f'A área de um terreno de {larg}x{comp} é {v_area}m².')


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"96 - FUNÇÃO QUE CALCULA ÁREA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que tenha uma função 
chamada área(), que receba as dimensões de 
um terreno retangular (largura e 
comprimento) e mostre a área do terreno.\033[m\n""")

print(' CONTOLE DE TERRENOS ')
print('-' * 21)

lar = float(input('LARGURA (m): '))
com = float(input('COMPRIMENTO (m): '))
area(lar, com)
