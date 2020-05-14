#include "ponte.h"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int tamanho = 9;
    int opcao;
    OBJETO *vetorTeste = malloc(sizeof(OBJETO) * tamanho);
    inserirAleatoriosNoVetor(vetorTeste,tamanho);
    printf("Vetor desordenado:\t");
    printVetor(vetorTeste, tamanho);
    printf("bubble[1]\nselection[2]\ninsertion[3]\n");
    scanf("%d",&opcao);
    if (opcao == 1)
        bubble(vetorTeste,tamanho);
    else if (opcao ==2)   
        selection(vetorTeste,tamanho);
    printf("Vetor ordenado:\t\t");
    printVetor(vetorTeste, tamanho);
    return 0;
}
