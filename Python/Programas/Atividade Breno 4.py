rp: int
num = rp = rn = 0

a1 = int(input('Digite um número: '))
a2 = int(input('Digite um segundo número: '))
rp = a2 - a1

while num != -1:
    num = int(input('Digite um novo número: '))
    if num == -1:
        break
    rn = num - a2
    if rn == rp:
        print('\033[36mPA\033[m')
        print(f'{"~" * 30}')
        a2 = num
    elif rn != rp:
        print('\033[31mNÃO PA\033[m')
        break

if rp == rn:
    print(f'{"~" * 30}')
    print(f'\033[34mRazão: {rp}\033[m')
