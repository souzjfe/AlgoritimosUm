#include <stdio_ext.h>
#include "Sistema.h"
#include <stdlib.h>
#include <string.h>

int controleAcesso(char *keyDefined) // somente para nocao de seguranca que deve ter o sistema
{
    int i = 0;
    char senha[MAX_SIZE_PASSWORD];
    int tentativas = 0;
    do
    {
        if (tentativas > 0)
        {
            printf("%d tentativas restantes\n", 3 - tentativas);
            if (tentativas == 3) // se n conferir em 3 vezes voltq ao menu anterior
            {
                system("clear");
                return 0;
            }
        }
        printf("Informe a senha: \n");
        __fpurge(stdin);
        fgets(senha, MAX_SIZE_PASSWORD, stdin);

        tentativas++;

    } while (strcmp(senha, keyDefined) != 0); //valida se a senha confere
    system("clear");
    return 1;
}
NoL *buscaIDlivro(int keyID, Lista *deLivros) // busca sequencial por id de livros
{

    if (deLivros->inicio != NULL)
    {
        NoL *aux = deLivros->inicio;
        do
            if (keyID == aux->item.infBook.id)
                return aux;
        while ((aux = aux->itemSucessor) != deLivros->inicio);
    }
    return NULL;
}
NoL *buscaIDusuario(int keyID, Lista *deUsuarios) // busca sequencial por id de livros
{
    if (deUsuarios->inicio != NULL)
    {
        NoL *aux = deUsuarios->inicio;
        do
            if (aux->item.infUser.id == keyID)
                return aux;
        while ((aux = aux->itemSucessor) != deUsuarios->inicio); // percorrer a lista
    }
    return NULL;
}

/*
funcao para criar livros
ela cria e insere na lista de livros
se ja existe um id igual ela verifica se o nome 'e o mesmo, se for o mesmo somente 'e incrementado a quantidade 
no livro ja criado, se nao pede para repetir o id
*/

int criarLivro(Lista *deLivros)
{
    Book novo;
    NoL *temp;

    printf("Informe o titulo do livro: ");
    __fpurge(stdin);
    fgets(novo.title, MAX_SIZE_NAME, stdin); // utilizei fgets em vez de gets pois gets nao funciona bem no meu compilador
    do
    {
        printf("\nInforme o id do livro: ");
        scanf("%d", &novo.id);
    } while ((temp = buscaIDlivro(novo.id, deLivros)) != NULL && strcmp(temp->item.infBook.title, novo.title) != 0); //se o id ja existe e o nome desses sao diferentes ele pede novamente o id
    printf("\nInforme o genero do livro: ");
    __fpurge(stdin);
    fgets(novo.genero, MAX_SIZE_NAME, stdin);
    printf("\nQual a quantidade dese livro sera incluida: ");
    scanf("%d", &novo.quantidade);
    novo.filaEspera = newFila(); // inicia a fila de espera
    novo.controle = 0; // inicia o controle como 0 pois ainda nao possui fila
    if (temp != NULL && strcmp(temp->item.infBook.title, novo.title) == 0) // se o id e o mesmo e o nome tambem soma a quantidade
    {
        printf("Ja existe esse livro, foi somado sua quantidade\n");
        temp->item.infBook.quantidade += novo.quantidade;
        return 1;
    }
    else
    {
        return inserirNaLista(deLivros, (Info)novo); //se nao insere na lista
    }

    return 0;
}
Book atualizarLivro(Lista *deLivros) // a funcao retorna um book e este substituira o livro que deve ser atualizado
{
    Book novo;
    NoL *temp; // necessaria para buscar igualdades de id

    printf("Informe o titulo do livro: ");
    __fpurge(stdin);
    fgets(novo.title, MAX_SIZE_NAME, stdin);
    do
    {
        printf("\nInforme o id do livro: ");
        scanf("%d", &novo.id);
    } while ((temp = buscaIDlivro(novo.id, deLivros)) != NULL && strcmp(temp->item.infBook.title, novo.title) != 0); //se o id ja existe pede para repetir
    printf("\nInforme o genero do livro: ");
    __fpurge(stdin);
    fgets(novo.genero, MAX_SIZE_NAME, stdin);
    printf("\nQual a quantidade dese livro sera incluida: ");
    scanf("%d", &novo.quantidade);
    if (temp != NULL && strcmp(temp->item.infBook.title, novo.title) == 0) // se ja exite o livrro soma a quantidade
    {
        printf("Ja existe esse livro, foi somado sua quantidade\n");
        temp->item.infBook.quantidade += novo.quantidade;
    }
    else //se nao retorna o livro atualizado
    {
        return novo;
    }
}
int criarUsuario(Lista *deUsuarios)
{
    User novo;
    printf("Informe o nome: ");
    __fpurge(stdin);
    fgets(novo.name, MAX_SIZE_NAME, stdin);
    do
    {
        printf("\nInforme o id: ");
        scanf("%d", &novo.id);
    } while (buscaIDusuario(novo.id, deUsuarios) != NULL); // pede para repetir o id
    printf("\nInforme uma senha: ");
    __fpurge(stdin);
    fgets(novo.senha, MAX_SIZE_PASSWORD, stdin);
    novo.listaDeReservas = newList(); // inicializa a lista de livros do usuario
    novo.controle = 0; // inicia com 0 
    inserirNaLista(deUsuarios, (Info)novo); //insere na lista
    return 1;
}
User atualizarUsuario(Lista *deUsuarios) // retorna o usuario que substituira o desatualizado
{
    User novo;
    printf("Informe o nome: ");
    __fpurge(stdin);
    fgets(novo.name, MAX_SIZE_NAME, stdin);
    do
    {
        printf("\nInforme o id: ");
        scanf("%d", &novo.id);
    } while (buscaIDusuario(novo.id, deUsuarios) != NULL);
    printf("\nInforme uma senha: ");
    __fpurge(stdin);
    fgets(novo.senha, MAX_SIZE_PASSWORD, stdin);
    return novo;
}

