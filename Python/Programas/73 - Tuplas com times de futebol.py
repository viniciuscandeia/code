print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"73 - TUPLAS COM TIMES DE FUTEBOL" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mExercício Python 073: Crie uma tupla 
preenchida com os 20 primeiros colocados da 
Tabela do Campeonato Brasileiro de Futebol, 
na ordem de colocação. Depois mostre:
a) Os 5 primeiros times.
b) Os últimos 4 colocados.
c) Times em ordem alfabética. 
d) Em que posição está o time da Chapecoense.\033[m""")

tupla = ("Flamengo", "Santos", "Palmeiras", "Grêmio", "Atlético-PR", "São Paulo", "Internacional", "Corinthians", "Fortaleza", "Goiás", "Bahia", "Vasco", "Atlético-MG", "Fluminense", "Botafogo", "Ceará", "Cruzeiro", "CSA", "Chapecoense", "Avaí")

print(tupla[:5])
print(tupla[16:])
print(sorted(tupla))
print(tupla.index("Chapecoense"))
