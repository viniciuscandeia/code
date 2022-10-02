from random import randint

print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' PEDRA - PAPEL - TESOURA '))
print('\033[35m{:=^40}\033[m'.format('='))
print("""\033[33mCrie um programa que faça o computador 
jogar Jokenpô com você.
 \033[m""")

print("""\n\033[31m( 1 ) PEDRA\033[m
\033[33m( 2 ) PAPEL\033[m
\033[34m( 3 ) TESOURA\033[m""")
player = int(input('Qual opção você escolhe? '))

pc = randint(1, 3)

if player == 1 and pc == 2:
    print('\n\033[32mVENCEDOR: PC\033[m')
    print(f'Você escolheu: \033[31mPEDRA\033[m')
    print(f'PC escolheu: \033[33mPAPEL\033[m')
elif player == 1 and pc == 3:
    print('\n\033[35mVENCEDOR: JOGADOR\033[m')
    print(f'Você escolheu: \033[31mPEDRA\033[m')
    print(f'PC escolbeu: \033[34mTESOURA\033[m')
elif player == 2 and pc == 1:
    print('\n\033[35mVENCEDOR: JOGADOR\033[m')
    print('Você escolheu: \033[33mPAPEL\033[m')
    print('PC escolheu: \033[31mPEDRA\033[m')
elif player == 2 and pc == 3:
    print('\n\033[32mVENCEDOR: PC\033[m')
    print('Você escolheu: \033[33mPAPEL\033[m')
    print('PC escolheu: \033[34mTESOURA\033[m')
elif player == 3 and pc == 1:
    print('\n\033[32mVENCEDOR: PC\033[m')
    print('Você escolheu: \033[34mTESOURA\033[m')
    print('PC escolheu: \033[31mPEDRA\033[m')
elif player == 3 and pc == 2:
    print('\n\033[35mVENCEDOR: JOGADOR\033[m')
    print('Você escolheu: \033[34mTESOURA\033[m')
    print('PC escolheu: \033[33mPAPEL\033[m')
elif player == pc:
    print('\n\033[36mEMPATE!\033[m')
else:
    print('OPÇÃO INVÁLIDA!')
