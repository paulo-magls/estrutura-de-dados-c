#include <stdio.h>
#include <ctype.h>
// fun��o isdigit(): isdigit(5) -> 1 || isdigit('A') -> 0
#include <string.h>
// fun��o strchr(): strchr("ABC", 'A') -> 1 || strchr("ABC", 'D') -> 0
#include "pilha.h"

// fun��o que recebe uma express�o prefixa e devolve o resultado
int valpre(char *e){
	Pilha p = pilha(512);
	
	for(int i = strlen(e)-1; i >= 0; i--)
		// e[i]-'0' -> converte o caractere para digito
		if(isdigit(e[i])) empilha(e[i]-'0', p);
		else if(strchr("+-*/", e[i])){
			int x = desempilha(p);
			int y = desempilha(p);
			
			switch(e[i]){
				case '+': empilha(x+y, p); break;
				case '-': empilha(x-y, p); break;
				case '*': empilha(x*y, p); break;
				case '/': empilha(x/y, p); break;
			}
		}
		
	int z = topo(p); // Tamb�m pode usar o desempilha(p)
	destroip(&p);
	return z;
}

int main(void) {
	char e[256];
	
	printf("Prefixa? ");
	gets(e); // Exemplo de entrada: +*23/84
	
	printf("Valor = %d", valpre(e)); // Sa�da: 8
	return 0;
}
