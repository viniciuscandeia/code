from datetime import date

print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"92 - CADASTRO DE TRABALHADOR EN PYTHON" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que leia nome, ano de 
nascimento e carteira de trabalho e 
cadastre-o (com idade) em um dicionário. 
Se por acaso a CTPS for diferente de ZERO, 
o dicionário receberá também o ano de 
contratação e o salário. Calcule e 
acrescente, além da idade, com quantos 
anos a pessoa vai se aposentar.\033[m""")

dados = dict()

dados['Nome'] = str(input('Nome: '))
ano_n = int(input('Ano de Nascimento: '))
dados['Idade'] = date.today().year - ano_n
dados['CTPS'] = int(input('Carteira de Trabalho (0 se não tem): '))
if dados['CTPS'] != 0:
    dados['Ano de Contratação'] = int(input('Ano de Contratação: '))
    dados['Salário'] = float(input('Salário: R$ '))
    dados['Aposentadoria'] = dados['Ano de Contratação'] + 35 - ano_n

print('-=' * 20)
for k, v in dados.items():
    print(f'  - {k} tem o valor {v}')
