print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"64 - TRATANDO VÁRIOS VALORES V1.0" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia vários números 
inteiros pelo teclado. O programa só vai 
parar quando o usuário digitar o valor 999, 
que é a condição de parada. No final, mostre 
quantos números foram digitados e qual foi 
a soma entre eles (desconsiderando o flag).\033[m\n""")

soma = 0
opcao = 0
cont = 0
opcao = int(input('Digite um número [999 para parar]: '))
while opcao != 999:
    soma += opcao
    cont += 1
    opcao = int(input('Digite um número [999 para parar]: '))

print(f'Você digitou {cont} números e a soma entre eles foi {soma}.')
