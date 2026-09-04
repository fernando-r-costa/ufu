#include <stdio.h>
#include "lista.h"

int main()
{
    Descritor lista;
    
    inicializarLista(&lista);
    exibirLista(&lista);
    
    adicionarNoInicio(&lista, 20);
    exibirLista(&lista);
    
    adicionarNoFinal(&lista, 10);
    exibirLista(&lista);
    
    adicionarNoInicio(&lista, 30);
    exibirLista(&lista);
    
    adicionarNoFinal(&lista, 25);
    exibirLista(&lista);
    
    adicionarNoInicio(&lista, 50);
    exibirLista(&lista);
    
    removerDoInicio(&lista);
    exibirLista(&lista);
    
    removerDoFinal(&lista);
    exibirLista(&lista);
    
    removerElemento(&lista, 20);
    exibirLista(&lista);
    
    return 0;
}
