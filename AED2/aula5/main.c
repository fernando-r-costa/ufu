/*
Pratica Grafo
Aluno: Fernando Rodrigues Costa - 12521BCC029
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    int peso;
    struct No *prox;
} No;

typedef struct {
    No **lista;
    int quantidadeVertices;
} Grafo;

/*
Atividade 1 - Construcao do Grafo
*/
void adicionarAresta(Grafo *g, int origem, int destino, int peso) {
    No *novo = malloc(sizeof(No));

    novo->destino = destino;
    novo->peso = peso;
    novo->prox = g->lista[origem];
    g->lista[origem] = novo;
}

/*
 Perguntas
 1. Qual a complexidade da insercao?
 O(1)
 2. Qual a vantagem da lista de adjacencia sobre matriz de adjacencia?
 A lista de adjacencia e vantajosa quando ha poucas arestas entre os
 vertices, pois economiza memoria.
 3. Quando a matriz de adjacencia pode ser mais vantajosa?
 A matriz e mais vantajosa quando existem muitas arestas entre os vertices
 e e mais rapida para consultar se existe uma aresta entre dois vertices.
*/

/*
Atividade 2 - Busca em Profundidade (DFS)
*/
void DFS(Grafo *g, int v, int visitado[]) {
    visitado[v] = 1;
    printf("%d ", v);

    No *aux = g->lista[v];
    while (aux != NULL) {
        if (!visitado[aux->destino]) {
            DFS(g, aux->destino, visitado);
        }
        aux = aux->prox;
    }
}

/*
Perguntas
1. Qual estrutura implicita e utilizada pela DFS?
Pilha.
2. A DFS encontra sempre o menor caminho?
Nao, ela explora um caminho ate sua profundidade maxima antes de
retroceder, podendo encontrar um caminho mais longo mesmo que exista outro
mais curto.
3. Cite duas aplicacoes da DFS.
Pode ser utilizada para detectar ciclos em grafos e identificar componentes
conexos.
*/

/*
Atividade 3 - Busca em Largura (BFS)
 */
void BFS(Grafo *g, int origem) {
    int fila[100];
    int inicio = 0;
    int fim = 0;
    int visitado[100] = {0};

    fila[fim++] = origem;
    visitado[origem] = 1;

    while (inicio < fim) {
        int v = fila[inicio++];
        printf("%d ", v);

        No *aux = g->lista[v];
        while (aux != NULL) {
            if (!visitado[aux->destino]) {
                visitado[aux->destino] = 1;
                fila[fim++] = aux->destino;
            }
            aux = aux->prox;
        }
    }
}

/*
Perguntas
1. Qual estrutura e essencial para BFS?
A fila, porque o primeiro elemento que entra deve ser o primeiro a sair,
seguindo a politica FIFO.
2. BFS encontra o menor caminho em grafos sem peso?
Sim. A BFS percorre o grafo por niveis, garantindo que os vertices mais
proximos sejam visitados primeiro e, assim, encontrando o menor caminho em
quantidade de arestas.
3. Compare BFS e DFS.
A BFS utiliza uma fila e percorre o grafo por niveis, garantindo o menor
caminho em grafos sem peso. Ja a DFS utiliza uma pilha, explorando os
caminhos em profundidade antes de retroceder, sem garantir o menor caminho.
Ambas possuem complexidade de tempo O(V + E), considerando a representacao
por listas de adjacencia.
*/

/*
Atividade 4 - Ordenacao Topologica
*/
void topoDFS(Grafo *g, int v, int visitado[], int pilha[], int *topo) {
    visitado[v] = 1;

    No *aux = g->lista[v];
    while (aux != NULL) {
        if (!visitado[aux->destino]) {
            topoDFS(g, aux->destino, visitado, pilha, topo);
        }
        aux = aux->prox;
    }

    pilha[(*topo)++] = v;
}

/*
Perguntas
1. Em quais grafos a ordenacao topologica pode ser aplicada?
A ordenacao topologica pode ser aplicada em grafos direcionados aciclicos
(DAG), ou seja, grafos que possuem arestas com direcao e nao apresentam
ciclos.
2. O que acontece se existir ciclo?
Se existir um ciclo, nao e possivel realizar uma ordenacao topologica
valida, pois havera dependencias circulares entre os vertices, impedindo
uma sequencia que respeite todas as dependencias.
3. Cite uma aplicacao pratica.
Uma aplicacao pratica e o gerenciamento de dependencias na compilacao de
programas, determinando a ordem correta em que os modulos devem ser
compilados.
*/

/*
Atividade 5 - Arvore Geradora
Perguntas
1. Quantas arestas possui uma arvore geradora?
Uma arvore geradora possui exatamente V - 1 arestas, sendo V o numero de
vertices do grafo. Portanto, nesse grafo temos 3.
2. Apresente uma arvore geradora valida.
Uma arvore geradora valida e formada pelas arestas (0,1), (0,2) e (2,3),
pois conecta todos os quatro vertices do grafo, possui V - 1 = 3 arestas
e nao apresenta ciclos.
3. O conjunto abaixo e uma arvore geradora?
Sim, pois e formado por 3 arestas, conecta todos os quatro vertices do
grafo e nao apresenta ciclos.
*/