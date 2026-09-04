#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main()
{
    No* lista = NULL;
    int p, k;
    
    printf("Indique o número de pessoas: ");
    scanf("%d", &p);
    
    for(int i = p; i >= 1; i--) {
        inserirInicio(&lista, i);
    }
    
    srand(time(NULL));
    k = (rand() % 10) +1;
    printf("O número de saltos: %d\n", k);
    
    escolherLider(&lista, k);
    
    return 0;
}
