print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"62 - SUPER PROGRESSÃO ARITMÉTICA V3.0" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mMelhore o DESAFIO 061, perguntando para o 
usuário se ele quer mostrar mais alguns 
termos. O programa encerrará quando ele 
disser que quer mostrar 0 termos.
\033[m""")

a1 = int(input('Primeiro termo: '))
r = int(input('Razão: '))

cont = 0
an = a1
final = 9
resposta = 1

while resposta != 0:
    while cont <= final:
        print(f'{an}', end='')
        print(" > ", end='')
        cont += 1
        an += r
    print('PAUSA!')
    resposta = int(input('Quantos termos quer mostrar a mais? '))
    if resposta != 0:
        final += resposta

print(f"Progressão finalizada com {cont} termos.")
