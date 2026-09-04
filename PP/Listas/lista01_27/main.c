#include <stdio.h>

int main()
{
    int n;
    
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    if(n%3==0 && n%5!=0) {
        printf("O número é divisível só por 3");
    } else if(n%3!=0 && n%5==0) {
        printf("O número é divisível só por 5");
    } else if(n%3==0 && n%5==0) {
        printf("O número é divisível por 3 e 5");
    } else {
        printf("O número não é divisível por 3 e 5");
    }

    return 0;
}
