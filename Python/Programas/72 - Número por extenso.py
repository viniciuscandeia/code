print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"72 - NÚMERO POR EXTENSO" :^45}\033[m')
print(f'\033[35m{"=" * 45}')
print("""\033[33mCrie um programa que tenha uma tupla 
totalmente preenchida com uma contagem por 
extenso, de zero até vinte. Seu programa 
deverá ler um número pelo teclado 
(entre 0 e 20) e mostrá-lo por extenso.\033[m\n""")

tupla = ("zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove", "vinte")

valor = -1
resposta = ' '

while True:
    while valor < 0 or valor > 20:
        valor = int(input('Digite um númerp entre 0 e 20: '))
        if valor >= 0 and valor <= 20:
            print(f'Você digitou o número {tupla[valor]}.')
            break
        else:
            print('\033[31mNúmero inválido. Tente novamente.\033[m')
    while resposta not in "SN":
        resposta = str(input('Você quer continuar [S/N]? ')).upper().strip()
        if resposta not in "SN":
            print('\033[31mResposta inválida. Tente novamente.\033[m')
    print(f'{"=" * 40}')
    if resposta == "N":
        break
    valor = -1
    resposta = ' '

print('\033[33mPrograma finalizado.\033[m')