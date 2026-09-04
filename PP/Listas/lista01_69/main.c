#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    char str2[50];
    
    printf("Digite uma string: ");
    fgets(str1, 50, stdin);
    
    str1[strcspn(str1, "\n")] = '\0';
    
    int tamanho_str = strlen(str1);
        
    for (int i = 0; i < tamanho_str; i++){
        str2[(tamanho_str - 1) - i] = str1[i];
    };
    
    str2[tamanho_str] = '\0';
    printf("str2: %s\n", str2);
    
    if (strcmp(str1, str2) == 0) {
        printf("A palavra é um palíndrome\n");
    } else {
        printf("A palavra não é um palíndrome\n");
    }
    
    
    return 0;
}

