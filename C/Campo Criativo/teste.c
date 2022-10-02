#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include "aditivos.h"

int main()
{

    inicioCodigo();

    double x = 0;
    double y = 0;
    double z = 0;
    double t = 0;

    double iniX = 0;
    double iniY = 0;
    double iniZ = 0;
    double iniT = 0;

    double valorCorreto = 1 / 10;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 1000; k++)
            {
                for (int l = 0; l < 1000; l++)
                {

                    iniT += 0.1;

                    t = iniT;

                    double valorX = 4 * x + 1 * y - 2 * z - 3 * t;
                    double valorY = 2 * x + 1 * y + 1 * z - 4 * t;
                    double valorZ = 6 * x - 9 * z + 9 * t;

                    if (valorX == 0 && valorY == 0 && valorZ == 0)
                    {
                        wprintf(cor_amarela L" %lf %lf %lf %lf\n" cor_branca, x, y, z, t);
                    }
                }

                iniZ += 0.1;
                z = iniZ;
            }

            iniY += 0.1;
            y = iniY;

            wprintf(L"y : %.15lf\n", y);
            sleep(1);
        }

        iniX += 0.1;
        t = iniX;
    }

    traco(2);
    return 0;
}