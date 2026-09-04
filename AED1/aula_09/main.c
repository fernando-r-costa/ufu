#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    ListaCircular lista;
    lista.fim = NULL;

    // Inserindo elementos
    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirFinal(&lista, 40);

    // Imprimindo a lista de forma iterativa
    imprimirLista(&lista);

    // ALTERADO: Descomentado e ativado o teste da nova função de ordenação corrigida
    if (listaCircularOrdenada(&lista)) {
        printf("A lista esta ordenada em ordem crescente.\n");
    } else {
        printf("A lista nao esta ordenada.\n");
    }
    
    printf("\nImpressao da lista recursiva: ");
    imprimirRecursiva(&lista);
    
    // ALTERADO: Substituído a chamada crua pelo wrapper 'buscarLista', iniciando a busca pelo começo real
    printf("\nResultado da busca: %d\n", buscarLista(&lista, 40));

    return 0;
}