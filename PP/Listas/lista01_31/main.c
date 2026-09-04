#include <stdio.h>

int main()
{
    int n;
    
    printf("Digite um número: ");
    scanf("%d", &n);
    
    int m = 0;
    
    for(int i=0; i<5; i++) {
        m = n * 3 * (i+1);
        printf("%d\n", m);
    }

    return 0;
}