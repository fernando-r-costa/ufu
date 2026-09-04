#ifndef _LISTA_H
#define _LISTA_H

typedef struct { 
    char titulo[30];
    char autor[30];
    int ano;
    float preco;
} Livro;

typedef struct {
    Livro *livros;
    int uso;
    int capacidade;
} Lista;

void iniciar(Lista *l, int capacidade);

int inserir(Lista *l, Livro livro);

int remover(Lista *l, char *titulo);

void exibir(Lista *l);

void liberar(Lista *l);

#endif