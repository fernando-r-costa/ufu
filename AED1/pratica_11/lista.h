#ifndef _LISTA_H
#define _LISTA_H

typedef struct No No;

void inserirInicio(No** cabeca, int id);
void removerNo(No** cabeca, No* alvo);
void imprimirFrente(No* cabeca);
void imprimirTras(No* cabeca);
int escolherLider(No** cabeca, int k);

#endif