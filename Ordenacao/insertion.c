#include "ponte.h"
#include "stdio.h"

void insertion(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesOrdenados;
    for (indicesOrdenados = 0; indicesOrdenados < tamanhoVetor; indicesOrdenados++) //a cada vez que o IndicesOrdenados 'e incrementado significa que um itam ja esta ordenado
    {
        for (indiceComparado = indicesOrdenados; indiceComparado > 0; indiceComparado--) //recebe o item de referencia e analisa ele de traz para frente ate chegar ao primeiro item
        {
            if (vetorASerOrdenado[indiceComparado].key <= vetorASerOrdenado[indiceComparado - 1].key) //se for menor que o aterior troca
            {
                swap(&vetorASerOrdenado[indiceComparado], &vetorASerOrdenado[indiceComparado - 1]); //troca
                printVetor(vetorASerOrdenado, tamanhoVetor);
            }
        }
    }
}