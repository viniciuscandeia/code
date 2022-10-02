print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"79 - VALORES ÚNICOS EM UMA LISTA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa onde o usuário possa digitar 
vários valores numéricos e cadastre-os em uma 
lista. Caso o número já exista lá dentro, ele 
não será adicionado. No final, serão exibidos 
todos os valores únicos digitados, em ordem 
crescente. \033[m\n""")

lista = list()

while True:
    valor = int(input('Digite um valor: '))
    if valor not in lista:
        lista.append(valor)
        print("Valor adicionado com sucesso...")
    else:
        print("Valor duplicado! Não vou adicionar...")
    resposta = str(input('Você quer continuar [S/N]? ')).upper().strip()
    if resposta == "N":
        break

lista.sort()
print(f"Você digitou os valores {lista}")
