/*
	Nome: Vinicius Candeia Pereira Vieira
	Matrícula: 20200009783
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>

#include <pthread.h>
#include "aditivos.h"

#define QTD_THREADS 5 // serão manipuladas por 5 threads cada

/*
(Questão 1 - 5,0 pontos) Faça um programa em C/C++ que controle o acesso de
duas filas de threads a duas seções críticas diferentes. O programa deverá
possuir duas variáveis globais (x e y) de tipo float, iniciadas com zero, que
serão manipuladas por 5 threads cada (num total de 10 threads). As threads de
indices pares deverão executar uma função que manipule o valor da variável x,
incrementando-a com um valor aleatório entre 1 e 5, depois dormindo 250ms; as
threads com indice ímpar executarão uma função que manipula o valor da variável
y, incrementando-a com valor com aleatório entre 2 e 25 e depois dormir 300ms.

Implemente uma solução para o problema da seção crítica que atenda as 4
propriedades de uma solução ideal, que use espera ocupada e que garanta que
todas as threads incrementem as duas variáveis globais dentro de um ciclo de
iterações. O programa deverá ser finalizado quando a soma dos valores de x e y
for  maior que 100. Comente o código explicando como foi feito o controle de
acesso às duas seções críticas, explicando qual a função atômica utilizada.
*/

// O programa deverá possuir duas variáveis globais (x e y) de tipo float, iniciadas com zero
float x = 0;
float y = 0;
int lock = 0;

/*
	As threads de indices pares deverão executar uma função que manipule o valor da variável x,
	incrementando-a com um valor aleatório entre 1 e 5, depois dormindo 250ms;
*/

void *funcaoPar(void *valor)
{ // serão manipuladas por 5 threads cada
	long indice = (long)valor;
	while (true)
	{
		// | Espera ocupada
		while (__sync_test_and_set(&lock, 1))
			;

		// * Seção crítica
		x = (1 + rand() % 4);
		usleep(250);
		wprintf(corCiano L"PAR " corBranca ": snc %ld vg: %f\n", indice, x);

		// | Destrava
		lock = 0;
	}
}

/*
	As threads com indice ímpar executarão uma função que manipula o valor da variável
	y, incrementando-a com valor com aleatório entre 2 e 25 e depois dormir 300ms.
*/
void *funcaoImpar(void *valor)
{ // serão manipuladas por 5 threads cada
	long indice = (long)valor;
	while (true)
	{
		// | Espera ocupada
		while (__sync_test_and_set(&lock, 1))
			;

		// * Seção crítica
		y = (2 + rand() % 23);
		wprintf(corAmarela L"IMPAR " corBranca ": snc %ld vg: %f\n", indice, y);
		usleep(300);

		// | Destrava
		lock = 0;
	}
}

int main()
{
	pthread_t threads[QTD_THREADS];
	float soma = 0;

	soma = x + y;

	srand(time(NULL));

	for (long i = 0; i < QTD_THREADS; i++)
	{
		if (i % 2 == 0)
			pthread_create(&threads[i], NULL, funcaoPar, (void *)i);
		else
			pthread_create(&threads[i], NULL, funcaoImpar, (void *)i);
	}

	// Thread principal irá esperar até essa condição ser válida.
	while (soma <= 100)
		;

	return 0;
}
