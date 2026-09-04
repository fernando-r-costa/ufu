#include <stdio.h>
#include <string.h>

int main()
{
    char str1[150];
    char str2[150];
    
    printf("Digite uma string: ");
    fgets(str1, 150, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    int tamanho_str = strlen(str1);
        
    for (int i = 0; i < tamanho_str; i++){
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str2[i] = (str1[i] - 'A' + 3) % 26 + 'A';
         } else if (str1[i] >= 'a' && str1[i] <= 'z') {
            str2[i] = (str1[i] - 'a' + 3) % 26 + 'a';
         } else {
            str2[i] = str1[i];
         }
    };
    
    str2[tamanho_str] = '\0';
    
    printf("str2: %s", str2);
    
    return 0;
}

