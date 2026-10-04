#include <stdio.h>

int main() {
	int v[6] = {1, 2, 4, 5, 6};
    int qte = 5;
    int extra = 7;

    int i = qte - 1;

    while (i >= 0 && v[i] > extra) {
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = extra;
    qte++;

    for (int i = 0; i < qte; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}