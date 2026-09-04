#include <stdio.h>

int main()
{
    int n;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    
    int resultado = ((n*3)+1) + ((n*2)-1);
    
    printf("O quadrado do seu número é: %d", resultado);

    return 0;
}
