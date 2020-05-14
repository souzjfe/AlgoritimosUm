#include "ponte.h"
#include <stdio.h>
#include <stdlib.h>

void inserirAleatoriosNoVetor(OBJETO *vetor,int tamanho)
{
    int indiceQueRecebera_Valor;
    for ( indiceQueRecebera_Valor = 0; indiceQueRecebera_Valor < tamanho; indiceQueRecebera_Valor++)
    {
        vetor[indiceQueRecebera_Valor].key= rand()%10; //valores aleatorios ate 10;
    }
    
}

void swap(OBJETO *a, OBJETO *b)
{
    OBJETO aux = *a;
    *a = *b;
    *b = aux;
    printf("Trocou %d com %d:\t\t", b->key, a->key);
}
void printVetor(OBJETO *vetor, int tamanho)
{
    int indiceMostrado;
    printf("{%d",vetor[0].key);
    for ( indiceMostrado = 1; indiceMostrado < tamanho; indiceMostrado++)
    {
        printf(", %d",vetor[indiceMostrado].key);
    }
    printf("}\n");
}


