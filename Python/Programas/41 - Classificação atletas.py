print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' CLASSIFICAÇÃO ATLETAS '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mA Confederação Nacional de Natação precisa 
de um programa que leia o ano de 
nascimento de um atleta e mostre 
sua categoria, de acordo com a idade:
- Até 9 anos: MIRIM
- Até 14 anos: INFANTIL
- Até 19 anos: JÚNIOR
- Até 25 anos: SÊNIOR
- Acima de 25 anos: MASTER \033[m""")

from datetime import date

ano_a = int(input('\nQual o ANO de seu nascimento? '))

dif_a = date.today().year - ano_a

if dif_a <= 9:
    print('CLASSIFICAÇÃO: \033[33mMIRIM\033[m')
elif 9 < dif_a <= 14:
    print('CLASSIFICAÇÃO: \033[33mINFANTIL\033[m')
elif 14 < dif_a <= 19:
    print('CLASSIFICAÇÃO: \033[33mJÚNIOR\033[m')
elif 19 < dif_a <= 25:
    print('CLASSIFICAÇÃO: \033[33mSÊNIOR\033[m')
elif dif_a > 25:
    print('CLASSIFICAÇÃO: \033[33mMASTER\033[m')
