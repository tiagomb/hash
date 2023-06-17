#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void inicializaNulo (struct hash T[m], int tam){
    int i;
    for (i = 0; i < tam; i++){
        T[i].estado = nulo;
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
    if (T1[pos].estado == nulo)
        return -1;
    if (T1[pos].estado == excluido || T1[pos].chave != chave){
        pos = h2(chave);
        if (T2[pos].estado == nulo || T2[pos].chave != chave)
            return -1;
        else
            return pos;
    }
    return pos;
}

void insere (int chave, struct hash T1[m], struct hash T2[m]){
    int pos1, pos2;
    pos1 = h1(chave);
    pos2 = h2(chave);
    if (T1[pos1].estado == ocupado && T1[pos1].chave == chave)
        return;
    if (T1[pos1].estado == ocupado){
        pos2 = h2(T1[pos1].chave);
        T2[pos2].chave = T1[pos1].chave;
        T2[pos2].estado = ocupado;
        T2[pos2].pos = pos2;
        T2[pos2].tabela = "T2";
    }
    T1[pos1].chave = chave;
    T1[pos1].estado = ocupado;
    T1[pos1].pos = pos1;
    T1[pos1].tabela = "T1";
}

void exclui (int chave, struct hash T1[m], struct hash T2[m]){
    int pos = h1(chave);
    if (T1[pos].estado == nulo)
        return;
    else if (T1[pos].estado == ocupado && T1[pos].chave == chave)
        T1[pos].estado = excluido;
    else{
        pos = h2(chave);
        if (T2[pos].estado == ocupado && T2[pos].chave == chave)
            T2[pos].estado = nulo;
    }
}

int junta(struct hash T1[m], struct hash T2[m], struct hash aux[m*2]){
    int pos = 0;
    for (int i = 0; i < m; i++)
        if (T1[i].estado == ocupado){
            aux[pos] = T1[i];
            pos++;
        }
    for (int i = 0; i < m; i++)
        if (T2[i].estado == ocupado){
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