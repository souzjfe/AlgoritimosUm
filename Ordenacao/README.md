# Algoritmos de Ordenação

Imagine um jogo de cartas qualquer, você recebe 9 cartas e decide ordena-las em ordem crescente. Há várias formas de organiza-las não? Exatamente, isso também acontece com vetores numéricos desordenados. Antes de programar o código sugiro que tenha consigo algumas cartas de baralho em mãos e ordene-as na forma que diz o algoritmo.

A **utilidade** de ordenar uma vetor é simplesmente para facilitar o trabalho de busca.

Para **ilustrar melhor** vizualize cada algoritmo [aqui](https://visualgo.net/en/sorting)

## Bubble Sort

Método de bolha, como o nome sugere a intenção é criar "bolhas" de comparação, voltando as cartas, seria como se pegassemos duas delas, ordenassemos elas separadamente e devolvessemos novamente à mão. Assim repetindo até que todas estivessem ordenadas. 

Vamos ao codigo:

~~~c
void bubble(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesRestantes; 

    for (indicesRestantes = tamanhoVetor - 1; indicesRestantes >= 0; indicesRestantes--)
        for (indiceComparado = 0; indiceComparado +1 < tamanhoVetor; indiceComparado++)
            if (vetorASerOrdenado[indiceComparado].key > vetorASerOrdenado[indiceComparado + 1].key) //se a posicao da frente for maior o algoritmo troca
                swap(&vetorASerOrdenado[indiceComparado], &vetorASerOrdenado[indiceComparado + 1]); //estamos trocando somente o endereco de memoria   
}
~~~

## Selection Sort

## Insertion Sort

## Quick Sort