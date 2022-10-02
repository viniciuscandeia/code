print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"80 - LISTA ORDENADA SEM REPETIÇÕES" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa onde o usuário possa digitar 
cinco valores numéricos e cadastre-os em uma 
lista, já na posição correta de inserção 
(sem usar o sort()). No final, mostre a lista 
ordenada na tela.\033[m\n""")

lista = list()
maior = menor = 0

for c in range(0, 5):
    n = int(input('Digite um valor: '))
    if c == 0 or n > lista[-1]:
        lista.append(n)
        print('Aicionado ao final da lista...')
    else:
        pos = 0
        while pos < len(lista):
            if n <= lista[pos]:
                lista.insert(pos, n)
                print(F'Adicionado á posição {pos} da lista...')
                break
            pos += 1
print(lista)