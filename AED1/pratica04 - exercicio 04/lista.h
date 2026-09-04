#ifndef _LISTA_H
#define _LISTA_H

//produto
struct produto{
  int codProd;        //código do produto
  char nomeProd[10];  //nome do produto
  float valor;        //valor do produto
  int qtdeEstoque;    //quantidade disponível em estoque
};

//lista
struct lista {
    struct produto *info;
    int capacidade;
    int quantidade;
};
typedef struct lista Lista;


Lista* criarLista(int capacidade); //passagem por valor(cópia do número)

void inserirProduto(Lista* l, struct produto novo); //l: passagem por referência(ponteiro) | novo: passagem por valor(cópia do struct produto)

struct produto buscaPrecoMenor(Lista* l); //l: passagem por referência(ponteiro)

void venda(Lista* l, int codProd, int qtdVendida); //l: passagem por referência(ponteiro) | codProd e qtdVendida: passagem por valor (cópias dos números)

#endif