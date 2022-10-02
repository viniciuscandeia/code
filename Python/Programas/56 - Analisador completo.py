print('\033[35m=\033[m' * 45)
print(f'\033[35m{"56 - ANALISADOR COMPLETO" :^45}\033[m')
print('\033[35m=\033[m' * 45)
print("""\033[33mDesenvolva um programa que leia o nome, idade 
e sexo de 4 pessoas. No final do programa, mostre: 
A média de idade do grupo
Qual o nome do homem mais velho
Quantas mulheres têm menos de 20 anos.\033[m""")

s = 0
maior_h = 0
m = 0
nome_v = ''
total_m20: 0
for c in range(1, 5):
    print(f'{c}º pessoa')
    nome = str(input('Nome: ')).strip()
    idade = int(input('Idade: '))
    sexo = str(input('Sexo [M/F]: ')).strip()
    s += idade
    m = s / 4
    if c == 1 and sexo in 'Mn':
        maior_h = idade
        nome_v = nome
    if sexo in 'Mn' and idade > maior_h:
        maior_h = idade
        nome_v = nome
    if sexo in 'Ff' and idade < 20:
        total_m20 += 1

print(f'MÉDIA: {m}')
print(f'HOMEM MAIS VELHO E SUA IDADE: {nome_v}, {maior_h}')
print(f'TOTAL DE MULHERES COM MENOS DE 20 ANOS: {total_m20}')