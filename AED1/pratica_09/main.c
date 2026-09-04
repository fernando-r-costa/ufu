#include <stdio.h>
#include "lista.h"

int main()
{
    ListaCircular frota;
    frota.fim = NULL;
    
    imprimirFrota(&frota);

    inserirFinal(&frota, 50, 20);
    inserirFinal(&frota, 75, 50);
    inserirFinal(&frota, 60, 40);
    inserirFinal(&frota, 90, 80);
    
    imprimirFrota(&frota);
    
    int qtdPorAbastecimento = 10;
    abastecerFrota(&frota, qtdPorAbastecimento);
    
    imprimirFrota(&frota);
    
    return 0;
}
