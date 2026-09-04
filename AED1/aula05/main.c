#include <stdio.h>
#include "lista.h"

int main()
{
    // int x, *p, **q;
    // q = &p;
    // p = &x;
    // x = 10;
    
    // printf("\n%d\n", &q);
    // printf("\n%d\n", *q);
    // printf("\n%d\n", &p);
    // printf("\n%d\n", *p);
    // printf("\n%d\n", &x);
    // printf("\n%d\n", x);
    
    No *n1;
    
    criaListaVazia(&n1);
    
    int elem = 10;
    insereLista(&n1, elem);
    elem = 20;
    insereLista(&n1, elem);
    elem = 30;
    insereLista(&n1, elem);
    elem = 40;
    insereLista(&n1, elem);
    elem = 50;
    insereLista(&n1, elem);
    
    imprimeLista(&n1);
    printf("\n");
    
    elem = 30;
    
    buscaLista(&n1, elem);
    
    removerLista(&n1, elem);
    
    imprimeLista(&n1);
        
    return 0;
}