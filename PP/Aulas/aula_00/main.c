#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*char c = getchar();
    printf("Caractere: %c\n", c);
    printf("Codigo ASCII: %d\n", c);*/

    /*char c;
    scanf("%c", &c);
    printf("Caractere: %c\n", c);
    printf("Codigo ASCII: %d\n", c);*/

    char c;

    printf("Entre com o caractere: ");
    scanf("%c", &c);

    printf("Seu caractere foi: %c\n", c);
    printf("Seu caractere em ASCII: %d\n", c);

    return 0;
}
