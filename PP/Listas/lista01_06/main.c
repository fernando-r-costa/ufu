#include <stdio.h>

int main()
{
    int n1, n2, n3, n4;
    float media = 0;
    
    printf("Digite 4 notas para calcular a média: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    
    media = (n1+n2+n3+n4)/4.0;
    
    printf("A média é: %.2f", media);

    return 0;
}
