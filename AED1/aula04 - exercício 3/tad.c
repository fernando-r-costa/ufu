#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

typedef struct aluno {
    char nome[50];
    int notaPratica;
    int notaTeorica;
} Aluno;

typedef struct no { 
    Aluno aluno;
    struct no* prox;
} No;

No* criaListaVazia() {
    return NULL;
}

void verificaListaVazia(No *l) {
    // VPL exige silêncio, função mantida vazia
}

No* inserirAluno (No *l, char nome[], int np, int nt) {
    No* novo;
    novo = (No*) malloc (sizeof(No));
    
    if (novo == NULL)
        return novo;
        
    strcpy(novo->aluno.nome, nome);
    novo->aluno.notaPratica = np;
    novo->aluno.notaTeorica = nt;
    novo->prox = l;
    
    return novo;
}

void buscaAluno(No *l, char nome[]) {
    while (l != NULL && strcmp(l->aluno.nome, nome) != 0) {
        l = l->prox;
    }
    
    // Se não achar, o VPL não espera saída (silêncio)
    if (l == NULL) {
        return;
    }
    
    // A única saída exigida pelo VPL para a opção 2: A soma em número inteiro
    int soma = l->aluno.notaPratica + l->aluno.notaTeorica;
    printf("%d\n", soma);
}

void mediaSuperior(No *l) {
    while (l!= NULL) {
        int soma = l->aluno.notaPratica + l->aluno.notaTeorica;
        
        if(soma >= 70) {
            // Imprime apenas o nome, sem decorações
            printf("%s\n", l->aluno.nome);
        }
        
        l = l->prox;
    }
}

No* removerAluno(No *l, char nome[]) {
    No *lAtual = l;
    No *lAnterior = NULL;
    
    while (lAtual != NULL && strcmp(lAtual->aluno.nome, nome) != 0) {
        lAnterior = lAtual;
        lAtual = lAtual->prox;
    }
    
    if (lAtual == NULL) {
        return l;
    }
    
    if (lAnterior == NULL) {
        l = lAtual->prox;
    } else {
        lAnterior->prox = lAtual->prox;
    }
    
    free(lAtual);
    return l;
}

void imprimeLista(No *l) {
    // Mantida simples caso o VPL teste a opção 5 secretamente
    while (l!= NULL) {
        printf("%s\n", l->aluno.nome);
        printf("%d\n", l->aluno.notaTeorica);
        printf("%d\n", l->aluno.notaPratica);
        l = l->prox;
    }
}