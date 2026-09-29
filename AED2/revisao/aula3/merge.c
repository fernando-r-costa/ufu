#include "sorts.h"
#include <stdlib.h>

void merge(int v[], int inicio, int meio, int fim){
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int *temp = (int*)malloc((fim - inicio + 1) * sizeof(int)); 
    
    while(i <= meio && j <= fim){
        if(v[i] < v[j]){
            temp[k++] = v[i++];
        }else{
            temp[k++] = v[j++];
        }
    }
    while(i <= meio){
        temp[k++] = v[i++];
    }
    while(j <= fim){
        temp[k++] = v[j++];
    }
    for(i = inicio, k = 0; i <= fim; i++, k++){
        v[i] = temp[k];
    }
    free(temp);
}

void mergeSort(int v[], int inicio, int fim){
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}