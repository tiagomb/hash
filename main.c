#include <stdio.h>
#include <stdlib.h>

#define m 11
#define null -1
#define excluded -2

void inicializaNulo (int T[m]){
    int i;
    for (i = 0; i < m; i++){
        T[i] = null;
    }
}

int h1 (int chave){
    return chave % m;
}

int h2 (int chave){
    return (int)(m * (chave * 0.9 - (int)(chave * 0.9)));
}

int buscaT1 (int chave, int T1[m]){
    int pos = h1(chave);
    if (T1[pos] == null){
        return null;
    }
    else if (T1[pos] == excluded || T1[pos] != chave){
        return excluded;
    }
    else
        return pos;
}

int buscaT2 (int chave, int T2[m]){
    int pos = h2(chave);
    if (T2[pos] != chave)
        return null;
    else
        return pos;
}

void insere (int chave, int T1[m], int T2[m]){
    int pos, chaveAntiga;
    pos = h1(chave);
    chaveAntiga = T1[pos];
    if (chaveAntiga == chave)
        return;
    T1[pos] = chave;
    if (chaveAntiga >= 0){
        pos = h2(chaveAntiga);
        T2[pos] = chaveAntiga;
    }
}

void exclui (int chave, int T1[m], int T2[m]){
    int pos = h1(chave);
    if (T1[pos] == null)
        return;
    else if (T1[pos] == chave)
        T1[pos] = excluded;
    else{
        pos = h2(chave);
        if (T2[pos] == chave)
            T2[pos] = null;
    }
}

void imprimeHash (int T1[m], int T2[m]){
    for (int i = 0; i < m; i++){
        if (T1[i] >=0 && T2[i] >=0){
            if (T1[i]>=T2[i]){
                printf ("%d,T1,%d\n", T1[i], i);
                printf ("%d,T2,%d\n", T2[i], i);
            }
            else{
                printf ("%d,T2,%d\n", T2[i], i);
                printf ("%d,T1,%d\n", T1[i], i);
            }
        }
        else if (T1[i] >= 0){
            printf ("%d,T1,%d\n", T1[i], i);
        }
        else if (T2[i] >= 0){
            printf ("%d,T2,%d\n", T2[i], i);
        }
    }
}

int main(){
    int T1[m], T2[m];
    int aux[m*2];
    inicializaNulo(T1);
    inicializaNulo(T2);
    char opcao;
	int chave;
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
    imprimeHash (T1, T2);
    return 0;
}