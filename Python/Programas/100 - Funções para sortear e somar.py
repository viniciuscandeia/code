from random import randint

numeros = list()


def sorteia():
    print('Sorteando 5 valores: ', end='')
    for c in range(0, 5):
        numeros.append(randint(1, 10))
        print(f'{numeros[c]} ', end='')
    print('PRONTO!')


def somapar():
    soma = 0
    print(f'Somando os valores pares de {numeros}, temos ', end='')
    for p in numeros:
        if p % 2 == 0:
            soma += p
    print(soma)


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"100 - FUNÇÕES PARA SORTEAR VALORES E SOMAR" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que tenha uma lista chamada 
números e duas funções chamadas sorteia() e 
somaPar(). A primeira função vai sortear 5 
números e vai colocá-los dentro da lista e 
a segunda função vai mostrar a soma entre 
todos os valores pares sorteados pela função 
anterior.\033[m\n""")

sorteia()
somapar()
