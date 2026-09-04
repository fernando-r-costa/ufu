#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen ("arq.txt", "r");
    if (fp == NULL) {
        printf("Erro");
        exit(1);
    }
    
    char str[150];
    
    // printf("Digite um texto: ");
    // fgets(str, 150, stdin);
    
    // fputs(str, fp);
    
    while (fgets(str, 150, fp) != NULL) {
        printf("%s", str);
    }
    
    fclose(fp);
    
    return 0;
}