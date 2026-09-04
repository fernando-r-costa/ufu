#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    struct elemento *ant;
    int dados;
    struct elemento *prox;
} Elem;
    
typedef Elem* Lista;

Lista* criaLista() {
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));
        
    if(novaLista != NULL) {
        *novaLista = NULL;
    }
    
    return novaLista;
}
    
Elem* criarElem (int valor) {
    Elem* novoElem = (Elem*) malloc(sizeof(Elem));
        
    if (novoElem == NULL) return NULL;
        
    novoElem->dados = valor;
    novoElem->prox = novoElem->ant = NULL;
    return novoElem;
        
}
    
void insereInicio (Lista *lista, int v) {
    Elem *novo = criarElem(v);
    if (novo == NULL) return;
    
    novo->prox = *lista;
    novo->ant = NULL;
    
    if (*lista != NULL) {
        (*lista)->ant = novo;
    }
        
    *lista = novo;
}

void imprimeLista(Lista *lista) {
    Elem *atual = *lista;
    while(atual != NULL) {
        printf("%d ", atual->dados);
        atual = atual->prox;
    }
    printf("\n");
}

void concatenaInicio(Lista *listaA, Lista *listaB) {
    while(*listaA != NULL) {
        Elem *atual = *listaA;
    }
    
    *listaA = (*listaA)->prox;
    if(*listaA != NULL) {
        (*listaA)->ant
    }
}

int main()
{
    Lista *listaA = criaLista();
    Lista *listaB = criaLista();
    
    // Lista A = {1, 2, 3}
    insereInicio(listaA, 3);
    insereInicio(listaA, 2);
    insereInicio(listaA, 1);
    
    // Lista B = {4, 6, 8}
    insereInicio(listaB, 8);
    insereInicio(listaB, 6);
    insereInicio(listaB, 4);
    
    printf("--- Antes ---\n");
    printf("Lista A: "); imprimeLista(listaA);
    printf("Lista B: "); imprimeLista(listaB);
    

    return 0;
}