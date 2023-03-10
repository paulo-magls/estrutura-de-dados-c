#include <stdio.h>
#include <ctype.h>
// função isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// função strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"


// função que recebe uma expressão infixa e converte para posfixa
char *posfixa(char *e) {
	static char s[256];
	int j = 0;
	Pilha p = pilha(256);
	
	for(int i=0; e[i]; i++)
		if(isdigit(e[i])) s[j++] = e[i];
		else if(strchr("+-*/", e[i])) empilha(e[i], p);
		else if(e[i] == ')') s[j++] = desempilha(p);
	
	s[j] = '\0';
	destroip(&p);
	return s;
}

int main(void) {
	char e[256];
	
	printf("Infixa? "); 
	gets(e); // Exemplo de entrada: ((2*3)+(8/4))
	
	printf("Posfixa = %s\n", posfixa(e)); // Saída: 23*84/+
	return 0;
}
