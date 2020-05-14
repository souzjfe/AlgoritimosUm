#include "Sistema.h"
#include <stdio.h>

int main()
{
    // Carregando as listas
    Lista *deLivrosDisponiveis = ArqToLisL("listaDeLivros.dat");
    Lista *deUsuarios = ArqToLisU("listaDeUsuarios.dat");
    //
    // Iniciando menu Geral encadeado a outros menus
    menuGeral(deUsuarios, deLivrosDisponiveis);
    //
    //salvando listas em arquivo
    LisToArqL("listaDeLivros.dat", deLivrosDisponiveis);
    LisToArqU("listaDeUsuarios.dat", deUsuarios);
    //
    return 0;
}
