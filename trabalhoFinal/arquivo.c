#include "Sistema.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Lista *ArqToLisU(char *nomeArq)  // Funcao para carregar a lista de usuarios a partir do arquivo
{
    FILE *Arq = fopen(nomeArq, "rb"); //File utilizado para carregar a lista de usuarios
    Lista *aSerCarregada = newList(); // Friando a lista
    fseek(Arq, 0, SEEK_END);    // Seleciona a posicao do cursor no fim do arquivo para na linha abaixo calcular o tamanho dele
    int i, j, count = ftell(Arq) / sizeof(Info);
    int tamanhoArqInterno;
    if (ftell(Arq) != 0) // Se o arquivo nao esta vazio inicia-se o carregamento
    {
        Info up; // variavel que sera inserida
        FILE *Auxiliar; // File utilado para ccarregar lista de reservas
        Info upInterna; // Variavel que utiliza-se para inserir na lista de reservas
        for (i = 0; i < count; i++)
        {
            fseek(Arq, sizeof(Info) * i, SEEK_SET); //Posiciona o cursor do arquivo no inicio e desloca a quantidade de memoria a partir de i
            fread(&up, sizeof(Info), 1, Arq); // lendo do arquivo
            if (up.infUser.controle) // se controle == 1 significa que existe uma lista de reserva e carrega ela
            {
                up.infUser.listaDeReservas = newList(); // cria a lista
                Auxiliar = fopen(strcat(up.infUser.name, "U.dat"), "rb"); // concatena o nome do livro com "L" para identificar + .dat para arquivo binario
                fseek(Auxiliar, 0, SEEK_END);
                tamanhoArqInterno = ftell(Auxiliar) / sizeof(Info); // calculo do tamanho
                for (j = 0; j < tamanhoArqInterno; j++) // lendo e inserindo na lista de reservas
                {
                    fseek(Arq, sizeof(Info) * j, SEEK_SET);
                    fread(&upInterna, sizeof(Info), 1, Arq);
                    inserirNaLista(up.infUser.listaDeReservas, upInterna); // isera na lista
                }
                fclose(Auxiliar);
            }
            inserirNaLista(aSerCarregada, up);
        }
        fclose(Arq);
    }

    return aSerCarregada;
}
Lista *ArqToLisL(char *nomeArq) // O mesmo da funcao anterior se repe nesta diferenciando-se que agora sera alem de carregar a lista de livros ira carregar a fila de espera deste livro
{
    FILE *Arq = fopen(nomeArq, "rb");
    Lista *aSerCarregada = newList();
    fseek(Arq, 0, SEEK_END);
    int i, j, count = ftell(Arq) / sizeof(Info);
    int tamanhoArqInterno;
    if (ftell(Arq) != 0)
    {
        Info up;
        FILE *Auxiliar;
        Info upInterna;
        for (i = 0; i < count; i++)
        {
            fseek(Arq, sizeof(Info) * i, SEEK_SET);
            fread(&up, sizeof(Info), 1, Arq);
            if (up.infBook.controle)
            {
                up.infBook.filaEspera = newFila();
                Auxiliar =  fopen(strcat(up.infBook.title, "L.dat"), "rb"); // concatena o nome do livro com "L" para identificar + .dat para arquivo binario
                fseek(Auxiliar, 0, SEEK_END);
                tamanhoArqInterno = ftell(Auxiliar) / sizeof(Info);
                for (j = 0; j < tamanhoArqInterno; j++)
                {
                    fseek(Arq, sizeof(Info) * j, SEEK_SET);
                    fread(&upInterna, sizeof(Info), 1, Arq);
                    inserirNaFila(up.infBook.filaEspera, upInterna); // isera na fila
                }
                fclose(Auxiliar);
            }
            inserirNaLista(aSerCarregada, up);
        }
        fclose(Arq);
    }

    return aSerCarregada;
}

int LisToArqL(char *nomeArq, Lista *lista) // passa da lista de livros para o arquivo
{
    if (lista->inicio != NULL)
    {

        NoL *temp = lista->inicio; // auxiliar para percorer lista
        FILE *Arq = fopen(nomeArq, "wb"); // file usado para arquivar a lista de livros
        FILE *Auxiliar; // file utilizado para qrquivar a fila de espera do livro

        do // se a lista so tem o inicio arquiva ele
        {
            if (temp->item.infBook.controle) // verifica se o livro tem fila de espera
            {
                Auxiliar =  fopen(strcat(temp->item.infBook.title, "L.dat"), "wb"); // concatena o nome do livro com "L" para identificar + .dat para arquivo binario
                
                NoF *aux = temp->item.infBook.filaEspera->inicio;
                do
                    fwrite(&aux->item, sizeof(Info), 1, Auxiliar);
                while ((aux = aux->itemSucessor) != NULL); // percorrendo a fila e escrevendo
                fclose(Auxiliar);
            }
            fwrite(&temp->item, sizeof(Info), 1, Arq);
        } while ((temp = temp->itemSucessor) != lista->inicio);
        int count = ftell(Arq) / sizeof(Info);
        fclose(Arq);

        return count; //retorna a contagem de Info arquivada no arquivo de livros
    }
    return 0;
}
int LisToArqU(char *nomeArq, Lista *lista) // o mesmo se repete da funcao anterior, diferenciando-se que nesta e arquivada uma fila de espera de cada usuario tambem arquivado 
{
    if (lista->inicio != NULL)
    {
        NoL *temp = lista->inicio;
        FILE *Arq = fopen(nomeArq, "wb");
        FILE *Auxiliar;

        do // se a lista so tem o inicio arquiva ele
        {
            if (temp->item.infUser.controle) // verifica se o livro tem lista de reserva
            {
                Auxiliar = fopen(strcat(temp->item.infUser.name, "U.dat"), "wb"); // concatena o nome do livro com "U" para identificar + .dat para arquivo binario
                NoL *aux = temp->item.infUser.listaDeReservas->inicio;
                do
                    fwrite(&aux->item, sizeof(Info), 1, Auxiliar);
                while ((aux = aux->itemSucessor) != temp->item.infUser.listaDeReservas->inicio);
                fclose(Auxiliar);
            }
            fwrite(&temp->item, sizeof(Info), 1, Arq);
        } while ((temp = temp->itemSucessor) != lista->inicio);
        int count = ftell(Arq) / sizeof(Info);
        fclose(Arq);
        return count;
    }
    return 0;
}