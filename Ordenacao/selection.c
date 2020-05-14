#include "ponte.h"
#include "stdio.h"

void selection(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesRestantes;
    OBJETO *PonteiroValorMinimo; // encontraremos valores minimos para o metodo de troca ela recebera o endereco de memoria do valor minimo do vetor
    for (indicesRestantes = 0; indicesRestantes < tamanhoVetor; indicesRestantes++)
    {
        PonteiroValorMinimo = &vetorASerOrdenado[indicesRestantes];
        for (indiceComparado = indicesRestantes + 1; indiceComparado < tamanhoVetor; indiceComparado++)
        {
            if (PonteiroValorMinimo->key > vetorASerOrdenado[indiceComparado].key ) //se o valor selecionado for maior que o valor comparado atribuimos um novo apontamento para o nosso ponteiro
                PonteiroValorMinimo = &vetorASerOrdenado[indiceComparado];
        }
        swap(&vetorASerOrdenado[indicesRestantes], PonteiroValorMinimo); //troca
        printVetor(vetorASerOrdenado, tamanhoVetor);
    }
}