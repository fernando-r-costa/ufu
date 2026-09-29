#include "sorts.h"

void selectionSort(int v[], int n){
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}