#include <stdio_ext.h>
#include "Sistema.h"
#include <stdlib.h>

static void menuLivro(Lista *deLivrosDisponiveis) // menu para gerenciar livros opcao 1 do menu gerancial
{
    int opcao;
    char repetir;
    do
    {
        printf("Insira a opcão\n\n(1) Para adicionar livro\n(2) Para mostrar lista de livros(Atualizar/Excluir)\n(9) Para voltar ao menu da Interface Gerencial\n:");
        scanf("%d", &opcao);
            system("clear");
        switch (opcao)
        {
        case 1:
            printf("CADASTRO DE LIVRO\n");
            do
            {
                criarLivro(deLivrosDisponiveis);
                printf("Repetir?");
                __fpurge(stdin);
                scanf("%c", &repetir);
                system("clear");
            } while (repetir == 's' || repetir == 'S');
            break;
        case 2:
            printCatalogo(deLivrosDisponiveis, NULL, NULL, 'g');
            break;
        case 9:
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (opcao != 9);
}
static void menuUsuario(Lista *listaDeUsuarios) // menu para gerenciar o usuario opcao 2 do menu gerencial
{
    int opcao;
    char repetir;
    do
    {
        printf("Insira a opção\n\n(1) Para adicionar Usúario\n(2) Para mostrar lista de usúarios(Atualizar/Excluir)\n(9) Para voltar ao menu da Interface Gerencial\n:");
        scanf("%d", &opcao);
        system("clear");
        switch (opcao)
        {
        case 1:

            printf("CADASTRO DE USUARIO\n");
            do
            {
                criarUsuario(listaDeUsuarios);
                printf("Repetir?");
                __fpurge(stdin);
                scanf("%c", &repetir);
                system("clear");
            } while (repetir == 's' || repetir == 'S');
            break;
        case 2:
            printListaUser(listaDeUsuarios);
            break;
        case 9:
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (opcao != 9);
}
static void interfaceGerencial(Lista *listaDeUsuarios, Lista *deLivrosDisponiveis) // menu do gerente opcao 1 do menu geral
{
    int opcao;
    char repetir;

    do
    {
        printf("Insira a opcão\n\n(1) Para gerenciar livro\n(2) Para gerenciar usuario\n(9) Para voltar ao menu inicial\n:");
        scanf("%d", &opcao);
        system("clear");
        switch (opcao)
        {
        case 1:
            menuLivro(deLivrosDisponiveis);
            break;
        case 2:
            menuUsuario(listaDeUsuarios);
            break;
        case 9:
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (opcao != 9);
}
static void interfaceUsual(Lista *deUsuarios, Lista *deLivros) // interface para o usuario opcao 2 do  geral
{
    int opcao;
    char repetir;
    int id;
    if (deUsuarios->inicio != NULL)
    {
        printf("Informe seu ID\n: ");
        scanf("%d", &id);
        NoL *usuario = buscaIDusuario(id, deUsuarios);
        if (usuario != NULL && controleAcesso(usuario->item.infUser.senha))
        {
            printf("Bem vindo %s ", usuario->item.infUser.name);
            do
            {
                printf("insira sua opcão\n\n(1) Emprestar livro\n(2) Para atualizar cadastro de usuario\n(3) Para ver seus livros emprestados\n(9) Para voltar ao menu inicial\n:");
                scanf("%d", &opcao);
                system("clear");
                switch (opcao)
                {
                case 1:
                    printCatalogo(deLivros, deUsuarios, usuario, 'u');
                    break;
                case 2:
                    usuario->item = (Info)atualizarUsuario(deUsuarios);
                    break;
                case 3:
                    printCatalogo(usuario->item.infUser.listaDeReservas, deUsuarios, usuario, 'd');
                    break;
                case 9:
                    break;
                default:
                    printf("Opção Inválida\n");
                    break;
                }
            } while (opcao != 9);
        }
        else
            printf("ID não encontrado\n\n");
    }
}
void menuGeral(Lista *deUsuarios, Lista *deLivrosDisponiveis) // primeiro menu
{
    int opcao;
    char repetir;
    system("clear");
    printf("Bem vindo\n");
    do
    {
        printf("Insira a Opcão\n\n(1) para interface gerencial\n(2) para interface usual\n(3) para mostrar catalago\n(9) Para sair\n:");
        scanf("%d", &opcao);
        system("clear");
        switch (opcao)
        {
        case 1:
            if (controleAcesso("12345"))
                interfaceGerencial(deUsuarios, deLivrosDisponiveis);
            else
                opcao = 9;
            break;
        case 2:
            interfaceUsual(deUsuarios, deLivrosDisponiveis);
            break;
        case 3:
            printCatalogo(deLivrosDisponiveis, deUsuarios, NULL, 'a');
            break;
        case 9:
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (opcao != 9);
}