import random

print("\033[35m=\033[m" * 45)
print(f'\033[35m{"58 - JOGO DA ADVINHAÇÃO V2.0":^45}\033[m')
print("\033[35m=\033[m" * 45)
print("""\033[33mMelhore o jogo do DESAFIO 028 onde o 
computador vai "pensar" em um número 
entre 0 e 10. Só que agora o jogador vai 
tentar adivinhar até acertar, mostrando 
no final quantos palpites foram 
necessários para vencer.
\033[m""")

tentativas = 0
resposta = -1
valor = random.randint(0, 10)

print("Pensei em um número. Você pode advinhar qual? \nEle está no intervalo de 0 a 10.\n")

while resposta != valor:
    resposta = int(input("Qual seu palpite? "))
    tentativas += 1
    if resposta != valor:
        print("\033[31mERROU. Tente novamente.\033[m")
    else:
        print("\033[32mPARABÉNS! Você acertou!\033[m")
print("\033[33mFIM DO JOGO.\033[m")
if tentativas == 1:
    print('Você acertou na primeira tentaiva.')
else:
    print(f'Você acertou em {tentativas} tentativas.')
