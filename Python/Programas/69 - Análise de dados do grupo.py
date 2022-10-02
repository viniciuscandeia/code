print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"69 - ANÁLISE DE DADOS DO GRUPO" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia a idade e o sexo 
de várias pessoas. A cada pessoa cadastrada, 
o programa deverá perguntar se o usuário quer 
ou não continuar. No final, mostre:
A) quantas pessoas tem mais de 18 anos.
B) quantos homens foram cadastrados.
C) quantas mulheres tem menos de 20 anos. \033[m\n""")

maior_18 = 0
num_h = 0
mulher_20 = 0
resposta = 0
sexo = 0

while True:
    print(f'{"=-" * 20}')
    print(f'{"CADASTRO DO POVO" :^40}')
    print(f'{"=-" * 20}')
    idade = int(input('Digite a idade: '))
    while sexo != "H" and sexo != "M":
        print('[ H ] Homem \n[ M ] Mulher')
        sexo = str(input('Digite o sexo: ')).upper().strip()
        if sexo != "H" and sexo != "M":
            print('\033[31mResposta inválida. Tente novamente.\033[m')
    if idade > 18:
        maior_18 += 1
    if sexo == "H":
        num_h += 1
    if sexo == "M" and idade < 20:
        mulher_20 += 1
    while resposta != "S" and resposta != "N":
        resposta = str(input('Você quer continuar cadastrando [S/N]? ')).upper().strip()
        if resposta != "S" and resposta != "N":
            print('\033[31mResposta inválida. Tente novamente.\033[m')
    if resposta == "N":
        break
    sexo = 0
    resposta = 0

print(f'{"=-" * 20}')
print('Resumo dos cadastros:')
if maior_18 == 1:
    print('Apenas 1 pessoa com mais de 18 anos foi cadastrada.')
elif maior_18 > 1:
    print(f'{maior_18} pessoas com mais de 18 anos foram cadastradas.')
if num_h == 1:
    print('Apenas 1 homem foi cadastrado.')
elif num_h > 1:
    print(f'{num_h} homens foram cadastrados.')
if mulher_20 == 1:
    print('Apenas 1 mulher com menos de 20 anos foi cadastrada.')
elif mulher_20 > 1:
    print(f'{mulher_20} mulheres com menos de 20 anos foram cadastradas.')
