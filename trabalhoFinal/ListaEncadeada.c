#include <stdio_ext.h>
#include <stdlib.h>
#include "Sistema.h"

Lista *newList() // cria nova lista circular
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;

    return lista;
}
NoL *criarNoL(Info item) // cria a celula que ja recebe o seu item
{
    NoL *celula = (NoL *)malloc(sizeof(NoL));
    celula->item = item;
    celula->itemSucessor = NULL;
    celula->itemPrecessor = NULL;
    return celula;
}
int inserirNaLista(Lista *lista, Info item) // insereindo na lista 
{
    NoL *item_No = criarNoL(item);
    if (lista->inicio == NULL) // se a lista 'e nula a celula e inserida no inicio e sera circular com ela mesma
    {
        lista->inicio = item_No;
        lista->inicio->itemPrecessor = item_No;
        lista->inicio->itemSucessor = item_No;
        return 1;
    }
    else // se nao insere no final e atualiza
    {
        NoL *aux = lista->inicio->itemPrecessor;

        aux->itemSucessor = item_No;
        item_No->itemSucessor = lista->inicio;
        item_No->itemPrecessor = aux;
        lista->inicio->itemPrecessor = item_No;
        return 1;
    }
    return 0;
}
NoL *remover(Lista *l, NoL *item)
{
    NoL *temp = item;
    NoL *aux;

    //Verificar se a celula pesquisada não é nula
    if (item != NULL)
    {
        //Verificar se a lista tem apenas um item
        if (item == l->inicio && item->itemPrecessor == l->inicio)
        {
            l->inicio = NULL;
            free(l->inicio);
            return NULL;
        }
        else if (item == l->inicio) //Verificar se o item escolhido é o inicio da lista
        {
            aux = l->inicio;
            l->inicio = l->inicio->itemSucessor;
            l->inicio->itemPrecessor = aux->itemPrecessor;
            l->inicio->itemSucessor = aux->itemSucessor;

            return aux;
        }
        else if (item->itemSucessor == l->inicio) //Verificar se o item a ser removido é o ultimo item da lista
        {
            l->inicio->itemPrecessor = temp->itemPrecessor;
            temp->itemPrecessor->itemSucessor = l->inicio;
        }
        else //Excluir um item da lista que não seja a cabeça
        {
            aux = temp->itemPrecessor;
            aux->itemSucessor = temp->itemSucessor;
            temp->itemSucessor->itemPrecessor = aux;
        }

        return temp;
    }

    return NULL;
}
