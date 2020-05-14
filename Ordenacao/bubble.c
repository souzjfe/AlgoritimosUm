#include "ponte.h"
#include "stdio.h"



void bubble(OBJETO *vetorASerOrdenado, int tamanhoVetor)
{
    int indiceComparado, indicesRestantes; //  no bubble utiliza um limte e o seu sucessor para comparacao

    for (indicesRestantes = tamanhoVetor - 1; indicesRestantes >= 0; indicesRestantes--)
    {
        for (indiceComparado = 0; indiceComparado +1 < tamanhoVetor; indiceComparado++)
        {
            if (vetorASerOrdenado[indiceComparado].key > vetorASerOrdenado[indiceComparado + 1].key) //se a posicao da frente for maior o algoritmo troca
            {
                swap(&vetorASerOrdenado[indiceComparado], &vetorASerOrdenado[indiceComparado + 1]); //estamos trocando somente o endereco de memoria
                printVetor(vetorASerOrdenado, tamanhoVetor);
            }
        }
    }
}