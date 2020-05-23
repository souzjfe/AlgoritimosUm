# Algoritmos de Ordenação

Imagine um jogo de cartas qualquer, você recebe nove cartas e decide ordena-las em ordem crescente. Há várias formas de organiza-las não? Exatamente, isso também acontece com vetores numéricos desordenados. Antes de programar o código sugiro que tenha consigo algumas cartas de baralho em mãos e ordene-as na forma que diz o algoritmo.

A **utilidade** de ordenar uma vetor é simplesmente para facilitar o trabalho de busca.

Para **ilustrar melhor** vizualize cada algoritmo [aqui](https://visualgo.net/en/sorting).

Toda ordenação tem um **critério**. Pode ser ele ordenar pelo valor atribuido ao uma string, ou a ID de uma struct. Para exemplificar os  métodos ordenaremos decrescentemente. 

## Bubble Sort

Método de bolha, como o nome sugere a intenção é criar "bolhas" de comparação, voltando ao baralho, seria como se pegassemos duas cartas, a primeira e a segunda carta da mão, olhassemos pra elas e ordenassemos colocando a de **maior valor** na segunda possição e devolvessemos novamente à mão. A proxima bolha seria entre a segunda carta (aquela que deixamos na segunda posição) e a terceira. Assim repetindo até que a maior carta **chege ao final** da mão e então teriamos **uma carta já ordenada** em seu local final. 

#### Vamos ao código:

~~~c
void bubble(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesRestantes; 

    for (indicesRestantes = tamanhoVetor - 1; indicesRestantes >= 0; indicesRestantes--)
        for (indiceComparado = 0; indiceComparado +1 < tamanhoVetor; indiceComparado++)
            if (vetorASerOrdenado[indiceComparado].key > vetorASerOrdenado[indiceComparado + 1].key) //se a posicao da frente for maior o algoritmo troca
                swap(&vetorASerOrdenado[indiceComparado], &vetorASerOrdenado[indiceComparado + 1]); //troca
}
~~~

## Selection Sort

Com seu baralho em mãos você escolhe uma carta, olha para ela e compara com todas as outras até encontrar uma com valor menor (pode ser outro critério, isso define o modo de ordenação), quando você a  encontra temos então uma nova carta **selecionada** fazemos isso até chegar ao final das cartas, após isso colocamos na primeira posição, já que é a menor e estamos ordenando crescentemente. Opa uma carta **já está ordenada** agora selecionamos a segunda carta e repetimos o processo.

#### E aquilo que vocês procuram está aqui:

~~~c
void selection(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesOrdenados;
    OBJETO *PonteiroValorMinimo; // encontraremos valores minimos para o metodo de troca ela recebera o endereco de memoria do valor minimo do vetor
    for (indicesOrdenados = 0; indicesOrdenados < tamanhoVetor; indicesOrdenados++) //a cada vez que o IndicesOrdenados 'e incrementado significa que um itam ja esta ordenado
    {
        PonteiroValorMinimo = &vetorASerOrdenado[indicesOrdenados];
        for (indiceComparado = indicesOrdenados + 1; indiceComparado < tamanhoVetor; indiceComparado++)
        {
            if (PonteiroValorMinimo->key > vetorASerOrdenado[indiceComparado].key ) //se o valor selecionado for maior que o valor comparado atribuimos um novo apontamento para o nosso ponteiro
                PonteiroValorMinimo = &vetorASerOrdenado[indiceComparado];
        }
        swap(&vetorASerOrdenado[indicesOrdenados], PonteiroValorMinimo); //troca
    }
}
~~~



## Insertion Sort

O método por inserção baseia-se em observar um determinado indice e seus anteriores e inseri-lo (obvio) no local cuja o valor dele seja maior que o anterior e menor que o sucessor. **Exemplo sem enrolação a seguir:** Você tem cinco cartas em mãos, olha para a **segunda** carta e compara com as anteriores, ela é menor ou maior que a anterior? Se é menor **troca de lugar com a anterior** se maior mantém o lugar. Próxima carta, terceira posição, comparamos com a segunda e a primeira e fazemos a troca se necessário. Repete-se o processo até terminarmos as cartas.

#### Code:

~~~C
void insertion(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesOrdenados;
    for (indicesOrdenados = 0; indicesOrdenados < tamanhoVetor; indicesOrdenados++) //a cada vez que o IndicesOrdenados 'e incrementado significa que um itam ja esta ordenado

        for (indiceComparado = indicesOrdenados; indiceComparado > 0; indiceComparado--) //recebe o item de referencia e analisa ele de traz para frente ate chegar ao primeiro item
            if (vetorASerOrdenado[indiceComparado].key <= vetorASerOrdenado[indiceComparado - 1].key) //se for menor que o aterior troca
                swap(&vetorASerOrdenado[indiceComparado],&vetorASerOrdenado[indiceComparado - 1]); //troca
}
~~~



## Quick Sort
