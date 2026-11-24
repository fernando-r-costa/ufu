#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        //printf("========================\n");
        //printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
        //printf("\n\nres = %d\n",res);
        //preOrdem_ArvAVL(avl);
        //printf("\n\n");
    }

    // Teste da Atividade 1 - Busca com altura
    printf("\nAltura do no 10: %d\n", buscarAltura_ArvAVL(avl, 10));
    printf("Altura do no 5: %d\n", buscarAltura_ArvAVL(avl, 5));
    printf("Altura do no 99: %d\n", buscarAltura_ArvAVL(avl, 99));

    // Teste da Atividade 2 - Verificacao de AVL
    printf("\nA arvore eh AVL? %s\n", ehAVL(avl) ? "Sim" : "Nao");

    // Teste da Atividade 3 - Impressao grafica
    printf("\nEstrutura da AVL:\n");
    imprimirArvore(avl, 0);
    
//
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");
//
//    int NR = 4, dadosR[4] = {7,51,3,5};
//    for(i=0;i<NR;i++){
//        printf("\nRemovendo: %d\n",dadosR[i]);
//        res = remove_ArvAVL(avl,dadosR[i]);
//        printf("\n\nres = %d\n",res);
//        preOrdem_ArvAVL(avl);
//        //printf("\n\n");
//    }
//
//    printf("\nAVL tree:\n");
//    preOrdem_ArvAVL(avl);
//    printf("\n\n");

    remove_ArvAVL(avl,6);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,7);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,4);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    libera_ArvAVL(avl);


    return 0;
}

// Questão 1
// 1) info: é o dado armazenado
// altura: Armazena a altura da subárvore cuja raiz é esse nó, é utilizada para fazer o balanceamento
// *esq: aponta para o nó da arvore esquerda
// *dir: aponta para o nó da arvore direita
// 2) FB = altura(esquerda) - altura(direita)
// FB = 2 - 1 = 1
// Admite:
// -1: subárvore direita mais alta.
// 0: subárvores com alturas iguais.
// +1: subárvore esquerda mais alta.
// 3) LL é aplicado quando o desbalanceamento ocorre pela esquerda do filho esquerdo.
// LR é aplicado quando o desbalanceamento ocorreu pela direita do filho esquerdo.

// Questão 2
// Inserção    Rotação realizada
// 10          Nenhuma
// 20      	Nenhuma
// 30	        RR — rotação simples à esquerda
// 15	        Nenhuma
// 25	        Nenhuma
// 5	        Nenhuma