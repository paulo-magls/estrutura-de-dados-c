#include <stdio.h>
#include <ctype.h>
// fun��o isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// fun��o strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"

// fun��o que recebe uma express�o posfixa e devolve o resultado
int valor(char *e) {
	Pilha p = pilha(256);
	
	for(int i=0; e[i]; i++){
		if(isdigit(e[i]))
			// e[i]-'0' -> converte o caractere para digito
			empilha(e[i]-'0', p);
		else if(strchr("+-*/", e[i])){
			int y = desempilha(p);
			int x = desempilha(p);
			
			switch(e[i]){
				case '+': empilha(x+y, p); break;
				case '-': empilha(x-y, p); break;
				case '*': empilha(x*y, p); break;
				case '/': empilha(x/y, p); break;
			}
		}
	}
	
	int r = topo(p); // Tamb�m pode usar o desempilha(p)
	destroip(&p);
	return r;
}

int main(void) {
	char e[256];
	
	printf("Posfixa? ");
	gets(e); // Exemplo de entrada: 23*84/+
	
	printf("Valor = %d", valor(e)); // Sa�da: 8
	return 0;
}
