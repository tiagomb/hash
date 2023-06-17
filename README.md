### Equipe
- Eloisa Nielsen - GRR20221226
- Tiago Mendes Bottamedi - GRR20220068

### Objetivo

- O objetivo do trabalho é implementar um algoritmo de inserção, busca e exclusão de valores em uma tabela hash de endereçamento aberto.  Há duas tabelas de tamanho 11, T1 e T2. A função hash de T1 é h1(chave) = chave mod 11, caso haja colisão(o endereço desejado já esteja ocupado) em T1, a chave nova é inserida no endereço retornado de h1 e a antiga é inserida em T2 pela função hash h2(chave) =  ⌊11 * (chave * 0.9 − ⌊chave * 0.9⌋)⌋. Caso haja colisão na T2, a chave antiga é substituida pela nova.

### Implementação

- As tabelas hash são vetores da struct hash de tamanho m, aqui m = 11:
```c
struct hash T1[m], T2[m]
```
- A struct hash possui os elementos chave, pos(endereço), tabela(string indentificando a tabela do elemento), e estado(informa se o elemento do endereço é nulo(ou seja, nunca houve um elemento nele), 0, se o enedereço está ocupado, 1, ou se o elemento foi excluído, 2).

```c
struct hash{
    int chave;
    int pos;
    char *tabela;
    char estado;
};
```
- Inicialmente todas as structs de T1 e T2 têm seus estados inicializados como nulo.

- A função de busca inicialmente usa h1 para encontrar o elemento em T1, se encontrado, o endereço é retornado. Se a posição em T1 for nula, a busca retorna -1, não há necessidade de buscar em T2. Se o elemento está marcado como excluído ou é diferente do buscado, h2 é utilizada para fazer a busca em T2, retornando -1 caso o endereço tenha o estado nulo ou a chave presente seja diferente da buscada, e a posição, caso contrário
- A função de inserção insere a chave nova em T1 na posição retornada por h1, exceto se essa chave já estiver na tabela (nesse caso, a função ignora a duplicata e não faz nada). Caso haja uma chave nessa posição, ela é movida para T2 na posição retornada por h2.
  

```c
void insere (int chave, struct hash T1[m], struct hash T2[m]){
    int pos1, pos2;
    pos1 = h1(chave);
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
```
- A função de exclusão, ao invés de remover de fato a chave, apenas altera o estado da posição que ela ocupa. Ou seja, caso a chave seja encontrada em T1, sua posição é marcada como excluída, para auxiliar no algoritmo de busca. Caso seja encontrada em T2, sua posição é marcada como nula, uma vez que nenhuma outra chave depende dessa para a busca. Caso não seja encontrada, nada acontece.

```c
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
