#include <stdio.h>
#include "lista.h"

int main() {
    
    ListaDinamica lista;
    
    iniciar(&lista, 3);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    
    exibir(&lista);
    
    liberar(&lista);
    
    exibir(&lista);
    
    return 0;
}