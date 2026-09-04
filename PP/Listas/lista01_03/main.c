#include <stdio.h>

int main()
{
    int n;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    
    int q = n * n;
    
    printf("O quadrado do seu número é: %d", q);

    return 0;
}