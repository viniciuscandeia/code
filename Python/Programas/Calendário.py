adicao: int
dias: int
adicao = dias = 0

mes = str(input('Qual o mês? ')).lower().strip()
dia_s_l = str(input('Qual o dia da semana começa o mês? ')).lower().strip()
ano = int(input('Qual o ano? '))

semana = ('domingo', 'segunda', 'terça',
          'quarta', 'quinta', 'sexta', 'sábado')

mes_t = ('janeiro', 31, 'fevereiro', 28,
         'março', 31, 'abril', 30,
         'maio', 31, 'junho', 30,
         'julho', 31, 'agosto', 31,
         'setembro', 30, 'outubro', 31,
         'novembro', 30, 'dezembro', 31)

espaco: int = semana.index(dia_s_l)

if ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0:
    adicao = 1

if mes in mes_t:
    a = mes_t.index(mes) + 1
    if adicao == 1 and mes == "fevereiro":
        dias = mes_t[a] + 1
    else:
        dias = mes_t[a]

print('=' * 42)
print('DOM | SEG | TER | QUA | QUI | SEX | SÁB |')
print(f'{"    | " * espaco}', end='')

cont: int = espaco + 1

for c in range(1, dias + 1):
    cont += 1
    if cont <= 7:
        print(f' {c :^3}', end='| ')
    else:
        print(f' {c :^3}', end='| ')
        cont = 1
        print(f'\n{"-" * 42}')

print('\n')
