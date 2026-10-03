#include <stdio.h>

int main() {
    int v[10];

    int ehOrdenado = 1;

    printf("Digite 10 numeros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 10 - 1; i++) {
        if (v[i] > v[i + 1]) {
            ehOrdenado = 0;
            break;
        }
    }

    if (ehOrdenado) {
        printf("Ordenado\n");
    } else {
        printf("Não Ordenado\n");
    }

    return 0;
}