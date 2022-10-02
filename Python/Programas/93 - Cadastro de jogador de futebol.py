print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"93 - CADASTRO DE JOGADOR DE FUTEBOL" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que gerencie o 
aproveitamento de um jogador de futebol. 
O programa vai ler o nome do jogador e 
quantas partidas ele jogou. Depois vai 
ler a quantidade de gols feitos em cada 
partida. No final, tudo isso será guardado 
em um dicionário, incluindo o total de 
gols feitos durante o campeonato.\033[m\n""")

dados = dict()
gols = list()
soma = 0

dados['Nome'] = str(input('Nome do Jogador: '))
partidas = int(input(f'Quantas partidas {dados["Nome"]} jogou? '))
for c in range(0, partidas):
    gols.append(int(input(f'    Quantos gols na partida {c}? ')))
    soma += gols[c]
    
# soma = sum(partidas)

dados['Gols'] = gols[:]
dados['Total'] = soma

print("-=" * 20)
print(dados)

print("-=" * 20)
for k, v in dados.items():
    print(f'O campo "{k}" tem o valor {v}')

print("-=" * 20)
print(f'O jogador {dados["Nome"]} jogou {partidas} partidas.')
for c in range(0, 5):
    print(f'   => Na partida {c}, fez {gols[c]} gols.')
print(f'Fez um total de {dados["Total"]} gols.')
