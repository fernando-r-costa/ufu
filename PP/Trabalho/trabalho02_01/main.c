/* Autores:
    Fernando Rodrigues Costa
    Orlando Luiz de Carvalho Topam
    Vinícius Albino Torres Lima
*/

#include <stdio.h>

int main()
{
    char str[256];
    scanf("%256[^\n]", &str);
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + 3) %26 + 'a';
            
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + 3) %26 + 'A';
        }
    }
    
    printf("%s", str);
}