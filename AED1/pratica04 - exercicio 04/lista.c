#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//cria a lista | capacidade: passagem por valor
Lista* criarLista(int capacidade) {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->capacidade = capacidade;
    l->quantidade = 0;
    l->info = (struct produto*) malloc(capacidade * sizeof(struct produto));
    return l;
}

//insere um produto | l: passagem por referência | novo: passagem por valor
void inserirProduto(Lista* l, struct produto novo) {
    if (l->quantidade < l->capacidade) {
        l->info[l->quantidade] = novo;
        l->quantidade++;
    }
}

//busca o menor preço | l: passagem por referência
struct produto buscaPrecoMenor(Lista* l) {
    int menor = 0;
    for (int i = 1; i < l->quantidade; i++) {
        if (l->info[i].valor < l->info[menor].valor) {
            menor = i;
        }
    }
    return l->info[menor];
}

//realiza uma venda | l: passagem por referência | codProduto e qtdVendida: passagem por valor
void venda (Lista* l, int codProduto, int qtdVendida) {
    for (int i = 0; i < l->quantidade; i++) {
        if (l->info[i].codProd == codProduto) {
            if (l->info[i].qtdeEstoque >= qtdVendida) {
                l->info[i].qtdeEstoque -= qtdVendida;
                printf("Venda concluída. Estoque: %s - %d un", l->info[i].nomeProd, l->info[i]. qtdeEstoque);
            } else {
                printf("Venda não concluída, estoque insuficiente!");
            }
            return;
        }
    }
    printf("Código não encontrado!");
}