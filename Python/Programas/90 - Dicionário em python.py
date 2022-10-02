print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"90 - DICIONÁRIO EM PYTHON" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mFaça um programa que leia nome e média de um 
aluno, guardando também a situação em um 
dicionário. No final, mostre o conteúdo da 
estrutura na tela.\033[m\n""")

dados = dict()

dados['Nome'] = str(input('Nome: '))
dados['Média'] = float(input('Média: '))

if dados['Média'] >= 7:
    dados['Situacao'] = 'aprovado'
elif 7 > dados['Média'] >= 5:
    dados['Situacao'] = 'recuperação'
else:
    dados['Situacao'] = 'reprovado'

print("-=" * 20)

for k, v in dados.items():
    print(f'   - {k} é igual a {v}')
