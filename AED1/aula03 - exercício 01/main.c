#include <stdio.h>
#include "lista.h"

int main() {
    
    Lista lista;
    
    iniciar(&lista);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    
    exibir(&lista);
    
    return 0;
}