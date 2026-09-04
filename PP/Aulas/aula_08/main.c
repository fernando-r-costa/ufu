#include <stdio.h>

/*int somatorio(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main()
{
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    
    int resultado = somatorio(n);
    
    printf("Somatorio de 1 a %d: %d\n", n, resultado);

    return 0;
}*/

/*void calculos_circulo(float raio, float *area, float *perimetro, float *diametro) {
    *area = 3.1415 * raio * raio;
    *perimetro = 2 * 3.1415 * raio;
    *diametro = 2 * raio;
}

void main()
{
    float r;
    printf("Digite o raio do circulo: ");
    scanf("%f", &r);
    
    float a, p, d;
    calculos_circulo( r, &a, &p, &d);
    
    printf("Area do circulo: %f\n", a);
    printf("Perimetro do circulo: %f\n", p);
    printf("Diametro do circulo: %f\n", d);

}*/

int soma_vet (int *v, int t) {
    int soma = 0;
    for (int i = 0; i < t; i++) {
        soma += v[i];
    }
    return soma;
}

void imprime_vet (int *v, int t) {
    printf("Vetor: ");
    for (int i = 0; i < t-1; i++) {
        printf("%d", v[i]);
    }
    printf("%d\n", v[t-1]);
}

void main()
{
    int v[5] = {1, 2, 3, 4, 5};
    
    int s = soma_vet(v, 5);
    printf("A soma dos elementos: %d\n", s);
    
    imprime_vet(v, 5);
    
}