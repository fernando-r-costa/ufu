#include <stdio.h>
/*int somatorio(int numero) {
        if (numero == 1) {
            return 1;
        } else {
            return numero + somatorio(numero - 1);
        }
    }

int main()
{
    
    int numero;
    printf("Digite o numero: ");
    scanf("%d", &numero);
    
    printf("Somatorio de 1 ate %d: %d", numero, somatorio(numero));

    return 0;
}*/

int fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        } else {
            return fibonacci(n-1) + fibonacci(n - 2);
        }
    }

int main()
{
    int n;
    printf("Digite o numero: ");
    scanf("%d", &n);
    
    printf("Fibonacci de %d: %d", n, fibonacci(n));

    return 0;
}