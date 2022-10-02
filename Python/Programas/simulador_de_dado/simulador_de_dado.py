import random

while (True):

    resposta = str(input("Voce gostaria de jogar o dado? ")).upper().strip()

    try:

        if (resposta == "NAO" or resposta == "N"):
            break
        if (resposta == "SIM" or resposta == "S"):
            continue

    except:

        if (resposta == "SIM" or resposta == "S" or resposta == "NAO" or resposta == "N"):
            
            while(True):

                print("Resposta invalida! Tente novamente.")
                resposta = str(input("Voce gostaria de jogar o dado?")).upper().strip()
                if (resposta == "SIM" or resposta == "S" or resposta == "NAO" or resposta == "N"):
                    break

    finally:

        print(resposta)
