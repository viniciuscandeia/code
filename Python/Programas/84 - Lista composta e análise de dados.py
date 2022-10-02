print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{" 84 - LISTA COMPOSTA E ANÁLISE DE DADOS" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que leia nome e peso de 
várias pessoas, guardando tudo em uma lista. 
No final, mostre:
A) Quantas pessoas foram cadastradas.
B) Uma listagem com as pessoas mais pesadas.
C) Uma listagem com as pessoas mais leves.\033[m\n""")

galera = list()
dado = list()
maior = menor = 0

while True:
    dado.append(str(input('Nome: ')))
    dado.append(float(input('Peso: ')))
    galera.append(dado[:])
    dado.clear()
    r = str(input('Quer continuar [S/N]? '))
    if r in "Nn":
        break

print(f'Ao todo, você cadastrou {len(galera)} pessoas')

for p in range(0, len(galera)):
    if p == 0:
        maior = galera[p][1]
        menor = galera[p][1]
    else:
        if galera[p][1] >= maior:
            maior = galera[p][1]
        elif galera[p][1] <= menor:
            menor = galera[p][1]

print(f'O maior peso foi de {maior :.1f}kg. Peso de ', end='')
for c in range(0, len(galera)):
    if maior == galera[c][1]:
        print(f'[{galera[c][0]}]', end=' ')
print()

print(f'O menor peso foi de {menor :.1f}kg. Peso de ', end='')
for d in range(0, len(galera)):
    if menor == galera[d][1]:
        print(f'[{galera[d][0]}]', end=' ')
print()
