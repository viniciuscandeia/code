print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"86 - MATRIZ EM PYTHON" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que declare uma matriz de 
dimensão 3x3 e preencha com valores lidos 
pelo teclado. No final, mostre a matriz na 
tela, com a formatação correta\033[m""")

matriz = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

for linha in range(0, 3):
    for coluna in range(0, 3):
        matriz[linha][coluna] = int(input(f'Digite o valor para [{linha}, {coluna}]: '))

for linha in range(0, 3):
    for coluna in range(0, 3):
        print(f'[{matriz[linha][coluna] :^5}]', end='')
    print()
