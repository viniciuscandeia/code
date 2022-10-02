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

int busca_string(char* str, char* arquivo) {
	sleep(2);
	int ret_val = rand() % 100;
	printf("Encontrei %d instancias da string %s no arquivo %s.txt\n", ret_val, str, arquivo);
	return ret_val;
}

int main(void) {
	int pid_original;
	int pid_clones[QTD_ARQUIVOS];
	int ret_clones[QTD_ARQUIVOS];
	char str_busca[9];
	char filename[16];
	time_t t;

	srand(time(&t));


	printf("Digite a string a buscar: ");
	fgets(str_busca, sizeof(str_busca), stdin);

	pid_original = getpid();

	for (int i = 0; i < QTD_ARQUIVOS; i++) { 
		
		if (pid_original == getpid()) {
			pid_clones[i] = fork();
		}
		
	};

	if (pid_original != getpid()) { 
		sprintf(filename, "%d", getpid()-pid_original);
		printf("Processo buscando no arquivo %d.txt\n", getpid()-pid_original);
		return busca_string(str_busca, filename);
	}

	if (pid_original == getpid()) {
		int soma_ocorrencias = 0;
		for (int i = 0; i < QTD_ARQUIVOS; i++) {
			waitpid(pid_clones[i], &ret_clones[i], 0);
			soma_ocorrencias += WEXITSTATUS(ret_clones[i]);
		}

		printf("Quantidade de ocorrencias total para %s: %d\n", str_busca, soma_ocorrencias);

	}


	return 0;

}
