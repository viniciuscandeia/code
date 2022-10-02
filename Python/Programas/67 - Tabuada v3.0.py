print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"67 - TABUADA V3.0" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que mostre a tabuada 
de vários números, um de cada vez, para 
cada valor digitado pelo usuário. O 
programa será interrompido quando o 
número solicitado for negativo. \033[m""")

num = 0

while True:
    num = int(input('Digite um número \n[valor negativo para parar]: '))
    if num < 0:
        break
    for c in range(1, 11):
        print(f'{num} x {c} = {num * c}')
