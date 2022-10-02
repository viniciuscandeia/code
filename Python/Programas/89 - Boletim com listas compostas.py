print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"89 - BOLETIM COM LISTAS COMPOSTAS":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia nome e duas notas 
de vários alunos e guarde tudo em uma lista 
composta. No final, mostre um boletim 
contendo a média de cada um e permita que o 
usuário possa mostrar as notas de cada aluno 
individualmente.\033[m""")

resp = 0
info = []
temp = []

while True:
    nome = str(input('Nome: '))
    nota1 = float(input('Nota 1: '))
    nota2 = float(input('Nota 2: '))
    media = (nota1 + nota2) / 2
    r = str(input('Você quer continuar [S/N]? '))
    # info.append([nome, [nota1, nota2], media])
    temp.append(nome)
    temp.append(nota1)
    temp.append(nota2)
    temp.append(media)
    info.append(temp[:])
    temp.clear()
    if r in "Nn":
        break
    print('=' * 30)

print('=-=' * 15)
print()
print(f'{"No.":<5} {"NOME" :<13} {"MÉDIA" :<5}', f'\n{"-" * 30}')
for c in range(0, len(info)):
    print(f'{c :<6}{info[c][0]:<16}{info[c][3] :>3}')
print('-' * 30)

while True:
    resp = int(input('Mostrar notas de qual aluno? (999 interrompe) '))
    if resp == 999:
        break
    print(f'As notad de {info[resp][0]} foram: {info[resp][1]} e {info[resp][2]}')