void printLivro(Book livro)
{
    printf("\tTitulo: %s\tID: %d\n\tGenero: %s\tQuantidade: %d\n", livro.title, livro.id, livro.genero, livro.quantidade);
}

void printUsuario(User usuario)
{
    printf("Nome: %s\tID: %d\n", usuario.name, usuario.id);
}
void printListaUser(Lista *lista) // funcao para mostrar lista de usuarios
{
    if (lista->inicio == NULL)
        printf("Nenhum Usuario Cadastrado \n");
    else
    {
        char opcao;
        NoL *aux = lista->inicio; // variavel para percorrer a lista
        do
        {
            printUsuario(aux->item.infUser);
            printf("Opcao: [f] Para avancar, [t] Para retroceder, [v] Para voltar, [e] Para excluir e [a] Para atualizar\n:");
            __fpurge(stdin);
            scanf("%c", &opcao);
            system("clear");
            switch (opcao)
            {
            case 'f':
                aux = aux->itemSucessor;
                break;

            case 't':
                aux = aux->itemPrecessor;
                break;

            case 'v':
                break; //

            case 'a':
                printf("ATUALIZAR LIVRO\n"); 
                aux->item = (Info)atualizarUsuario(lista);  
                break;
            case 'e':
                remover(lista, aux);
                aux = aux->itemSucessor;
                break;
            }

        } while (opcao != 'v' && lista->inicio != NULL); // caso todos os usuarios sejam excluido ele para o while
    }
}
void emprestar(NoL *itemLivro, NoL *itemUsuario) // retorna 1 se entrou na fila de espera 0 se nao conseguiu inserir -1 se emprestou;
{
    if (itemLivro->item.infBook.quantidade > 0) // se for maior que zero tem livro em estoque e empresta para o usuario;
    {
        Info aux = itemLivro->item;
        aux.infBook.quantidade = 1;
        inserirNaLista(itemUsuario->item.infUser.listaDeReservas, itemLivro->item);
        itemLivro->item.infBook.quantidade--;
        printf("Livro enviado para sua lista de emprestimos\n\n");
        itemUsuario->item.infUser.controle = 0; // indica que existe uma lista dentro do usuario
    }
    else
    {
        inserirNaFila(itemLivro->item.infBook.filaEspera, itemUsuario->item);
        printf("Voce entrou na fila para resgatar este livro\n\n");
        itemLivro->item.infBook.controle = 1; //indica que existe uma fila dentro do usuario
    }
}
void devolver(NoL *aDevolver, Lista *deLivros, Lista *deReservas) // retorna 1 se devolveu 0 se nao
{
    NoL *temp = buscaIDlivro(aDevolver->item.infBook.id, deLivros);

    if (temp->item.infBook.filaEspera->inicio != NULL) // se for nao nula eu insiro na lista de reserva do primeiro usuario da fila de espera desse livro
    {
        inserirNaLista(aDevolver->item.infBook.filaEspera->inicio->item.infUser.listaDeReservas, aDevolver->item);
        desenfileirar(temp->item.infBook.filaEspera);// remove o primeiro usuario da fila
    }
    else
        temp->item.infBook.quantidade++; // caso contrario aumenta a quantidade do livro no catalogo
    remover(deReservas, aDevolver);
    printf("Livro devolvido\n\n");
}
/*
// PRINTCATALOGO -> funcao que mostra a lista de livros de acordo com o controle
CONTROLE:
u = para finalidade usuaria
g = para finalidade gerencial
d = uaual para modo liberado para devolucao;
*/
void printCatalogo(Lista *deLivros, Lista *deUsuarios, NoL *usuario, char controle)
{
    if (deLivros->inicio == NULL)
        printf("Nenhum Livro Cadastrado \n\n");
    else
    {
        NoL *aux = deLivros->inicio;
        char opcao = 'n';
        do
        {
            printLivro(aux->item.infBook);

            if (controle == 'g')
                printf("Opcao: [f] Para avancar, [t] Para retroceder, [v] Para voltar: [e] Para excluir e [a] Para atualizar\n:");
            else if (controle == 'u')
                printf("Opcao: [f] Para avancar, [t] Para retroceder, [v] Para voltar e [r] Para reservar\n:");
            else if (controle == 'd')
                printf("Opcao: [f] Para avancar, [t] Para retroceder, [v] Para voltar e [d] Para devolver\n:");
            else
                printf("Opcao: [f] Para avancar, [t] Para retroceder, [v] Para voltar\n:");
            __fpurge(stdin);
            scanf("%c", &opcao);
            system("clear");
            if (opcao == 'f')
                aux = aux->itemSucessor;
            else if (opcao == 't')
                aux = aux->itemPrecessor;
            else if (opcao == 'r' && controle == 'u')
                emprestar(aux, usuario);
            else if (opcao == 'e' && controle == 'g')
                remover(deLivros, aux);
            else if (opcao == 'a' && controle == 'g')
                aux->item = (Info)atualizarLivro(deLivros);
            else if (opcao == 'd' && controle == 'd')
                devolver(aux, deLivros, usuario->item.infUser.listaDeReservas);
            else if (opcao != 'v')
                printf("Opção Inválida\n");
        } while (opcao != 'v' && deLivros->inicio != NULL); // caso todos os livros sejam excluidos ele para o while
    }
}
