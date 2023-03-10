#include <stdio.h>
#include <ctype.h>
// função isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// função strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"

// função que recebe uma expressão posfixa e devolve o resultado
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
	
	int r = topo(p); // Também pode usar o desempilha(p)
	destroip(&p);
	return r;
}

int main(void) {
	char e[256];
	
	printf("Posfixa? ");
	gets(e); // Exemplo de entrada: 23*84/+
	
	printf("Valor = %d", valor(e)); // Saída: 8
	return 0;
}
