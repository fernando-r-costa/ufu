
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

// Percursos recursivos
void preOrdem(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    printf("%d ", (*raiz)->info);
    preOrdem(&((*raiz)->esq));
    preOrdem(&((*raiz)->dir));
}

void emOrdem(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    emOrdem(&((*raiz)->esq));
    printf("%d ", (*raiz)->info);
    emOrdem(&((*raiz)->dir));
}

void posOrdem(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    posOrdem(&((*raiz)->esq));
    posOrdem(&((*raiz)->dir));
    printf("%d ", (*raiz)->info);
}

// Funções auxiliares
int contarNos(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return 0;
    }

    int total = 1 + contarNos(&((*raiz)->esq))
                  + contarNos(&((*raiz)->dir));

    return total;
}

int altura(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
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

// Inserção em ABB
void inserirABB(No** raiz, int valor) {
    if (raiz == NULL) {
        return;
    }

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

// Busca em ABB
bool buscarABB(No** raiz, int alvo) {
    if (raiz == NULL || *raiz == NULL) {
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

// Liberação da memória da árvore (pós-ordem)
void liberarArvore(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    liberarArvore(&((*raiz)->esq));
    liberarArvore(&((*raiz)->dir));

    free(*raiz);
    *raiz = NULL;
}

// Encontra o menor valor da subárvore
No* menorValor(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return NULL;
    }

    if ((*raiz)->esq == NULL) {
        return *raiz;
    } else {
        return menorValor(&((*raiz)->esq));
    }
}

// NOVA FUNÇÃO - Encontra o maior valor da subárvore
No* maiorValor(No** raiz) {
    if (raiz == NULL || *raiz == NULL) {
        return NULL;
    }

    if ((*raiz)->dir == NULL) {
        return *raiz;
    }

    return maiorValor(&((*raiz)->dir));
}

// Remoção em ABB
void removerABB(No** raiz, int valor) {
    if (raiz == NULL || *raiz == NULL) {
        return;
    }

    if (valor < (*raiz)->info) {
        removerABB(&((*raiz)->esq), valor);
    } else if (valor > (*raiz)->info) {
        removerABB(&((*raiz)->dir), valor);
    } else {

        // Caso 1: nó folha
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            free(*raiz);
            *raiz = NULL;
            return;
        }

        // Caso 2: nó com apenas o filho direito
        else if ((*raiz)->esq == NULL) {
            No* temp = *raiz;
            *raiz = (*raiz)->dir;
            free(temp);
            return;
        }

        // Caso 3: nó com apenas o filho esquerdo
        else if ((*raiz)->dir == NULL) {
            No* temp = *raiz;
            *raiz = (*raiz)->esq;
            free(temp);
            return;
        }

        // Caso 4: nó com dois filhos
        else {
            No* temp = menorValor(&((*raiz)->dir));

            (*raiz)->info = temp->info;

            removerABB(&((*raiz)->dir), temp->info);
        }
    }
}

// NOVA FUNÇÃO AUXILIAR - Validação recursiva dos limites
bool validarABB(No* no, No* minimo, No* maximo) {
    if (no == NULL) {
        return true;
    }

    if (minimo != NULL && no->info <= minimo->info) {
        return false;
    }

    if (maximo != NULL && no->info >= maximo->info) {
        return false;
    }

    return validarABB(no->esq, minimo, no) &&
           validarABB(no->dir, no, maximo);
}

// NOVA FUNÇÃO - Verifica se uma árvore é uma ABB válida
bool verificarABB(No** raiz) {
    if (raiz == NULL) {
        return false;
    }

    return validarABB(*raiz, NULL, NULL);
}

// Função principal
int main() {

    // ATIVIDADE 1 - Construção e percursos
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

    // ATIVIDADE 2 - Inserção e busca
    ArvBin raizABB = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35, 45};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        inserirABB(&raizABB, valores[i]);
    }

    printf("Em-ordem da ABB: ");
    emOrdem(&raizABB);

    printf("\nBuscar 45: %s\n",
           buscarABB(&raizABB, 45) ? "Sim" : "Nao");

    printf("Buscar 100: %s\n",
           buscarABB(&raizABB, 100) ? "Sim" : "Nao");

    // ATIVIDADE 3 - Remoção e funções complementares
    printf("\nABB original: ");
    emOrdem(&raizABB);

    // Teste de maiorValor
    No* maior = maiorValor(&raizABB);

    if (maior != NULL) {
        printf("\nMaior valor da ABB: %d\n", maior->info);
    }

    // Teste do maior valor da subárvore esquerda
    No* maiorEsq = maiorValor(&(raizABB->esq));

    if (maiorEsq != NULL) {
        printf("Maior valor da subarvore esquerda: %d\n",
               maiorEsq->info);
    }

    // Teste de validação da ABB
    printf("ABB valida: %s\n",
           verificarABB(&raizABB) ? "Sim" : "Nao");

    // Remover folha
    removerABB(&raizABB, 20);
    printf("Apos remover 20: ");
    emOrdem(&raizABB);

    // Remover nó com um filho
    removerABB(&raizABB, 30);
    printf("\nApos remover 30: ");
    emOrdem(&raizABB);

    // Remover nó com dois filhos
    removerABB(&raizABB, 50);
    printf("\nApos remover 50: ");
    emOrdem(&raizABB);

    // Verificar se a ABB continua válida
    printf("\nABB continua valida: %s\n",
           verificarABB(&raizABB) ? "Sim" : "Nao");

    // Teste complementar: árvore propositalmente inválida
    ArvBin raizInvalida = criarNo(50);
    raizInvalida->esq = criarNo(30);
    raizInvalida->dir = criarNo(70);
    raizInvalida->esq->dir = criarNo(60);

    printf("Arvore de teste invalida e ABB: %s\n",
           verificarABB(&raizInvalida) ? "Sim" : "Nao");

    // Liberação da memória
    liberarArvore(&raiz);
    liberarArvore(&raizABB);
    liberarArvore(&raizInvalida);

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

// ATIVIDADE 3 - PERGUNTAS
// 1. Por que, no caso de dois filhos, escolhemos o menor da subárvore direita (ou o maior da esquerda)?
// Porque esses valores permitem substituir o nó removido sem violar a propriedade de ordenação da ABB.
// O menor da subárvore direita é o sucessor em ordem, enquanto o maior da esquerda é o antecessor.
// Após copiar o valor escolhido, removemos seu nó original.
// 2. Implemente uma função que encontra o maior valor da subárvore esquerda como alternativa para remoção com dois filhos.
// 3. O que acontece se tentarmos remover um valor que não existe na árvore? A implementação proposta trata isso corretamente?
// A função percorre a ABB comparando o valor procurado com os valores dos nós.
// Se o valor não existir, chegará a um ponteiro NULL e encerrará a execução pelo caso-base.
// A árvore permanecerá inalterada.
// Sim, a implementação trata corretamente essa situação.
// 4. (Bônus) Implemente uma função que verifica se uma árvore binária é uma ABB válida.