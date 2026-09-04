#include <stdio.h>

int main()
{
    float comprimento, largura, preco;
    
    printf("Informe o comprimento e a largura: ");
    scanf("%f %f", &comprimento, &largura);
    
    printf("Informe o preco do metro do arame: ");
    scanf("%f", &preco);
    
    float custo = ((comprimento+largura)*2)*5*preco;
    
    printf("O custo com arame é: R$ %.2f", custo);

    return 0;
}
