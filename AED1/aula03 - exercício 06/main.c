#include <stdio.h>
#include "lista.h"

int main() {
    
    int capacidade = 0;
    Lista lista;
    
    printf("Informe a capacidade da lista de livros: ");
    scanf("%d", &capacidade);
    
    iniciar(&lista, capacidade);
    
    // Livro livro = {
    //     .titulo = "Teste do primeiro livro",
    //     .autor = "Autor do primeiro livro",
    //     .ano = 2001,
    //     .preco = 50.90
    // };
    
    int opcao = -1;
    
    while(opcao != 0) {
        printf("\n--- Escolha uma opção: ---\n");
        printf("1 - Inserir um livro\n");
        printf("2 - Remover um livro\n");
        printf("3 - Imprimir a lista\n");
        printf("0 - Sair\n");
        printf(">> ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            
            case 1:
                Livro livro;
                
                printf("\n\n--- Inserir Livro ---\n");
                printf("Título: ");
                scanf(" %[^\n]", livro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]", livro.autor);
                printf("Ano: ");
                scanf("%d", &livro.ano);
                printf("Preço: ");
                scanf("%f", &livro.preco);
                
                inserir(&lista, livro);
                exibir(&lista);
                
                break;
            
            case 2:
                char titulo[30];
                
                printf("\n\n --- Remover Livro ---\n");
                printf("Título: ");
                scanf(" %[^\n]", titulo);
                
                remover(&lista, titulo);
                exibir(&lista);
                
                break;
                
            case 3:
                exibir(&lista);
                
                break;
                
            case 0:
                printf("Saindo ...\n");
                
                break;
        }
    }
    
    
    liberar(&lista);
    
    exibir(&lista);
    
    return 0;
}