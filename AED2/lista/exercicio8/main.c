#include <stdio.h>
#include <string.h>

struct pessoa {
    int matricula;
    char nome[30];
    float nota;
};

void ordenarArr(struct pessoa *v, int N, int campo) {
    int i, continua;
    struct pessoa aux;
    int fim = N;

    do {
        continua = 0;
        for (i = 0; i < fim - 1; i++) {
            int trocar = 0;

            if (campo == 1) {
                if (v[i].matricula > v[i + 1].matricula) {
                    trocar = 1;
                }
            } else if (campo == 2) {
                if (strcmp(v[i].nome, v[i + 1].nome) > 0) {
                    trocar = 1;
                }
            } else if (campo == 3) {
                if (v[i].nota > v[i + 1].nota) {
                    trocar = 1;
                }
            }

            if (trocar) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = 1;
            }
        }
        fim--;
    } while (continua != 0);
}

int main() {
    int N = 4;
    struct pessoa turma[4] = {
        {102, "Zelia", 8.5},
        {104, "Ana", 9.0},
        {101, "Carlos", 7.5},
        {103, "Bruno", 6.0}
    };

    int opcao;
    printf("Ordenação por:\n");
    printf("1 - Matrícula\n");
    printf("2 - Nome\n");
    printf("3 - Nota\n");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 3) {
        printf("Opção invalida!\n");
        return 1;
    }

    ordenarArr(turma, N, opcao);

    for (int i = 0; i < N; i++) {
        printf("Matrícula: %d | Nome: %s | Nota: %.1f\n", turma[i].matricula, turma[i].nome, turma[i].nota);
    }

    return 0;
}