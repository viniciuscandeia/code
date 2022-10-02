print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"70 - ESTATÍSTICAS EM PRODUTOS" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia o nome e o 
preço de vários produtos. O programa deverá 
perguntar se o usuário vai continuar ou não. 
No final, mostre:
A) qual é o total gasto na compra.
B) quantos produtos custam mais de R$1000.
C) qual é o nome do produto mais barato. \033[m\n""")

valor = 0
menor = 0
m_1000 = 0
cont = 0
soma = 0
resposta = 0

while True:
    nome = str(input('Digite o nome do produto: '))
    valor = float(input('Digite o preço do produto: '))
    soma += valor
    cont += 1
    if cont == 1:
        menor = valor
    elif cont > 1:
        if valor < menor:
            menor = valor
    if valor > 1000:
        m_1000 += 1
    while resposta != 'N' and resposta != 'S':
        resposta = str(input('Você quer continuar [S/N]? ')).upper().strip()
        if resposta != 'N' and resposta != 'S':
            print('\033[31mResposta inválida. Tente novamente.\033[m')
        print(f'{"-=" * 20}')
    if resposta == "N":
        break
    resposta = 0

print(f'Você gastou um total de R$ {soma :.2f} .')
print(f'{m_1000} produtos custaram mais de R$ 1000,00 .')
print(f'O produto mais barato custou R$ {menor :.2f} .')
