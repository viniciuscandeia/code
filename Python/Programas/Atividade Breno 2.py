print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{" 2 - PA e PG" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m\n')

print("""[ A ] Progressão Aritmética
[ G ] Progressão Geométrica""")
resposta = str(input('Sua opção: ')).upper().strip()

a1 = int(input('\nPrimeiro termo: '))
if resposta == "A":
    r = int(input('Razão: '))
if resposta == "G":
    r = float(input('Razão: '))
n = int(input('Número de termos: '))

s = cont = 0
valor = a1

if resposta == "A":
    print('\nOpção escolhida: \033[33mProgressão Aritmética\033[m\n')
    for c in range(a1, a1 + (n - 1) * r + 1, r):
        print(c, end='')
        if r > 0:
            print(" -> " if c < a1 + (n - 1) * r else "", end='')
        if r < 0:
            print(" -> " if c > a1 + (n - 1) * r else "", end='')
        s += c
    print(' || FIM')
    print(f'\nA soma dos termos foi \033[35m{s}\033[m.')

if resposta == "G":
    print('Opção escolhida: \033[33mProgressão Geométrica\033[m\n')
    while cont < n:
        cont += 1
        if cont == 1:
            valor = a1
        if cont > 1:
            valor = a1 * (r ** (cont-1))
        print(f'{valor :.0f}', end='')
        if r > 1:
            print(' -> ' if valor < a1 * (r ** (n-1)) else "", end='')
        if r < 1:
            print(' -> ' if valor > a1 * (r ** (n - 1)) else "", end='')
        s += valor
    print(' || FIM')
    print(f'\nA soma dos termos foi \033[35m{s}\033[m.')
