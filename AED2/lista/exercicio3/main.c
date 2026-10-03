#include <stdio.h>

int main() {
    int n = 10;
    int v[10] = {12, 45, 7, 23, 9, 42, 67, 5, 43, 67};
    int atual;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] < v[j + 1]) {
                atual = v[j];
                v[j] = v[j + 1];
                v[j + 1] = atual;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}