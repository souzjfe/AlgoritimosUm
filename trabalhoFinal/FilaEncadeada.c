#include "Sistema.h"
#include <stdlib.h>
Fila *newFila()
{
    Fila *nova = malloc(sizeof(Fila)); // aloca a fila
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

NoF *criarNoF(Info item) // cria a celula que ja recebe o valor a ela destinado
{
    NoF *c = (NoF *)malloc(sizeof(NoF));
    c->item = item;
    c->itemSucessor = NULL;

    return c;
}
int inserirNaFila(Fila *fila, Info item) // insere na fila retorna 1 se ssucesso 0 se nao
{
    NoF *item_No = criarNoF(item);
    if (fila->inicio == NULL) // se a fila esta vazia insere no incio e o fim sera o proprio inicio portanto atualiza o fim
    {
        fila->inicio = item_No;
        fila->fim = item_No;
        return 1;
    }
    else // se a fila nao esta vazia insere no fim 
    {
        fila->fim->itemSucessor = item_No;
        fila->fim = fila->fim->itemSucessor;
        return 1;
    }
    return 0;
}

int desenfileirar(Fila *fila) // remove o incio e atualiza
{
    NoF *aux;

    if (fila->inicio != NULL)
    {
        aux = fila->inicio;
        fila->inicio = aux->itemSucessor;
        free(aux);
        return 1;
    }
    return 0;
}
