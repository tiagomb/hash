#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
    struct hash T1[m], T2[m], aux[m*2];
    inicializaNulo(T1, m);
    inicializaNulo(T2, m);
    inicializaNulo (aux, m*2);
    char opcao;
	int chave, tam;
	while (!feof(stdin)){
		scanf(" %c %d", &opcao, &chave);
		switch (opcao){
			case 'i':
				insere (chave, T1, T2);
			break;
			case 'r':
				exclui (chave, T1, T2);
			break;
			default:
				fprintf (stderr, "Argumento inválido\n");
				exit(1);
		}
	}
    tam = junta(T1, T2, aux);
    qsort (aux, tam, sizeof(struct hash), compara);
    imprimeHash(aux, tam);
    return 0;
}