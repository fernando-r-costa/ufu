#ifndef _LISTA_H
#define _LISTA_H

// Estrutura para representar um nó da lista encadeada
typedef struct No {
    int valor; // Valor armazenado no nó
    struct No *prox; // Ponteiro para o próximo nó
} No;
 
 
// Estrutura para o nó descritor
typedef struct {
    No *inicio; // Ponteiro para o início da lista
    No *fim; // Ponteiro para o final da lista
    int quantidade; // Quantidade de elementos na lista
} Descritor;

void inicializarLista(Descritor *lista);
int listaVazia(Descritor *lista);
void adicionarNoInicio(Descritor *lista, int valor);
void adicionarNoFinal(Descritor *lista, int valor);
void removerDoInicio(Descritor *lista);
void removerDoFinal(Descritor *lista);
void removerElemento(Descritor *lista, int elemento);
void exibirLista(Descritor *lista);


#endif