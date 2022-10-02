from random import randint
from time import sleep
from operator import itemgetter

print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"91 - JOGO DE DADOS EM PYTHON" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa onde 4 jogadores joguem um 
dado e tenham resultados aleatórios. Guarde 
esses resultados em um dicionário em Python. 
No final, coloque esse dicionário em ordem, 
sabendo que o vencedor tirou o maior número 
no dado.\033[m\n""")

ranking = list()
jogo = dict()

for c in range(1, 5):
    lancamento = randint(1, 6)
    print(f'Jogador {c} tirou {lancamento} no dado.')
    jogo[f'jogador{c}'] = lancamento
    sleep(1)

print("-=" * 20)
print(f'{"== RANKING DOS JOGADORES ==":^40}')

ranking = sorted(jogo.items(), key=itemgetter(1), reverse=True)

for i, v in enumerate(ranking):
    print(f'       {i + 1}º lugar: {v[0]} com {v[1]}')
    sleep(1)