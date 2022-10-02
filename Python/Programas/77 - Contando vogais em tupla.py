print(f'\033[35m{"=" * 45}\033[m')
print(f'\033[35m{"77 - CONTANDO VOGAIS EM TUPLA" :^45}\033[m')
print(f'\033[35m{"=" * 45}\033[m')
print("""\033[33mCrie um programa que tenha uma tupla com 
várias palavras (não usar acentos). Depois 
disso, você deve mostrar, para cada palavra, 
quais são as suas vogais.\033[m""")

tupla = ("Aprender", "Programar", "Linguagem", "Python", "Curso",
         "Grátis", "Estudar", "Praticar", "Trabalhar", "Mercado",
         "Programador", "Futuro")

for palavra in tupla:
    print(f'\nNa palavra {palavra.upper()} tem asn vogais: ', end='')
    for letra in palavra:
        if letra.lower() in 'aeiouá':
            print(letra, end=' ')


