#include <stdio.h>

void calc_esfera(float R, float *area, float *volume) {
    (*area) = 4 * 3.1415 * R * R;
    (*volume) = (4.0/3) * 3.1415 * R * R * R;
}

int negativos (float *vet, int N) {
    int i;
    int count = 0;
    for (i=0; i<N; i++) {
        if (*(vet+i) < 0) {
            count ++;
        }
    }
    return count;
}

int main(void)
{
    /*int x, y;
    
    x = 10;
    y = 20;
    
    if (&x > &y) {
        printf("Endereco maior: %p. \n", &x);
    } else {
        printf("Endereco menor: %p. \n", &y);
    }
    
    if (&x > &y) {
        printf("Endereco maior: %d. \n", &x);
    } else {
        printf("Endereco menor: %d. \n", &y);
    }*/
    
    /*float r, a, v;
    printf("Digite o raio: ");
    scanf("%f", &r);
    
    calc_esfera(r, &a, &v);
    printf("\n Area: %.2f\n", a);
    printf("\n Volume: %.2f\n", v);*/
    
    float vet[] = {1.0, -2.19, 10.0, -5.9, 0};
    printf("\nQuantidade de negativos no vetor: %d\n", negativos (vet, 5));
    
    return 0;
}