def fatorial(num, show=False):
    """
    -> Calcula o fatorial de um número
    :param num: o número a ser calculado
    :param show: se vai mostrar ou não, o cálculo
    :return: retorna o fatorial do número
    """
    fat = 1
    for c in range(num, 0, -1):
        if show:
            print(f'{c}', end='')
            if c > 1:
                print(f' x ', end='')
            else:
                print(f' = ', end='')
        fat *= c
    return fat


print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"102 - FUNÇÃO PARA FATORIAL" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que tenha uma função 
fatorial() que receba dois parâmetros: o 
primeiro que indique o número a calcular e 
outro chamado show, que será um valor lógico 
(opcional) indicando se será mostrado ou não 
na tela o processo de cálculo do fatorial.\033[m\n""")


num = int(input('Número: '))
print(fatorial(num, show=True))
