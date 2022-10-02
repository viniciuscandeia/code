print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"82 - DIVIDINDO VALORES DE UMA LISTA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que vai ler vários números 
e colocar em uma lista. Depois disso, crie 
duas listas extras que vão conter apenas os 
valores pares e os valores ímpares digitados, 
respectivamente. Ao final, mostre o conteúdo 
das três listas geradas.\033[m\n""")

lista_p = list()
lista_i = list()
lista = list()

while True:
    n = int(input('Digite um número: '))
    lista.append(n)
    r = str(input('Você quer continuar [S/N]? ')).strip().upper()
    if r == "N":
        break

for c in range(0, len(lista)):
    if lista[c] % 2 == 0:
        lista_p.append(lista[c])
    if lista[c] % 2 == 1:
        lista_i.append(lista[c])

print(f'A lista completa é {lista}')
print(f'A lista de pares é {lista_p}')
print(f'A lista de ímpares é {lista_i}')