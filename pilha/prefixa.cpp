/*
	Exercício 5. Crie a função prefixa(e) que devolve a forma prefixa
	da expressão aritmética completamente parentesiada e.
*/

#include <stdio.h>
#include <ctype.h>
// função isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// função strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"


// função que recebe uma expressão infixa e converte para prefixa
char *prefixa(char *e){
	static char s[513];
	Pilha p = pilha(512);
	int j = 0;
	
	for(int i = strlen(e)-1; i >= 0; i--)
		if(isdigit(e[i])) s[j++] = e[i];
		else if(strchr("+-*/", e[i])) empilha(e[i], p);
		else if(e[i] == '(') s[j++] = desempilha(p);
	
	s[j] = '\0';
	destroip(&p);
	return _strrev(s);
}

int main(void) {
	char e[256];
	
	printf("Infixa? "); 
	gets(e); // Exemplo de entrada: ((2*3)+(8/4))
	
	printf("Prefixa = %s\n", prefixa(e)); // Saída: +*23/84
	return 0;
}
