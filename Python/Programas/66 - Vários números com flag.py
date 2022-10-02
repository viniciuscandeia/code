print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"66 - VÁRIOS NÚMEROS COM FLAG" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia números inteiros 
pelo teclado. O programa só vai parar quando 
o usuário digitar o valor 999, que é a 
condição de parada. No final, mostre quantos 
números foram digitados e qual foi a soma 
entre elas (desconsiderando o flag).\033[m\n""")

num = 0
soma = 0
cont = 0

while True:
    num = int(input('Digite um número [999 para parar]: '))
    if num == 999:
        break
    soma += num
    cont += 1
print('\033[33mFIM\033[m')
print(f'Você digitou {cont} números e a soma deles foi {soma}.')