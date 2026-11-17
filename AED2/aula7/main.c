#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição do nó
typedef struct No {
    int info;
    struct No* esq;
    struct No* dir;
} No;

// TAD da árvore
typedef No* ArvBin;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return NULL;
    }

    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}


//Percursos recursivos
void preOrdem(No** raiz) {
    if(*raiz == NULL) {
        return;
    }

    printf("%d ", (*raiz)->info);
    preOrdem(&((*raiz)->esq));
    preOrdem(&((*raiz)->dir));
}

void emOrdem(No** raiz) {
    if(*raiz == NULL) {
        return;
    }

    emOrdem(&((*raiz)->esq));
    printf("%d ", (*raiz)->info);
    emOrdem(&((*raiz)->dir));
}

void posOrdem(No** raiz) {
    if(*raiz == NULL) {
        return;
    }

    posOrdem(&((*raiz)->esq));
    posOrdem(&((*raiz)->dir));
    printf("%d ", (*raiz)->info);
}

//Funções auxiliares
int contarNos(No** raiz) {
    if (*raiz == NULL) {
        return 0;
    }

    int total = 1 + contarNos(&((*raiz)->esq)) + contarNos(&((*raiz)->dir));

    return total;
}

int altura(No** raiz) {
    if (*raiz == NULL) {
        return 0;
    }

    int alturaEsq = 1 + altura(&((*raiz)->esq));
    int alturaDir = 1 + altura(&((*raiz)->dir));

    if (alturaEsq < alturaDir) {
        return alturaDir;
    } else {
        return alturaEsq;
    }
}

void inserirABB(No** raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = criarNo(valor);
        return;
    }

    if (valor < (*raiz)->info) {
        inserirABB(&((*raiz)->esq), valor);
    } else if (valor > (*raiz)->info) {
        inserirABB(&((*raiz)->dir), valor);
    }
}

bool buscarABB(No** raiz, int alvo) {
    if (*raiz == NULL) {
        return false;
    }

    if (alvo == (*raiz)->info) {
        return true;
    } else if (alvo < (*raiz)->info) {
        return buscarABB(&((*raiz)->esq), alvo);
    } else {
        return buscarABB(&((*raiz)->dir), alvo);
    }
}

// Função para liberar toda a memória da árvore (pós-ordem)
void liberarArvore(No** raiz) {
    if (*raiz == NULL) {
        return;
    }

    liberarArvore(&((*raiz)->esq));
    liberarArvore(&((*raiz)->dir));
    
    free(*raiz);
    *raiz = NULL;
}

// Função principal
int main() {
    ArvBin raiz = criarNo(10);

    raiz->esq = criarNo(5);
    raiz->dir = criarNo(15);

    raiz->esq->esq = criarNo(3);
    raiz->esq->dir = criarNo(7);
    raiz->dir->dir = criarNo(20);

    printf("Pre-ordem: ");
    preOrdem(&raiz);

    printf("\nEm-ordem: ");
    emOrdem(&raiz);

    printf("\nPos-ordem: ");
    posOrdem(&raiz);

    printf("\nTotal de nos: %d\n", contarNos(&raiz));
    printf("Altura: %d\n", altura(&raiz));

    printf("\n");

    ArvBin raizABB = NULL;
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        inserirABB(&raizABB, valores[i]);
    }
    
    printf("Em-ordem da ABB: ");
    emOrdem(&raizABB);
    
    // Deve imprimir em ordem crescente
    printf("\n");
    printf("Buscar 45: %s\n", buscarABB(&raizABB, 45) ? "Sim" : "Nao");
    printf("Buscar 100: %s\n", buscarABB(&raizABB, 100) ? "Sim" : "Nao");
    
    liberarArvore(&raiz);
    liberarArvore(&raizABB);

    return 0;
}

// Atividade 1 - Perguntas
// 1. Qual a principal aplicação prática do percurso em-ordem em uma ABB?
// É percorrer e apresentar seus elementos em ordem crescente, aproveitando a propriedade de ordenação da árvore.
// 2. Por que os percursos recursivos são naturalmente adequados para árvores?
// Porque elas possuem uma estrutura hierárquica e recursiva, na qual cada nó pode ser considerado a raiz de uma subárvore.
// Assim, podemos aplicar a mesma função às subárvores esquerda e direita, utilizando a pilha de chamadas para controlar os retornos até que todos os nós sejam visitados.
// 3. O que aconteceria se chamássemos preOrdem(NULL)? Como evitar problemas?
// Podemos provocar uma falha de segmentação, pois a função recebe um ponteiro duplo e tenta desreferenciá-lo. 
// Para evitar o problema, devemos verificar se raiz ou *raiz é NULL antes de acessar os dados do nó.


// ATIVIDADE 2 - PERGUNTAS
// 1. Por que em uma ABB o percurso em-ordem resulta em valores ordenados?
// Porque a ABB mantém os valores menores à esquerda e os maiores à direita de cada nó.
// Como o percurso em-ordem visita primeiro a esquerda, depois a raiz e por último a direita,
// os valores são apresentados em ordem crescente.
// 2. Qual a complexidade de tempo da inserção e busca no pior caso? E no caso médio?
// Caso médio: O(log n) para inserção e busca.
// Pior caso: O(n) para inserção e busca.
// No caso médio, considerando uma árvore com altura aproximadamente logarítmica, as operações percorrem poucos níveis.
// No pior caso, a árvore pode ficar degenerada, semelhante a uma lista encadeada, exigindo percorrer até n nós.
// 3. Insira manualmente os valores 1, 2, 3, 4 e 5, nessa ordem, em uma ABB. Isso é problemático? Por quê?
// A árvore resultante será:
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
// Sim, é problemático porque os valores são inseridos em ordem crescente, fazendo com que todos os nós fiquem à direita.
// A árvore fica degenerada, semelhante a uma lista encadeada, e as operações de busca e inserção podem atingir complexidade O(n), perdendo a eficiência de uma árvore com altura logarítmica.