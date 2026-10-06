#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

// Função auxiliar para copiar vetores, garantindo que todos os algoritmos ordenam os mesmos dados
void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int tamanhos[] = {1000, 5000, 10000}; // Tamanhos definidos na atividade
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    srand(time(NULL));

    printf("Resultados da Avaliacao de Desempenho (em segundos):\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("%-10s | %-12s | %-14s | %-14s | %-10s | %-10s\n", "Tamanho", "Bubble", "Selection", "Insertion", "Quick", "Merge");
    printf("--------------------------------------------------------------------------------\n");

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int *v_original = (int*)malloc(n * sizeof(int));
        int *v_teste = (int*)malloc(n * sizeof(int));
        
        // Preenche o vetor original com números aleatórios
        for (int i = 0; i < n; i++) {
            v_original[i] = rand() % 100000;
        }

        clock_t inicio, fim;
        double tempo_bubble, tempo_selection, tempo_insertion, tempo_quick, tempo_merge;

        // Bubble Sort
        copiarVetor(v_original, v_teste, n);
        inicio = clock();
        bubbleSortOtimizado(v_teste, n);
        fim = clock();
        tempo_bubble = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Selection Sort
        copiarVetor(v_original, v_teste, n);
        inicio = clock();
        selectionSort(v_teste, n);
        fim = clock();
        tempo_selection = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Insertion Sort
        copiarVetor(v_original, v_teste, n);
        inicio = clock();
        insertionSort(v_teste, n);
        fim = clock();
        tempo_insertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Quick Sort
        copiarVetor(v_original, v_teste, n);
        inicio = clock();
        quickSort(v_teste, 0, n - 1);
        fim = clock();
        tempo_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Merge Sort
        copiarVetor(v_original, v_teste, n);
        inicio = clock();
        mergeSort(v_teste, 0, n - 1);
        fim = clock();
        tempo_merge = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("%-10d | %-12.6f | %-14.6f | %-14.6f | %-10.6f | %-10.6f\n", 
               n, tempo_bubble, tempo_selection, tempo_insertion, tempo_quick, tempo_merge);

        free(v_original);
        free(v_teste);
    }
    printf("--------------------------------------------------------------------------------\n");

    return 0;
}