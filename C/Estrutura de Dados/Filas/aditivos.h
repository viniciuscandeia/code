#ifndef ADITIVOS_H
#define ADITIVOS_H

/* Uso de cores na execução do código */
#define cor_preta "\033[0;30m"
#define cor_vermelha "\033[0;31m"
#define cor_verde "\033[0;32m"
#define cor_amarela "\033[0;33m"
#define cor_azul "\033[0;34m"
#define cor_magenta "\033[0;35m"
#define cor_ciano "\033[0;36m"
#define cor_branca "\033[0;37m"

void limparBuffer(void);
void limpatela(void);
void traco(int valor);
void inicioCodigo(void);

#endif