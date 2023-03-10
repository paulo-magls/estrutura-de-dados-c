/*
	Exerc�cio 5. Crie a fun��o prefixa(e) que devolve a forma prefixa
	da express�o aritm�tica completamente parentesiada e.
*/

#include <stdio.h>
#include <ctype.h>
// fun��o isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// fun��o strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"


// fun��o que recebe uma express�o infixa e converte para prefixa
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
	
	printf("Prefixa = %s\n", prefixa(e)); // Sa�da: +*23/84
	return 0;
}
