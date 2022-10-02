print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"78 - MAIOR E MENOR VALORES NA LISTA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que leia 5 valores numéricos 
e guarde-os em uma lista. No final, mostre 
qual foi o maior e o menor valor digitado e 
as suas respectivas posições na lista.\033[m\n""")

lista = list()

for c in range(0, 5):
    lista.append(int(input(f'Digite o {c + 1}º valor: ')))

print(f'O maior valor foi {max(lista)} e ocupa ', end='')
if lista.count(max(lista)) == 1:
    print(f' a {lista.index(max(lista)) + 1}º posição')
else:
    print('as posições: ', end='')
    for c in range(0, 5):
        if max(lista) == lista[c]:
            print(f'{c + 1}º', end=' ')

print(f'\nO menor valor foi {min(lista)} e ocupa ', end='')
if lista.count(min(lista)) == 1:
    print(f' a {lista.index(min(lista)) + 1}º posição')
else:
    print('as posições: ', end='')
    for c in range(0, 5):
        if min(lista) == lista[c]:
            print(f'{c + 1}º', end=' ')
