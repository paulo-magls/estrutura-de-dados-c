/*
	Exercício 2. Crie um programa com uma pilha e uma fila
	para verificar se uma frase é palíndroma.
*/

#include <stdio.h>
#include <ctype.h>
#include "../pilha/pilha.h"
#include "fila.h"

int main(void) {
	char  s[513];
	Pilha p = pilha(512);
	Fila  f = fila(512);
	
	printf("Frase? ");
	gets(s);
	
	for(int i=0; s[i]; i++)
		if(isalpha(s[i])){
			empilha(s[i], p);
			enfileira(s[i], f);
		}
	
	while(!vaziaf(f) && desenfileira(f) == desempilha(p));
	
	if(vaziaf(f)) puts("Palindroma");
	else puts("Nao palindroma");
	
	destroip(&p);
	destroif(&f);
	return 0;
}
