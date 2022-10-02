#ifndef ADITIVOS_H
#define ADITIVOS_H

/* Uso de cores na execução do código */
#define corPreta "\033[0;30m"
#define corVermelha "\033[0;31m"
#define corVerde "\033[0;32m"
#define corAmarela "\033[0;33m"
#define corAzul "\033[0;34m"
#define corMagenta "\033[0;35m"
#define corCiano "\033[0;36m"
#define corBranca "\033[0;37m"

void limparBuffer(void);
void limpatela(void);
void traco(int valor);
void inicioCodigo(void);
void sleep_us(unsigned long microseconds);

#endif