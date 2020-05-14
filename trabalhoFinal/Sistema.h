#define MAX_SIZE_NAME 100
#define MAX_SIZE_PASSWORD 6
#define MAX_SIZE_FLE 50
#include <stdio.h>
//lista circular
typedef struct Lista
{
    struct NoL *inicio;
} Lista;
//
//fila encadeada
typedef struct Fila
{
    struct NoF *fim;
    struct NoF *inicio;
} Fila;
//

// usuario
typedef struct User
{
    int controle; // 0 se nao tem lista de reserva 1 se tem
    char name[MAX_SIZE_NAME];
    int id;
    char senha[MAX_SIZE_PASSWORD];
    Lista *listaDeReservas;
} User;
//
//livro
typedef struct Book
{
    int controle; //0 se nao tem fila de espera 1 se tem
    unsigned id;
    int quantidade;
    char title[MAX_SIZE_NAME];
    char genero[MAX_SIZE_NAME];
    Fila *filaEspera;
} Book;
//

typedef union Info //atravez dessa union podemos usar algumas fun'coes para ambas as estruturas sem precisar mudar o algoritmo;
{
    Book infBook;
    User infUser;
} Info;


typedef struct NoF // celula para fila
{
    Info item;
    struct NoF *itemSucessor;
} NoF;

typedef struct NoL // celula para lista
{
    Info item;
    struct NoL *itemSucessor;
    struct NoL *itemPrecessor;
} NoL;

//Funcoes da lista encadeada
Lista *newList();
NoL *criarNoL(Info item);
int inserirNaLista(Lista *lista, Info item);
Info liberarItem(NoL *item);
NoL *remover(Lista *l, NoL *item);
//
//funcoes gerais e especificas do sistema
int controleAcesso(char *keyDefined);
int criarLivro(Lista *deLivros);
int criarUsuario(Lista *deUsuarios);
void printLivro(Book livro);
void printUsuario(User usuario);
void printListaUser(Lista *lista);
void printUcatalogo(Lista *lista, NoL *usuario);
void printCatalogo(Lista *deLivros, Lista *deUsuarios, NoL *usuario, char controle);
int buscarLivro(Lista *lista, unsigned id);
void devolver(NoL *aDevolver, Lista *deLivros, Lista *deReservas);
NoL *buscaIDlivro(int keyID, Lista *deLivros);
NoL *buscaIDusuario(int keyID, Lista *deUsuarios);
User atualizarUsuario(Lista *deUsuarios);
//
//funcoes do menu

void menuGeral(Lista *listaDeUsuarios, Lista *listaDeLivrosDisponiveis);

// funcoes do arquivo 

Lista *ArqToLisU(char *nomeArq);
Lista *ArqToLisL(char *nomeArq);

int LisToArqL(char *nomeArq, Lista *lista);
int LisToArqU(char *nomeArq, Lista *lista);
//
//funcoes da fila

Fila *newFila();
NoF *criarNoF(Info item);
int inserirNaFila(Fila *fila, Info item);
int desenfileirar(Fila *fila);
//