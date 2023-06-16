### Equipe
- Eloisa Nielsen - GRR20221226
- Tiago Mendes Bottamedi - GRR20220068

### Objetivo

- O objetivo do trabalho é implementar um algoritmo de implementação, busca e exclusão de valores em uma tabela hash de endereçamento aberto.  Há duas tabelas, T1 e T2, de tamanho 11. A função hash de T1 é h1(chave) = chave mod 11, caso haja colisão na T1 (o endereço desejado já esteja ocupado), a chave nova é inserida no endereço retornado de h1 e a antiga é inserida em T2 pela função hash h2(chave) =  ⌊11 * (chave * 0.9 − ⌊chave * 0.9⌋)⌋. Caso haja colisão na T2, a chave antiga é substituida pela nova.

### Implementação

- As tabelas hash são vetores da struct hash de tamanho m, aqui m = 11:
```c
struct hash T1[m], T2[m]
```
- A struct hash possui os elementos chave, pos(endereço), tabela(string indentificando a tabela do elemento), excluido(informa se o elemento naquele endereço foi excluido, 1, ou não, 0) e nulo(informa se já house algum elemento naquele endereço, 0, ou não, 1).

```c
struct hash{
    int chave;
    int pos;
    char *tabela;
    int excluido : 1;
    int nulo : 1;
};
```
- Inicialmente todas as structs de T1 e T2 têm seu elemento nulo inicializado com 1.

- A função de busca inicialmente usa h1 para encontra o elemento em T1, se encontrado, o endereço é retornado. Se a posição em T1 for nula, a busca retorna -1, não há necessidade de buscar em T2. Se o elemento está marcado como excluído, h2 é utilizado para fazer a busca em T2, retornado o endereço caso o elemento tenha o campo nulo 0 e -1 caso contrário

- A função de inserção insere em T1 pelo endereço retornado por h1 se o endereço for nulo ou excluido, atualizando os valores da chave, nulo, excluido, pos e tabela. Caso o endereço esteja ocupado em T1 e a chave antiga seja a mesma ela não altera a tabela. Caso o endereço esteja ocupado em T1 e a chave antiga seja diferente, o elemento é inserido em T2 no endereço retornado por h2, independente da presença de uma chave antiga, também atualizando os valores da chave, nulo, excluido, pos e tabela.

```c
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
```
- A função de exlusão não altera a tabela caso o endereço do elemento em T1 seja nulo, caso contrário; se a chave for encontrado em T1 por h1 ela é marcada como excluída, se não, ela é buscada em T2 por h2 e, se encontrada, marcada com excluída. Se a chave não for encontrada a função não altera a tabela

```c
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
```
- Para facilitar a impressão, as tabelas hash são unidas em uma tabela hash auxiliar, que é então organizada em ordem crescente por meio da função qsort para que ela finalmente possa ser impressa na ordem desejada. A função qsort recebe como função de comparação a função "compara", que compara as chaves das structs para a ordenação:

```c
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
```
