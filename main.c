#include <stdio.h>
#include <stdlib.h>

#define m 11

struct hash{
    int chave;
    int pos;
    char *tabela;
    int excluido : 1;
    int nulo : 1;
};

void inicializaNulo (struct hash T[m], int tam){
    int i;
    for (i = 0; i < tam; i++){
        T[i].nulo = 1;
    }
}

int h1 (int chave){
    return chave % m;
}

int h2 (int chave){
    return (int)(m * (chave * 0.9 - (int)(chave * 0.9)));
}

int busca (int chave, struct hash T1[m], struct hash T2[m]){
    int pos = h1(chave);
    if (T1[pos].nulo)
        return -1;
    if (T1[pos].excluido){
        pos = h2(chave);
        if (T2[pos].nulo)
            return -1;
        else
            return pos;
    }
    return pos;
}

void insere (int chave, struct hash T1[m], struct hash T2[m]){
    int pos1, pos2, chaveAntiga;
    pos1 = h1(chave);
    chaveAntiga = T1[pos1].chave;
    if (chaveAntiga == chave)
        return;
    if (!T1[pos1].nulo && !T1[pos1].excluido){
        pos2 = h2(chaveAntiga);
        T2[pos2].chave = chaveAntiga;
        T2[pos2].nulo = 0;
        T2[pos2].excluido = 0;
        T2[pos2].pos = pos2;
        T2[pos2].tabela = "T2";
    }
    T1[pos1].chave = chave;
    T1[pos1].nulo = 0;
    T1[pos1].excluido = 0;
    T1[pos1].pos = pos1;
    T1[pos1].tabela = "T1";
}

void exclui (int chave, struct hash T1[m], struct hash T2[m]){
    int pos = h1(chave);
    if (T1[pos].nulo)
        return;
    else if (T1[pos].chave == chave)
        T1[pos].excluido = 1;
    else{
        pos = h2(chave);
        if (T2[pos].chave == chave)
            T2[pos].nulo = 1;
    }
}

int junta(struct hash T1[m], struct hash T2[m], struct hash aux[m*2]){
    int pos = 0;
    for (int i = 0; i < m; i++)
        if (!T1[i].nulo && !T1[i].excluido){
            aux[pos] = T1[i];
            pos++;
        }
    for (int i = 0; i < m; i++)
        if (!T2[i].nulo && !T2[i].excluido){
            aux[pos] = T2[i];
            pos++;
        }
    return pos;
}

int compara (const void *a, const void *b){
    struct hash *x = (struct hash *)a;
    struct hash *y = (struct hash *)b;
    if (x->chave < y->chave)
        return -1;
    else if (x->chave > y->chave)
        return 1;
    else
        return 0;
}

void imprimeHash (struct hash aux[m*2], int tam){
    for (int i = 0; i < tam; i++)
        printf ("%d,%s,%d\n", aux[i].chave, aux[i].tabela, aux[i].pos);
}

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
