#include <stdio.h>

int main()
{
    struct Pessoa {
        char nome[150];
        int idade;
        char endereco[250];
    };
    
    int qte;
    
    printf("Deseja fazer quantos cadastros: \n");
    scanf("%d", &qte);
    
    setbuf(stdin, NULL);
    
    struct Pessoa pessoa[qte]; 
    
    for (int i = 0; i < qte; i++) {
        printf("Digite os dados da pessoa %d: \n", i+1);
        printf("Nome: ");
        fgets(pessoa[i].nome, 150, stdin);
        printf("Idade: ");
        scanf("%d", &pessoa[i].idade);
        setbuf(stdin, NULL);
        printf("Endereco: ");
        fgets(pessoa[i].endereco, 250, stdin);
    }
    
    for (int i = 0; i < qte; i++) {
        printf("\nNome %d: %s", i+1, pessoa[i].nome);
        printf("Idade %d: %d\n", i+1, pessoa[i].idade);
        printf("Endereco %d: %s\n", i+1, pessoa[i].endereco);
    }

    return 0;
}
