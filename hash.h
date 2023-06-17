#include <stdio.h>
#include <stdlib.h>

#define m 11
#define nulo 0
#define ocupado 1
#define excluido 2

struct hash{
    int chave;
    int pos;
    char *tabela;
    char estado;
};

//Inicializa os estados de todos os elementos da tabela como nulo
void inicializaNulo (struct hash T[m], int tam);

//Função hash da primeira tabela
int h1 (int chave);

//Função hash da segunda tabela
int h2 (int chave);

//Busca a chave nas tabelas. Caso encontre, retorna a posição da chave na tabela. Caso contrário, retorna -1
int busca (int chave, struct hash T1[m], struct hash T2[m]);

/*Insere a chave nas tabelas. Caso a chave já esteja presente, não faz nada. Caso contrário, insere a chave na tabela 1 e, caso haja colisão, 
insere a chave antiga na tabela 2*/
void insere (int chave, struct hash T1[m], struct hash T2[m]);

/*Exclui a chave das tabelas. Caso a chave não esteja presente, não faz nada. Caso contrário, exclui a chave da tabela 1 (marcando a posição como exclúida 
para ajudar na busca) e, caso haja colisão, exclui a chave da tabela 2 (marcando a posição como nula)*/
void exclui (int chave, struct hash T1[m], struct hash T2[m]);

//Junta as duas tabelas em uma só, para que os elementos possam ser ordenados a fim de serem impressos
int junta(struct hash T1[m], struct hash T2[m], struct hash aux[m*2]);

//Compara as chaves para ordená-las através da função qsort
int compara (const void *a, const void *b);

//Imprime a tabela hash no formato especificado
void imprimeHash (struct hash aux[m*2], int tam);