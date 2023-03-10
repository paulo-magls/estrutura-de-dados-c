/*
	Exerc�cio 2. Dado um n�mero natural em base 10, exiba-o em bin�rio.
*/

#include <stdio.h>
#include "pilha.h"

int main(void) {
	int n;
	Pilha p = pilha(8 * sizeof(int));
	
	printf("Decimal? ");
	scanf("%d", &n);
	
	do {
		empilha(n%2, p);
		n /= 2;
	} while(n>0);
	
	printf("Binario = ");
	while(!vaziap(p))
		printf("%d", desempilha(p));
	
	destroip(&p);
	return 0;
}
