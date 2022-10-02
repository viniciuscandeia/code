print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"87 - MAIS SOBRE MATRIZ EM PYTHON":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33m Aprimore o desafio anterior, mostrando 
no final: 
A) A soma de todos os valores pares digitados.
B) A soma dos valores da terceira coluna.
C) O maior valor da segunda linha.\033[m\n""")

s_par = s_ter = 0
matriz = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

for linha in range(0, 3):
    for coluna in range(0, 3):
        matriz[linha][coluna] = int(input(f'Digite o valor para [{linha}, {coluna}]: '))

print("-=" * 20)

for linha in range(0, 3):
    for coluna in range(0, 3):
        print(f'[{matriz[linha][coluna] :^5}]', end='')
        if matriz[linha][coluna] % 2 == 0:
            s_par += matriz[linha][coluna]
    s_ter += matriz[linha][2]
    print()
print('-=' * 20)
print(f'A soma dos valores pares é {s_par}.')
print(f'A soma dos valores da terceira coluna é {s_ter}.')
print(f'O maior valor da segunda linha é {max(matriz[1])}.')
