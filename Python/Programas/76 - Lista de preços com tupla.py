print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"76 - LISTA DE PREÇOS COM TUPLA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que tenha uma tupla única 
com nomes de produtos e seus respectivos 
preços, na sequência. No final, mostre uma 
listagem de preços, organizando os dados em 
forma tabular.\033[m\n""")

print(f'{"-" * 45}')
print(f'{"LISTAGEM DE PREÇOS" :^45}')
print(f'{"-" * 45}')

tupla = ("Lápis", 1.75, "Borracha", 2.00, "Caderno", 15.90,
         "Estojo", 25.00, "Transferidor", 4.20, "Compasso", 9.99,
         "Mochila", 120.32, "Canetas", 22.30, "Livro", 34.90)

for pos, c in enumerate(tupla):
    if pos % 2 == 0:
        print(f'{tupla[pos] :.<35 }', end='')
        print(f'R${tupla[pos + 1] :>7.2f}')
print(f'{"-" * 45}')
