print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"65 - MAIOR E MENOR VALORES" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia vários números 
inteiros pelo teclado. No final da execução, 
mostre a média entre todos os valores e qual 
foi o maior e o menor valores lidos. O 
programa deve perguntar ao usuário se ele 
quer ou não continuar a digitar valores.\033[m\n""")

s = cont = 0
maior = menor = 0
resposta = ' '

while resposta != "N":
    n = int(input("Digite um número: "))
    cont += 1
    s += n
    if cont == 1:
        maior = menor = n
    else:
        if n > maior:
            maior = n
        if n < menor:
            menor = n
    resposta = str(input('Você quer continuar [S/N]? ')).upper().strip()[0]
    if resposta != "S" and  resposta != "N":
        print('\033[31m\nResposta inválida! Tente novamente.\033[m')
        print('\033[31mPrograma forçado a parar!\033[m')
        resposta = "N"
    print(f'{"=" * 45}')
print(f'Você digitou {cont} números e a média foi {s / cont :.2f}.')
print(f'O maior valor foi {maior} e o menor foi {menor}.')