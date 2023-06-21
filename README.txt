### Equipe
- Eloisa Nielsen - GRR20221226
- Tiago Mendes Bottamedi - GRR20220068

### Objetivo

- O objetivo do trabalho é implementar um algoritmo de inserção, busca e exclusão de valores em uma tabela hash de endereçamento aberto.  Há duas tabelas de tamanho 11, T1 e T2. A função hash de T1 é h1(chave) = chave mod 11, e a de T2 é h2(chave) =  ⌊11 * (chave * 0.9 − ⌊chave * 0.9⌋)⌋.

### Implementação

- As tabelas hash são vetores da struct hash de tamanho m, aqui m = 11:

- A struct hash possui os elementos: chave, pos(endereço), tabela(string identificando a tabela da chave), e estado(informa se o endereço é nulo(ou seja, não há uma chave válida nele), 0, se o endereço está ocupado, 1, ou se a chave foi excluída, 2).

struct hash{
    int chave;
    int pos;
    char *tabela;
    char estado;
};

- Inicialmente todas as structs de T1 e T2 têm seus estados inicializados como nulos.

- A função de busca inicialmente usa h1 para encontrar a chave em T1, se encontrada, seu endereço é retornado. Se a posição em T1 for nula, a busca retorna -1, não há necessidade de buscar em T2. Se a chave está marcada como excluída ou é diferente da buscada, h2 é utilizada para fazer a busca em T2, retornando -1 caso o endereço tenha o estado nulo ou a chave presente seja diferente da buscada, e a posição, caso contrário.

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

- A função de inserção insere a chave nova em T1 na posição retornada por h1, exceto se essa chave já estiver na tabela (nesse caso, a função ignora a duplicata e não altera a tabela). Caso o endereço esteja ocupado antes da inserção, a chave antiga também é movida para T2 na posição retornada por h2.

- A função de exclusão, ao invés de remover de fato a chave, apenas altera o estado da posição que ela ocupa. Ou seja, caso a chave seja encontrada em T1, sua posição é marcada como excluída, para auxiliar no algoritmo de busca. Caso seja encontrada em T2, sua posição é marcada como nula, uma vez que nenhuma outra chave depende desta para a busca. Caso não seja encontrada, nada é alterado.

- Para facilitar a impressão, as tabelas hash são unidas pela função "junta" em uma tabela hash auxiliar, que é então organizada em ordem crescente por meio da função qsort para que ela finalmente possa ser impressa na ordem desejada. A função qsort recebe como função de comparação a função "compara", que compara as chaves das structs para a ordenação.
