def escreva(msg):
    t = len(msg) + 4
    print('~' * t)
    print(f'  {msg}')
    print('~' * t)


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{" 97 - UM PRINT ESPECIAL" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que tenha uma função chamada 
escreva(), que receba um texto qualquer como 
parâmetro e mostre uma mensagem com tamanho 
adaptável.

Ex: 
escreva('Olá, Mundo!')
Saída:
~~~~~~~~~~~~~
 Olá, Mundo!
~~~~~~~~~~~~~\033[m\n""")


escreva('Vinicius Candeia')
