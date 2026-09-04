#include <stdio.h>

int main()
{
    float nota1;
    float nota2;
    float nota3;
    
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);
    
    float media = ((nota1*2) + (nota2*3) + (nota3*3)) / (2+3+3);
    
    printf("%.2f", media);
    
    return 0;
}