#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50];
    
    printf("Digite uma string: ");
    fgets(str1, 50, stdin);
    
    int count = 0;
    int tamanho_str = strlen(str1);
        
    for(int i = 0; i < tamanho_str; i++){
        
        if (str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U') {
            count++;
        } else if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u') {
            count++;
        } 
        
    }
    
    printf("A qte de vogais é: %d", count);
    
    return 0;
}

