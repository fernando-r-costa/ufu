#include <stdio.h>

int main() {
    
    typedef struct Endereco {
        char logradouro[100];
        int numero;
    } endereco;
    
    typedef struct Pessoa {
        char nome[50];
        int idade;
        endereco end;
    } pessoa;
    
    pessoa p[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome %d: ", i+1);
        setbuf(stdin, NULL);
        scanf("%[^\n]", p[i].nome);
        printf("Digite a idade: ");
        setbuf(stdin, NULL);
        scanf("%d", &p[i].idade);
        printf("Digite o logradouro: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", p[i].end.logradouro);
        printf("Digite o número: ");
        setbuf(stdin, NULL);
        scanf("%d", &p[i].end.numero);
        printf("%s cadastro realizado!\n\n", p[i].nome);
    }
    
    
    printf("\n% Lista de Cadastro: \n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s", p[i].nome);
        printf(" - Idade: %d\n", p[i].idade);
        printf("Endereço: %s, %d\n", p[i].end.logradouro, p[i].end.numero);
    }

    return 0;
}