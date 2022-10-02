import math

print("""( 1 ) Fazer simulação de COMPRA
( 2 ) Fazer simulação de RENDIMENTO""")
resposta0 = int(input('Sua opção: '))
print('=' * 45)

if resposta0 == 1:

    preco = float(input('Qual o preço do produto desejado? R$ '))
    num_p = int(input('Em quantas parcelas deseja pagar? '))

    parcelas = preco / num_p

    print(f'\n( ⦁ ) PARCELA: \033[35mR$ {parcelas :.2f}\033[m')
    print('=' * 45)
    print('Quanto você tem para realizar a compra?')
    dinheiro = float(input('R$'))

    if preco <= dinheiro:
        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
    elif preco > dinheiro:
        print('\n\033[31m{:=^40}\033[m'.format(' STATUS: COMPRA NEGADA '))

        print("""\nVocê pode optar por deixar o dinheiro \033[:4mrendendo\033[m 
    no BANCO, por meio de:
    
( 1 ) Depósitos mensais + juros
( 2 ) Depósito único + juros""")
        print('=' * 45)
        resposta1 = int(input("Sua opção: "))

        if resposta1 == 1:
            print('Opção escolhida: \033[33mDepósitos mensais + juros\033[m')
            print('=' * 45)
            dep = float(input("Qual o valor do DEPÓSITO MENSAL? \nR$ "))
            print("=" * 45)

            print("""Qual o valor da taxa de rendimento (%)?
( 1 ) Poupança (0.5%)
( 2 ) Outra""")
            resposta2 = int(input('Sua opção: '))

            if resposta2 == 1:
                print('Opção escolhida: \033[33mPoupança (0.5%)\033[m')
                print('=' * 45)

                print("""Quantos depósitos serão feitos?
( 1 ) O suficiente para alcançar o preço - sem juros
( 2 ) O suficiente para alcançar o preço - com juros
( 3 ) Quantidade escolhida pelo usuário + juros""")
                resposta3 = int(input('Sua opção: '))

                if resposta3 == 1:
                    print('Opção escolhida: \033[33mO suficiente para alcançar o preço - sem juros\033[m')
                    print('=' * 45)

                    din_n = preco - dinheiro
                    num_d = din_n / dep
                    num_D = math.ceil(num_d)

                    if num_D <= 1:
                        print(f'Apenas 1 depóstivo de \033[36mR$ {dep :.2f}\033[m será necessário.')
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                    else:
                        print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                        valor_a = dep * num_D
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')

                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                elif resposta3 == 2:
                    print('Opção escolhida: \033[33mO suficiente para alcançar o preço - com juros\033[m')
                    print('=' * 45)

                    if dinheiro == 0:
                        a = (preco * 0.005) / dep
                        b = a + 1
                        c = math.log(b, 10) / math.log(1.005, 10)

                        num_d = c + 1
                        num_D = math.trunc(num_d)
                        valor_f: float = dep * ((1.005 ** num_D - 1) / 0.005)

                    else:
                        a = dep / 0.005
                        b = preco + a
                        c = a + dinheiro
                        d = b / c
                        e = math.log(d, 10) / math.log(1.005, 10)
                        num_D = math.trunc(e) + 1

                        valor_f: float = dep * ((1.005 ** num_D - 1) / 0.005) + dinheiro * (1.005 ** num_D)

                    if valor_f >= preco:
                        if num_D <= 1:
                            print(f'Apenas 1 depósito de \033[36m{dep :.2f}\033[m será necessário')
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                            print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{num_D} meses\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_f :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                        else:
                            print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                            valor_a = dep * num_D
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_f :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                    else:
                        valor_F: float = dep * ((1.005 ** (num_D + 1) - 1) / 0.005)
                        if num_D <= 1:
                            print(f'Apenas 1 depósito de \033[36m{dep :.2f}\033[m será necessário')
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                        else:
                            print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                            valor_a = dep * num_D
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                elif resposta3 == 3:
                    print('Opção escolhida: \033[33mQuantidade escolhida pelo usuário + juros\033[m')
                    print('=' * 45)

                    num_d = int(input('Quantidade de depósitos: '))

                    valor_f: float = dep * ((1.005 ** num_d - 1) / 0.005) + dinheiro * (1.005 ** num_d)
                    x = preco / valor_f
                    t = math.log(x, 10) / math.log(1.005, 10)
                    T = math.trunc(t) + 1
                    valor_F = valor_f * (1.005 ** T)
                    dif_t = T - num_d

                    if num_d == 1:
                        print(f'Um único depósito de R$ \033[36m{dep :.2f}\033[m será realizado.')
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                        print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                        if dif_t > 0:
                            if dif_t > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO:  \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')

                        elif dif_t < 0:
                            if dif_t < -1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                    elif num_d > 1:
                        print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_d}\033[m')
                        valor_a = dep * num_d
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                        print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                        if dif_t > 0:
                            if dif_t > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO:  \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')

                        elif dif_t < 0:
                            if dif_t < -1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                else:
                    print('\033[31mOPÇÃO INVÁLIDA\033[m')

            elif resposta2 == 2:
                print('Opção escolhida: \033[33mOutra\033[m')
                taxa = float(input('Qual a taxa (%)? '))
                print('=' * 45)

                taxa_p = taxa / 100

                print("""Quantos depósitos serão feitos?
( 1 ) O suficiente para alcançar o preço - sem juros
( 2 ) O suficiente para alcançar o preço - com juros
( 3 ) Quantidade escolhida pelo usuário + juros""")
                resposta3 = int(input('Sua opção: '))

                if resposta3 == 1:
                    print('Opção escolhida: \033[33mO suficiente para alcançar o preço - sem juros\033[m')
                    print('=' * 45)

                    din_n = preco - dinheiro
                    num_d = din_n / dep
                    num_D = math.ceil(num_d)

                    if num_D <= 1:
                        print(f'Apenas 1 depóstivo de \033[36mR$ {dep :.2f}\033[m será necessário.')
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                    else:
                        print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                        valor_a = dep * num_D
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')

                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                elif resposta3 == 2:
                    print('Opção escolhida: \033[33mO suficiente para alcançar o preço - com juros\033[m')
                    print('=' * 45)

                    if dinheiro == 0:
                        a = (preco * taxa_p) / dep
                        b = a + 1
                        d = 1 + taxa_p
                        c = math.log(b, 10) / math.log(d, 10)

                        num_d = c + 1
                        num_D = math.trunc(num_d)
                        valor_f: float = dep * ((d ** num_D - 1) / taxa_p)

                    else:
                        a = dep / taxa_p
                        b = preco + a
                        c = a + dinheiro
                        d = b / c
                        f = 1 + taxa_p
                        e = math.log(d, 10) / math.log(f, 10)
                        num_D = math.trunc(e) + 1

                        valor_f: float = dep * ((f ** num_D - 1) / taxa_p) + dinheiro * (f ** num_D)

                    if valor_f >= preco:
                        if num_D <= 1:
                            print(f'Apenas 1 depósito de \033[36m{dep :.2f}\033[m será necessário')
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_f :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                        else:
                            print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                            valor_a = dep * num_D
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_f :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                    else:
                        valor_F: float = dep * (((1 + taxa_p) ** (num_D + 1) - 1) / taxa_p)
                        if num_D <= 1:
                            print(f'Apenas 1 depósito de \033[36m{dep :.2f}\033[m será necessário')
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))
                        else:
                            print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_D}\033[m')
                            valor_a = dep * num_D
                            print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                            print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                            anos = num_D / 12
                            if anos == 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                            elif anos > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                elif resposta3 == 3:
                    print('Opção escolhida: \033[33mQuantidade escolhida pelo usuário + juros\033[m')
                    print('=' * 45)

                    num_d = int(input('Quantidade de depósitos: '))

                    valor_f: float = dep * (((1 + taxa_p) ** num_d - 1) / taxa_p) + dinheiro * ((1 + taxa_p) ** num_d)
                    x = preco / valor_f
                    c = 1 + taxa_p
                    t = math.log(x, 10) / math.log(c, 10)
                    T = math.trunc(t) + 1
                    valor_F = valor_f * (c ** T)
                    dif_t = T - num_d

                    if num_d == 1:
                        print(f'Um único depósito de R$ \033[36m{dep :.2f}\033[m será realizado.')
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {dep :.2f}\033[m')
                        print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                        if dif_t > 0:
                            if dif_t > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO:  \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')

                        elif dif_t < 0:
                            if dif_t < -1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                                anos = T / 12
                                if anos == 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                                elif anos > 1:
                                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f}\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                    elif num_d > 1:
                        print(f'( ⦁ ) NÚMERO DE DEPÓSITOS: \033[36m{num_d}\033[m')
                        valor_a = dep * num_d
                        print(f'( ⦁ ) TOTAL DEPOSITADO: \033[35mR$ {valor_a :.2f}\033[m')
                        print(f'( ⦁ ) MONTANTE FINAL: \033[35mR$ {valor_F :.2f}\033[m')
                        if dif_t > 0:
                            if dif_t > 1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO:  \033[35m{T} meses\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')

                        elif dif_t < 0:
                            if dif_t < -1:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                            else:
                                print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 mês\033[m')
                        print('\n\033[32m{:=^40}\033[m'.format(' STATUS: COMPRA PERMITIDA '))

                else:
                    print('\033[31mOPÇÃO INVÁLIDA\033[m')

            else:
                print('\033[31mOPÇÃO INVÁLIDA\033[m')

        elif resposta1 == 2:
            print('Opção escolhida: \033[33mDepósito único + juros\033[m')
            print('=' * 45)

            print("""Qual o valor da taxa de rendimento (%)?
( 1 ) Poupança (0.5%)
( 2 ) Outra""")
            resposta2 = int(input('Sua opção: '))

            if resposta2 == 1:
                print('Opção escolhida: \033[33mPoupança (0.5%)\033[m')
                print('=' * 45)

                a = preco / dinheiro
                b = math.log(a, 10)
                c = math.log(1.005, 10)
                t = b / c
                T = math.trunc(t) + 1
                valor_f = dinheiro * (1.005 ** T)
                print(f'( ⦁ ) MONTANTE FINAL: \033[35m{valor_f :.2f}\033[m')
                if T == 1:
                    print('Apenas \033[35m1 mês\033[m de espera será necessário.')
                elif T > 1:
                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                    anos = T / 12
                    if anos == 1:
                        print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                    elif anos > 1:
                        print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f} anos\033[m')

            elif resposta2 == 2:
                print('Opção escolhida: \033[33mOutra\033[m')
                taxa = float(input('Qual a taxa (%)? '))
                print('=' * 45)

                taxa_p = taxa / 100
                a = preco / dinheiro
                b = math.log(a, 10)
                d = 1 + taxa_p
                c = math.log(d, 10)
                t = b / c
                T = math.trunc(t) + 1
                valor_f = dinheiro * (d ** T)
                print(f'( ⦁ ) MONTANTE FINAL: \033[35m{valor_f :.2f}\033[m')
                if T == 1:
                    print('Apenas \033[35m1 mês\033[m de espera será necessário.')
                elif T > 1:
                    print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{T} meses\033[m')
                    anos = T / 12
                    if anos == 1:
                        print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m1 ano\033[m')
                    elif anos > 1:
                        print(f'( ⦁ ) TEMPO NECESSÁRIO: \033[35m{anos :.1f} anos\033[m')

            else:
                print('\033[31mOPÇÃO INVÁLIDA\033[m')

        else:
            print('\033[31mOPÇÃO INVÁLIDA\033[m')

elif resposta0 == 2:

    print("""( 1 ) Juros Compostos SEM Aplicação Mensal
( 2 ) Juros Compostos COM Aplicação Mensal""")
    resposta1 = int(input('Sua opção: '))
    print('=' * 45)

    if resposta1 == 1:
        valor = float(input('Quanto você tem? \nR$ '))
        print('=' * 45)

        print("""( 1 ) Taxa da Poupança (0.5%)
( 2 ) Outra taxa""")
        resposta2 = int(input('Sua opção: '))
        print('=' * 45)

        if resposta2 == 1:
            taxa_p = 0.005
        elif resposta2 == 2:
            taxa = float(input('Qual a taxa (%)? '))
            taxa_p = taxa / 100

        tempo = int(input('Quanto tempo (meses)? '))
        print('=' * 45)

        valor_f = valor * ((1 + taxa_p) ** tempo)

        print(f'MONTANTE FINAL: \033[34m{valor_f :.2f}\033[m')

    elif resposta1 == 2:

        valor_i = float(input('Qual o valor inicial? \nR$ '))
        print('=' * 45)
        valor_a = float(input('Qual o valor do depósito mensal? \nR$ '))
        print('=' * 45)

        print("""( 1 ) Taxa da Poupança (0.5%)
( 2 ) Outra taxa""")
        resposta2 = int(input('Sua opção: '))
        print('=' * 45)

        if resposta2 == 1:
            taxa_p = 0.005
        elif resposta2 == 2:
            taxa = float(input('Qual a taxa (%)? '))
            taxa_p = taxa / 100
            print('=' * 45)
        else:
            print('\033[31mOPÇÃO INVÁLIDA\033[m')

        num_d = int(input('Quantos depósitos haverá? '))

        print("""( 1 ) Parar após o término dos dépositos
( 2 ) Continuar após o término dos depósitos""")
        resposta3 = int(input('Sua opção: '))
        print('=' * 45)

        if resposta3 == 1:
            valor_f: float = valor_a * (((1 + taxa_p) ** num_d - 1) / taxa_p) + valor_i * ((1 + taxa_p) ** num_d)
            print(f'MONTANTE FINAL: \033[34m{valor_f :.2f}\033[m')
        elif resposta3 == 2:
            tem_r = int(input('Quanto tempo ficará rendendo? '))
            valor_f: float = valor_a * (((1 + taxa_p) ** num_d - 1) / taxa_p) + valor_i * ((1 + taxa_p) ** num_d)

            valor_F = valor_f * ((1 + taxa_p) ** tem_r)

            print(f'MONTANTE FINAL: \033[34m{valor_F :.2f}\033[m')
        else:
            print('\033[31mOPÇÃO INVÁLIDA\033[m')

    else:
        print('\033[31mOPÇÃO INVÁLIDA\033[m')

else:
    print('\033[31mOPÇÃO INVÁLIDA\033[m')
