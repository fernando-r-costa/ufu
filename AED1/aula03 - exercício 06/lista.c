#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void iniciar(Lista *l, int capacidade) {
    l->livros = (Livro *) malloc(capacidade * sizeof(Livro));
    l->uso = 0;
    l->capacidade = capacidade;
}

int inserir(Lista *l, Livro livro) {
    
    if(l->uso >= l->capacidade) {
        l->capacidade++;
        l->livros = (Livro *) realloc(l->livros, l->capacidade * sizeof(Livro));
    }
    
    if(l->livros == NULL) {
        printf("Falha ao alocar memoria");
        return 0;
    }
    
    l->livros[l->uso] = livro;
    l->uso++;
    
    return 1;
}

int remover(Lista *l, char *titulo) {
    
    for(int i = 0; i < l->uso; i++) {
        
        if(strcmp(l->livros[i].titulo, titulo) == 0) {
            
            for(int j = i; j < l->uso; j++ ) {
                l->livros[j] = l->livros[j+1];
            }
            
            l->uso--;
            
            return 1;
        }
    }
    
    return 0;
    
}

void exibir(Lista *l) {
    
    printf("\n\n--- Lista dos Livros ---\n");
    
    for(int i = 0; i < l->uso; i++) {
        
        printf("Título: %s\n", l->livros[i].titulo);
        printf("Autor: %s\n", l->livros[i].autor);
        printf("Ano: %d\n", l->livros[i].ano);
        printf("Preço: %.2f\n\n", l->livros[i].preco);
    }
}

void liberar(Lista *l) {
    free(l->livros);
    
    l->livros = NULL;
    l->uso = 0;
    l->capacidade = 0;
}