#include "sorts.h"

int particiona(int v[], int inicio, int fim){
    int pivo = v[fim];
    int i = inicio - 1;
    int j, temp;
    for(j = inicio; j < fim; j++){
        if(v[j] <= pivo){
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i+1];
    v[i+1] = v[fim];
    v[fim] = temp;
    return i + 1;
}

void quickSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int p = particiona(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}