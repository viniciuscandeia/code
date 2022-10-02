/*
 1) Faça um programa em C/C++ em que você compare o tempo de criação de 30 
 threads e 30 processos, onde as threads e processos criadas apenas executem
 uma função que exiba uma mensagem ("Nova thread" ou "Novo processo") e as faça
 dormir por 2s. Use alguma função de medição de tempo* para tal e escreva suas
 impressões sobre o resultado, respondendo qual das opções demandou menos tempo
 de execução para ser realizada e faça a relação disso com consumo de 
 processamento e memória. Para finalizar, faça uma clara distinção (em 
 comentários no código) das diferenças principais entre threads e processos.
  Ao término do programa, nenhum processo deverá permanecer em execução.

  * Funções sugeridas para uso no processo de medição de tempo de execução são 
  * listadas abaixo. 
  * - Em C/C++: time(),  clock(), clock_gettime() (biblioteca time.h), 
  *     gettimeofday() (biblioteca sys/time.h);
  *     - Em C++: método chrono::high_resolution_clock (biblioteca chrono). 
  *     - Sugestão de referência: https://tinyurl.com/medirtempoemc
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define QTD_THREADS 30
#define QTD_PROCESSOS 30
#define SLEEP_TIME 2

void* funcao_thread(void* p) {
	sleep(SLEEP_TIME);
}

int main(void) {
	clock_t t_p1, t_p2, t_p;
	clock_t t_t1, t_t2, t_t;

	pthread_t threads[QTD_THREADS];
	int pid_original;
	int new_p;

	pid_original = getpid();

	//inicio medir tempo processos
	t_p1 = clock();

	for (int i = 0; i < QTD_PROCESSOS; i++) { 
		if (pid_original == getpid()) {
			new_p = fork();
		}
	}

	if (pid_original != getpid()) { 
		sleep(2);
		exit(0);
	} 

	if (pid_original == getpid()) { 
		t_p2 = clock();
		t_p = t_p2 - t_p1;
		printf("Instanciar 30 processos\n");
		printf("Tempo de execucao: %lf ms\n", ((double)t_p)/((CLOCKS_PER_SEC/1000)));
		//fim medicao tempo processos (so no processo original)

		//inicio medir tempo threads
		t_t1 = clock();

		for (int i = 0; i < QTD_THREADS; i++) {
			pthread_create(&threads[i], NULL, funcao_thread, NULL);
		}

		t_t2 = clock();

		t_t = t_t2 - t_t1;

		printf("Instanciar 30 threads\n");
		printf("Tempo de execucao: %lf ms\n", ((double)t_t)/((CLOCKS_PER_SEC/1000)));
		//fim medir tempo threads

	}

	return 0;
}

