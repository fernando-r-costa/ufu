#include <stdio.h>

int main()
{
    int qte = 0;
    int soma = 0;
    
    for (int i=0; qte<=50; i++){
        if(i%2==0) {
            soma = soma + i;
            qte++;
        }
    }
    
    
    printf("Soma: %d", soma);

    return 0;
}