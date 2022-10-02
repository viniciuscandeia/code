from random import randint

print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"74 - MAIOR E MENOR VALORES EM TUPLA" :^45}\033[m')
print(f'\033[35m{"+" * 45}\033[m')
print("""\033[33mCrie um programa que vai gerar cinco números 
aleatórios e colocar em uma tupla. Depois 
disso, mostre a listagem de números gerados 
e também indique o menor e o maior valor 
que estão na tupla. \033[m\n""")

a = randint(1, 100)
b = randint(1, 100)
c = randint(1, 100)
d = randint(1, 100)
e = randint(1, 100)

tupla = (a, b, c, d, e)

print('Os valores sorteados foram: ', end='')

for c in range(0, 5):
    print(tupla[c], end=' ')

print(f'\nO maior valor sorteado foi {max(tupla)}')
print(f'O menor valor sorteado foi {min(tupla)}')
