print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"95 - APRIMORANDO OS DICIONÁRIOS" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mAprimore o desafio 93 para que ele funcione 
com vários jogadores, incluindo um sistema 
de visualização de detalhes do aproveitamento 
de cada jogador.\033[m\n""")

jogador = dict()
gols = list()
jogadores = list()

while True:
    jogador.clear()
    jogador['Nome'] = str(input('Nome do jogador: '))
    partidas = int(input(f'Quantas partidas {jogador["Nome"]} jogou? '))

    gols.clear()
    for c in range(0, partidas):
        gols.append(int(input(f'  - Quantos gols na partida {c}? ')))

    jogador['Gols'] = gols[:]
    jogador['Total'] = sum(gols)
    jogadores.append(jogador.copy())

    resposta = str(input('Quer continuar [S/N]? ')).upper().strip()[0]
    if resposta not in "SN":
        print('\033[31mERRO!\033[m Digite apenas S ou N.')
        while resposta not in "SN":
            resposta = str(input('Quer continuar [S/N]? ')).upper().strip()[0]
    print('-=' * 20)
    if resposta == "N":
        break

print('Cód ', end='')
for k in jogador.keys():
    print(f'{k :<15}', end='')
print()

print('-' * 41)

for k, v in enumerate(jogadores):
    print(f'{k :>3} ', end='')
    for d in v.values():
        print(f'{str(d) :<15}', end='')
    print()
print('-' * 41)

while True:
    resposta2 = int(input('Mostrar dados de qual jogador [999 para parar]? '))
    if resposta2 == 999:
        break
    if resposta2 >= len(jogadores) or resposta2 < 0:
        print('\033[31mCódigo inválido!\033[m Tente novamente.')
    if -1 < resposta2 < len(jogadores):
        print(f' -- LEVANTAMENTO DO JOGADOR: {jogadores[resposta2]["Nome"]} --')
        for c in range(0, len(jogadores[resposta2]["Gols"])):
            print(f'    No jogo {c + 1}, fez {jogadores[resposta2]["Gols"][c]}.')
    print('-' * 41)

print('<< VOLTE SEMPRE >>')
