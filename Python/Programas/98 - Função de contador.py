from time import sleep


def contador(inicio, fim, passo):
    if passo < 0:
        passo *= -1
    sleep(0.3)
    print("-=" * 20)
    sleep(0.3)
    print(f'Contagem de {inicio} até {fim} de {passo} em {passo}')
    sleep(0.3)
    if fim > inicio:
        while True:
            if fim >= inicio:
                print(f'{inicio} ', end='')
                inicio += passo
                sleep(0.25)
            else:
                print('FIM!')
                break
    elif inicio > fim:
        while True:
            if inicio >= fim:
                print(f'{inicio} ', end='')
                inicio -= passo
                sleep(0.25)
            else:
                print('FIM!')
                break


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"98 - FUNÇÃO DE CONTADOR" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que tenha uma função chamada 
contador(), que receba três parâmetros: 
início, fim e passo. Seu programa tem que 
realizar três contagens através da função 
criada:

a) de 1 até 10, de 1 em 1
b) de 10 até 0, de 2 em 2
c) uma contagem personalizada\033[m\n""")

contador(1, 10, 1)
contador(10, 0, 2)

print('-=' * 20)
print('Agora é sua vwz de personalizar a contagem!')
i = int(input(f'{"Ínicio: " :<10}'))
f = int(input(f'{"Fim: " :<10}'))
p = 0
while p == 0:
    p = int(input(f'{"Passo: " :<10}'))
    if p == 0:
        print('\033[31mERRO!\033[m Valor inválido.')
contador(i, f, p)
