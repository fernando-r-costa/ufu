#include <stdio.h>

int main()
{
    float valor;
    
    printf("Digite o valor para desconto: ");
    scanf("%f", &valor);
    
    float valor_desconto = valor - (valor*0.15);
    
    printf("Valor com desconto de 15%: %.2f", valor_desconto);

    return 0;
}
