#include "ponte.h"
#include "stdio.h"

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
        printVetor(vetorASerOrdenado, tamanhoVetor);
    }
}