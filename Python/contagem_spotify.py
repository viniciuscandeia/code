from time import sleep

mes_total = open('ano_todo.txt', 'r', encoding="utf8")
mes_segundos = open('ano_todo_segundos.txt', 'w', encoding="utf8")

cont = 0

sleep(3)

for linha in mes_total:

    if (cont % 6 == 0):
        mes_segundos.write(linha)

    cont += 1

mes_total.close()
mes_segundos.close()
