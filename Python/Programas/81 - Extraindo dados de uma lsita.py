print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"81 - EXTRAINDO DADOS DE UMA LISTA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que vai ler vários números 
e colocar em uma lista. Depois disso, mostre:
A) Quantos números foram digitados.
B) A lista de valores, ordenada de forma 
decrescente.
C) Se o valor 5 foi digitado e está ou não 
na lista.\033[m\n""")

lista = list()

while True:
    n = int(input('Digite um número: '))
    lista.append(n)
    r = str(input('Quer continuar? [S/N] ')).upper().strip()
    if r == "N":
        break

print(f'Você digitou {len(lista)} elementos.')
lista.sort(reverse=True)
print(f"Os valores em ordem decrescente são {lista}")
if 5 in lista:
    print('O valor 5 faz parte da lista')
else:
    print('O valor 5 não foi encontrado na lista!')
