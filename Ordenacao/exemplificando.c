#include "ponte.h"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int tamanho = 9;
    OBJETO *vetorTeste = malloc(sizeof(OBJETO) * tamanho);
    inserirAleatoriosNoVetor(vetorTeste,tamanho);
    printf("Vetor desordenado:\t");
    printVetor(vetorTeste, tamanho);

    bubble(vetorTeste,tamanho);
    printf("Vetor ordenado:\t\t");
    printVetor(vetorTeste, tamanho);

    return 0;
}
