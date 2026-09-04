#include <stdio.h>
#include "lista.h"

// 1- a- a estrutura é definida recursivamente pois dessa forma é possível ligar um nó ao outro
//         gerando a lista encadeada, um nó tem um ponteiro para o outro nó
//     b- uma das vantagens está na possibilidade de expandir a lista sempre que um novo elemento
//         for inserido na lista, e também não é necessário espaço contínuo na memoria



int main() {
    
    No *lnum;
    int val;
    
    lnum = criaListaVazia();
    
    verificaListaVazia(lnum);
    
    for (int i=0; i<10; i++) {
        scanf("%d", &val);
        lnum = insereInicio (lnum, val);
    }
    
    imprime(lnum);
    
    imprime(lnum);
    
    return 0;
}