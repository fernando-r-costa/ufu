#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    char str2[50];
    
    printf("Digite a primeira string: ");
    fgets(str1, 50, stdin);
    printf("Digite a segunda string: ");
    fgets(str2, 50, stdin);
    
    if (strcmp(str1, str2) == 0) {
        printf("As duas strings são iguais. \n");
    } else if(strcmp(str1, str2) < 0) {
        printf("A primeira string é menor que a segunda. \n");
    } else {
        printf("A primeira string é maior que a segunda. \n");
    }
    
    return 0;
}