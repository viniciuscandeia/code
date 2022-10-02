print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"94 - UNINDO DICIONÁRIOS E LISTAS" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia nome, sexo e idade 
de várias pessoas, guardando os dados de 
cada pessoa em um dicionário e todos os 
dicionários em uma lista. No final, mostre: 
A) Quantas pessoas foram cadastradas
B) A média de idade
C) Uma lista com as mulheres
D) Uma lista de pessoas com idade acima da média\033[m\n""")

temp = dict()
dados = list()
resposta = ' '
cont = soma_i = 0

while resposta != 'N':
    cont += 1
    temp['Nome'] = str(input('Nome: '))
    temp['Sexo'] = str(input('Sexo [M/F]: ')).upper().strip()
    while temp['Sexo'] not in 'MF':
        print('\033[31mERRO!\033[m Responda apenas com M ou F')
        temp['Sexo'] = str(input('Sexo [M/F]: ')).upper().strip()
    temp['Idade'] = int(input('Idade: '))
    resposta = str(input('\033[33mVocê quer continuar [S/N]? \033[m')).upper().strip()
    while resposta not in "SN":
        print('\033[31mERRO!\033[m Responda apenas com S ou N.')
        resposta = str(input('\033[33mVocê quer continuar [S/N]? \033[m')).upper().strip()
    print('-=' * 20)
    dados.append(temp.copy())
    temp.clear()

print(f'A) Ao todo, temos {cont} pessoas cadastradas.')

for c in range(0, cont):
    soma_i += dados[c]['Idade']
media_i = soma_i / cont
print(f'B) A média de idade é de \033[31m{media_i :.2f}\033[m anos.')

print(f'C) As mulheres cadastradas foram ', end='')
for c in range(0, cont):
    if dados[c]['Sexo'] == 'F':
        print(dados[c]['Nome'], end=' ')

print()
print(f'D) Lista de pessoas que estão acima da média:')
for p in dados:
    if p['Idade'] > media_i:
        print('   ', end='')
        for k, v in p.items():
            print(f'{k} = {v}', end='; ')
        print()
