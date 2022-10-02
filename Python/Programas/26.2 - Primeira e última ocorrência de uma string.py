print('\033[35m{:=^46}\033[m'.format('='))
print('\033[35m{:^46}\033[m'.format(' PRIMEIRA E ÚLTIMA OCORRÊNCIA DE UMA STRING '))
print("""\033[33mFaça um programa que leia uma frase
pelo teclado e mostre:
- Quantas vezes aparece a letra "A".
- Em que posição ela aparece a primeira vez.
- Em que posição aparece a última vez.\033[m""")
print('\033[35m{:=^46}\033[m'.format('='))

frase = str(input('Digite uma frase: ')).strip().upper()
print(f'Em sua frase aparece \033[31m{frase.count("A")} letras\033[m "A".')
print(f'A primeira letra "A" aparece na posição \033[34m{frase.find("A") + 1}\033[m.')
print(f'A última letra "A aparece na posição \033[32m{frase.rfind("A") + 1}\033[m.')