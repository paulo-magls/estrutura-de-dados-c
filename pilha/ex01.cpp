/* 
	Exercício 1. Crie um programa que usa duas pilhas A e B 
	para ordenar uma sequência de n números dados pelo usuário
*/

#include <stdio.h>
#include "pilha.h"

int main(void) {
	int n, x;
	printf("Quantidade? ");
	scanf("%d", &n);
	
	Pilha A = pilha(5);
	Pilha B = pilha(5);
	
	for(int i=1; i<=n; i++){
		printf("%do numero? ", i);
		scanf("%d", &x);
		while(!vaziap(A) && x>topo(A))
			empilha(desempilha(A), B);
		empilha(x, A);
		while(!vaziap(B))
			empilha(desempilha(B), A);
	}
	
	printf("Sequencia ordenada:\n");
	while(!vaziap(A))
		printf("%d\n", desempilha(A));
		
	destroip(&A);
	destroip(&B);
	
	return 0;
}
