print("\033[35m=\033[m" * 45)
print(f'\033[35m{"57 - VALIDAÇÃO DE DADOS" :^45}\033[m')
print("\033[35m=\033[m" * 45)
print("""\033[33mFaça um programa que leia o sexo de uma
pessoa, mas só aceite os valores 'M' ou 'F'.
Caso esteja errado, peça a digitação novamente
até ter um valor correto.\n\033[m""")

sexo = 0

while sexo != "F" and sexo != "M":
    sexo = input((str("Qual o seu sexo? "))).upper()
    if sexo == "F":
        print('Mulher')
    if sexo == "M":
        print('Homem')
    if sexo != "F" and sexo != 'M':
        print('\033[31mResposta inválida!\nDigite novamente.\n\033[m')
print('FIM')
