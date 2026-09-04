#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*//Exerc�cio 01
    int i;
    for (i=0; i<=127; i++) {
       printf("%3d \t %c \n", i, i);
    };

    printf("\n ____________________________\n");

    i=0;
    while (i<=127) {
        printf("%3d \t %c \n", i, i);
        i++;
    };

    printf("\n ____________________________\n");

    i=0;
    do {
        printf("%3d \t %c \n", i, i);
        i++;
    } while (i<=127);*/

    //Exerc�cio 02: Imprimir um quadrado
    int n;

    printf("Digite a dimensao do quadrado: ");
    scanf("%d", &n);
    printf("\n");

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf(" *");
        }
        printf("\n");
    };

    printf("\n******************\n");
    printf("\n\n");

    for (int i=0; i<n; i++) {
        //for (int j=i; j<n; j++) {
        for (int j=0; j<i; j++) {
            printf(" *");
        }
        printf("\n");
    };

    return 0;
}
