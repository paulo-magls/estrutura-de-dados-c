/*
	Exercício 3. Dada uma cadeia de caracteres, mostre-a invertida
*/

#include <stdio.h>
#include "pilha.h"

int main(void) {
	char s[513];
	Pilha p = pilha(512);
	
	printf("Cadeia? ");
	gets(s);
	
	for(int i=0; s[i]; i++)
		empilha(s[i], p);
	
	printf("Inversa = ");
	while(!vaziap(p))
		printf("%c", desempilha(p));
		
	destroip(&p);
	return 0;
}
