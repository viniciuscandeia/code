print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' ÍNDICE DE MASSA CORPORAL '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mDesenvolva uma lógica que leia o peso e a 
altura de uma pessoa, calcule seu 
Índice de Massa Corporal (IMC) e 
mostre seu status, de acordo com a 
tabela abaixo:
- IMC abaixo de 18,5: Abaixo do Peso
- Entre 18,5 e 25: Peso Ideal
- 25 até 30: Sobrepeso
- 30 até 40: Obesidade
- Acima de 40: Obesidade Mórbida \033[m""")

massa = float(input('\nQual a sua massa (kg)? '))
altura = float(input('Qual a sua altura (m)? '))

IMC = massa / (altura ** 2)

if IMC < 18.5:
    print('\nSTATUS: \033[33mABAIXO DO PESO IDEAL\033[m')
elif 18.5 <= IMC < 25:
    print('\nSTATUS: \033[33mPESO IDEAL\033[m')
elif 25 <= IMC < 30:
    print('\nSTATUS: \033[33mSOBREPESO\033[m')
elif 30 <= IMC < 40:
    print('\nSTATUS: \033[33mOBESIDADE\033[m')
elif 40 <= IMC:
    print('\nSTATUS: \033[33mOBESIDADE MÓRBIDA\033[m')
