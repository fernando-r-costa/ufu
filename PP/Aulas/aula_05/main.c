#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[100];
    int cont_string = 0;
    int cont_vogais = 0;
    int cont_consoantes = 0;
    char string_caixa_alta[100];
    char string_caixa_baixa[100];
    //int cont = -1;

    printf("Digite uma string: ");
    scanf("%[^\n]", string);

    for (int i=0; i<100; i++) {

        if(string[i]>=97 && string[i]<=122) {
            string_caixa_alta[i] = string[i] - 32;
        } else {
            string_caixa_alta[i] = string[i];
        }

        if(string[i]>=65 && string[i]<=90) {
            string_caixa_baixa[i] = string[i] + 32;
        } else {
            string_caixa_baixa[i] = string[i];
        }

        if(string[i] == '\0') {
            break;
        } else if(string[i] == ' ') {
            continue;
        } else if(string[i] == 'a' || string[i] == 'A' ||
                  string[i] == 'e' || string[i] == 'E' ||
                  string[i] == 'i' || string[i] == 'I' ||
                  string[i] == 'o' || string[i] == 'O' ||
                  string[i] == 'u' || string[i] == 'U') {
            cont_vogais++;
            cont_string++;
        } else if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122)) {
            cont_consoantes++;
            cont_string++;
        }  else {
            cont_string++;
        }
    }

    /*while (string[++cont] != '\0');*/

    printf("String: %s\n", string);
    printf("Comprimento da string: %d\n", cont_string);
    printf("Qte vogais: %d\n", cont_vogais);
    printf("Qte consoantes: %d\n", cont_consoantes);
    printf("String caixa alta: %s\n", string_caixa_alta);
    printf("String caixa baixa: %s\n", string_caixa_baixa);

    return 0;
}
