print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' DETECTOR DE PALÍNDROMO '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mCrie um programa que leia uma frase qualquer 
e diga se ela é um palíndromo, desconsiderando 
os espaços.

Exemplos de palíndromos: 
APOS A SOPA, 
A SACADA DA CASA, 
A TORRE DA DERROTA, 
O LOBO AMA O BOLO, 
ANOTARAM A DATA DA MARATONA.\033[m""")


frase = str(input('\nDigite uma frase: ')).strip().upper()
palavras = frase.split()
junto = ''.join(palavras)
print(f'Você digitou a frase {frase}')

inverso = ''

for letra in range(len(junto, -1, -1)):
    inverso += junto[letra]
if inverso == junto:
    print('Temos um palíndromo.')
else:
    print('A frase digitada não é um palíndromo.')
