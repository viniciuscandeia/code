print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"83 - VALIDANDO EXPRESSÕES MATEMÁTICAS":^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa onde o usuário digite uma 
expressão qualquer que use parênteses. Seu 
aplicativo deverá analisar se a expressão 
passada está com os parênteses abertos e 
fechados na ordem correta.\n\033[m""")

pilha = []

expressao = str(input('Digite a expressão: '))

for simb in expressao:
    if simb == "(":
        pilha.append('(')
    elif simb == ")":
        if len(pilha) > 0:
            pilha.pop()
        else:
            pilha.append(')')
            break

if len(pilha) == 0:
    print('Sua expressão é válida.')
else:
    print('Sua expressão não é válida.')
