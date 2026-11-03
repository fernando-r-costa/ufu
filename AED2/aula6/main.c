/*
Pratica Grafo - continuação
Aluno: Fernando Rodrigues Costa - 12521BCC029
*/

#include <stdio.h>
#include <stdlib.h>

// Atividade 6 – Prim (Árvore Geradora Mínima)
int extrairMinimoPrim(int chave[], int visitado[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++)
        if (!visitado[i] && chave[i] < min) {
            min = chave[i];
            min_index = i;
        }

    return min_index;
}

for (i = 0; i < V - 1; i++) {
    int u = extrairMinimoPrim(chave, visitado, V);

    visitado[u] = 1;

    No *aux = g->lista[u];

    while (aux) {
        int v = aux->destino;

        if (!visitado[v] && aux->peso < chave[v]) {
            chave[v] = aux->peso;
            pai[v] = u;
        }

        aux = aux->prox;
    }
}

/*
Perguntas
1. Qual o objetivo de Prim?
Conectar todos os vértices do grafo com o menor custo total possível, sem formar ciclos.
2. Prim funciona em grafos desconexos?
Não. O algoritmo de Prim precisa de um grafo conexo para construir uma árvore geradora mínima que inclua todos os vértices.
3. Diferença entre árvore geradora e AGM.
Uma árvore geradora conecta todos os vértices sem formar ciclos. Já uma AGM é a árvore geradora que possui o menor custo total possível, considerando os pesos das arestas.
*/

// Atividade 7 – Dijkstra
int extrairMinimoDijkstra(int dist[], int visitado[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++)
        if (!visitado[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }

    return min_index;
}

for(i=0;i<V;i++){
    int u = extrairMinimoDijkstra(dist, visitado, V);
    visitado[u] = 1;
    No *aux = g->lista[u];

    while(aux){
        int v = aux->destino;
        if(dist[u] + aux->peso < dist[v]){
            dist[v] = dist[u] + aux->peso;
        }
        aux = aux->prox;
    }
}

/*
Perguntas
1. Qual restrição existe para os pesos?
O algoritmo de Dijkstra não admite pesos negativos nas arestas.
2. Qual vetor armazena os menores custos?
O vetor dist[].
3. Dijkstra produz uma árvore?
Sim. Dijkstra pode produzir uma árvore de caminhos mínimos a partir do vértice de origem, desde que sejam registrados os predecessores dos vértices.
*/

// Atividade 8 – Análise de Execução (Passo a Passo)
/*
Iteração Vértice escolhido Distâncias
Iteração    | Vértice escolhido | Distâncias [0, 1, 2, 3]
Inicial     | -                 | [0, ∞, ∞, ∞]
1           | 0                 | [0, 2, 4, ∞]
2           |1                  | [0, 2, 3, ∞]
3           |2                  | [0, 2, 3, 6]
Final       |3                  | [0, 2, 3, 6]

Perguntas
1. Qual o menor caminho de 0 para 3?
0 -> 1 -> 2 -> 3
2. Qual o custo total?
6
3. Qual seria o resultado de uma BFS a partir de 0?
A BFS percorre o grafo por níveis a partir do vértice 0, sem considerar os pesos das arestas. Portanto, seus caminhos podem ser diferentes dos encontrados por Dijkstra.
*/

// Atividade 9 – Complexidade
/*
Complete:
Algoritmo Complexidade
DFS - O(V + E)
BFS - O(V + E)
Ordenação topológica - O(V + E)
Prim - O(V²)
Dijkstra - O(V²)
*/

// Atividade 10 – Questão Integrada
/*
Considere um sistema de navegação urbana.
Explique:
1. Onde utilizar DFS?
A DFS pode ser utilizada para explorar as conexões entre ruas e verificar se existe um caminho entre dois locais da cidade.
2. Onde utilizar BFS?
A BFS pode ser utilizada para encontrar o caminho com o menor número de ruas (arestas) entre dois locais, sem considerar as distâncias ou os custos das ruas.
3. Onde utilizar Prim?
Prim pode ser utilizado para planejar uma rede de infraestrutura urbana, como cabos de comunicação, conectando todos os pontos com o menor custo total possível, sem formar ciclos.
4. Onde utilizar Dijkstra?
Dijkstra pode ser utilizado para encontrar o trajeto de menor custo entre dois locais, considerando pesos não negativos nas ruas, como distância ou tempo de deslocamento.
5. Qual algoritmo seria utilizado para definir a ordem de execução de tarefas dependentes?
A ordenação topológica, pois organiza as tarefas respeitando suas dependências, garantindo que cada tarefa seja executada somente depois das tarefas das quais depende. Isso exige que o grafo de dependências seja direcionado e acíclico (DAG).
*/