/*
 *
 * 2) Faça dois programas em C que solicitem uma string para o usuário (com até 8 
 * caracteres). Os dois programas irão contar as ocorrências da string em um dos
 * 6 arquivos anexados à esta lista utilizando concorrência - um deles usará 
 * threads e o outro processos. Cada arquivo deverá ser processado por uma 
 * thread/processo separado e no fim o programa deverá apresentar a soma das 
 * ocorrências calculadas por cada processo antes de seu término. Comente o 
 * código com as diferença do uso de threads e processos (do ponto de vista do
 * programador). 
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>

#define QTD_ARQUIVOS 6

char str_busca[9];

long busca_string(char* str, char* arquivo) {
	sleep(2);
	long ret_val = rand() % 100;
	printf("Encontrei %ld instancias da string %s no arquivo %s.txt\n", ret_val, str, arquivo);
	return ret_val;
}

void* busca_string_th(void* p) {
	char _filename[16];
	long indice_arquivo = (long)p;
	sprintf(_filename, "%ld", indice_arquivo);
	return (void*) busca_string(str_busca, _filename);

}

int main(void) {
	int pid_original;
	pthread_t threads[QTD_ARQUIVOS];
	int ret_th[QTD_ARQUIVOS];
	int soma_ret = 0;
	char filename[16];
	time_t t;

	srand(time(&t));


	printf("Digite a string a buscar: ");
	fgets(str_busca, sizeof(str_busca), stdin);

	for (long i = 0; i < QTD_ARQUIVOS; i++) {
		pthread_create(&threads[i], NULL, busca_string_th, (void*)i);
	}

	for (int i = 0; i < QTD_ARQUIVOS; i++) {
		pthread_join(threads[i], (void*)&ret_th[i]);
		soma_ret += ret_th[i];
	}

	printf("Quantidade total encontrada: %d\n", soma_ret);

	return 0;

}
