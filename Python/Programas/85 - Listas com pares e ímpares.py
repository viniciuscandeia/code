print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"85 - LISTAS COM PARES E ÍMPARES" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa onde o usuário possa digitar 
sete valores numéricos e cadastre-os em uma 
lista única que mantenha separados os valores 
pares e ímpares. No final, mostre os valores 
pares e ímpares em ordem crescente.\033[m\n""")

lista = [[], []]

for c in range(0, 7):
    valor = int(input('Digite um número: '))
    if valor % 2 == 0:
        lista[0].append(valor)
    elif valor % 2 == 1:
        lista[1].append(valor)

lista[0].sort()
lista[1].sort()

print(f'Os valores pares digitados foram {lista[0]}')
print(f'Os valores ímpares digitados foram {lista[1]}')
