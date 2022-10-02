#include <stdio.h>

#include "robo.h"

#define cor_amarela "\033[33m"
#define cor_branca "\033[37m"

void limpatela(void);
void tela(robo *);
char menu(void);

int main(void) {
    robo *r = robo_cria();
    char cmd;

    do {
        limpatela();
        tela(r);
        cmd = menu();
        switch (cmd) {
            case 'f':
                robo_frente(r);
                break;
            case 'e':
                robo_esquerda(r);
                break;
            case 'd':
                robo_direita(r);
                break;
        }
    } while (cmd != 's');

    robo_free(r);
    return 0;
}

void limpatela(void) {
    printf("\e[1;1H\e[2J");
}

void tela(robo *r) {
    int x, y;
    int rx, ry;

    rx = robo_x(r);
    ry = robo_y(r);
    for (y = 5; y >= -5; y--) {
        for (x = -5; x <= 5; x++) {
            if (x == rx && y == ry) {
                printf(cor_amarela "%c " cor_branca, robo_direcao(r));
            } else {
                printf(". ");
            }
        }
        puts("");
    }
    puts("");
    robo_print(r);
    puts("");
}

char menu(void) {
    static char *line = NULL;
    static size_t len = 0;
    puts("selecione:");
    puts(" f: andar p/ frente");
    puts(" e: virar p/ esquerda");
    puts(" d: virar p/ direita");
    puts(" s: sair");

    getline(&line, &len, stdin);
    return line[0];
}