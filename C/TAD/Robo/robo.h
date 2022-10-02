#ifndef ROBO_H
#define ROBO_H

typedef struct robo robo;

// robo comeca no (0, 0), olhando p/ y positivo
// pode olhar nas 4 direcoes alinhadas aos eixos
robo *robo_cria(void);
void robo_free(robo *);

// anda na direcao que o robo esta olhando
void robo_frente(robo *);

// mudam a direcao que o robo esta olhando
void robo_direita(robo *);
void robo_esquerda(robo *);

// printa as coordenadas atuais e direcao p/ onde olha
void robo_print(robo *);

// retorna 'A', '<', '>', ou 'v' dependendo da direcao que o 
// robo esta olhando
char robo_direcao(robo *);

// retornam as coordenadas atuais do robo
int robo_x(robo *);
int robo_y(robo *);

#endif