print('\033[35m{:=^40}\033[m'.format('='))
print('\033[35m{:^40}\033[m'.format(' MAIOR E MENOS VALORES '))
print('\033[35m{:=^40}\033[m'.format('='))
print('''\033[33mFaça um programa que leia três 
números qual é o maior e qual é o menor.\033[m''')

n1 = float(input('\nDigite o primeiro número: '))
n2 = float(input('Digite o segundo número: '))
n3 = float(input('Digite o terceiro número: '))

if n1 >= n2 and n1 > n3:
    if n2 > n3:
        print(f'O MAIOR valor é {n1}.')
        print(f'O MENOR valor é {n3}.')
    else:
        if n3 > n2:
            print(f'O MAIOR valor é {n1}.')
            print(f'O MENOR valor é {n2}.')
        else:
            print(f'O MAIOR valor é {n1}.')
            print(f'O MENOR valor é {n3}')
else:
    if n2 >= n1 and n2 > n3:
        if n1 > n3:
            print(f'O MAIOR valor é {n2}.')
            print(f'O MENOR valor é {n3}.')
        else:
            if n3 > n1:
                print(f'O MAIOR valor é {n2}.')
                print(f'O MENOR valor é {n1}.')
            else:
                print(f'O MAIOR valor é {n2}.')
                print(f'O MENOR valor é {n1}.')
    else:
        if n3 >= n1 and n3 > n2:
            if n1 > n2:
                print(f'O MAIOR valor é {n3}.')
                print(f'O MENOR valor é {n2}.')
            else:
                if n2 > n1:
                    print(f'O MAIOR valor é {n3}.')
                    print(f'O MENOR valor é {n1}.')
                else:
                    print(f'O MAIOR valor é {n3}.')
                    print(f'O MENOR valor é {n1}')
        else:
            if n3 > n1 and n3 >= n2:
                if n1 > n2:
                    print(f'O MAIOR valor é {n3}.')
                    print(f'O MENOR valor é {n2}.')
                else:
                    if n2 > n1:
                        print(f'O MAIOR valor é {n3}.')
                        print(f'O MENOR valor é {n1}.')
            else:
                if n1 == n2 == n3:
                    print('Todos os valores são iguais.')
