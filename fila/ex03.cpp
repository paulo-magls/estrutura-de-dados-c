/*
	Exercício 3. O programa a seguir simula o compartilhamento
	de CPU entre vários processos. Qual a saída?
*/

#include <stdio.h>
#include "fila.h"
#define TIMESLICE 3

int main(void) {
	Fila f = fila(5);
	
	// primeiro dígito = número do processo
	// segundo dígito = tempo necessário para concluir
	enfileira(17, f);
	enfileira(25, f);
	enfileira(39, f);
	enfileira(46, f);
	
	while(!vaziaf(f)){
		int x = desenfileira(f);
		int p = x / 10; // pega o primeiro dígito
		int t = x % 10; // pega o segundo dígito
		
		if(t > TIMESLICE)
			enfileira(10*p+(t-TIMESLICE), f);
		else
			printf("Processo %d concluido.\n", p);
	}
	
	destroif(&f);
	return 0;
}
