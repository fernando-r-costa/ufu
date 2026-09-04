#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");
    /*//Exerc�cio 1
    double vi, tq, d;
    const double g = 9.81;

    printf("Digite a velocidade inicial (m/s):\n");
    scanf("%lf", &vi);

    printf("Digite o tempo de queda (s):\n");
    scanf("%lf", &tq);

    //d = vi * tq - g * tq *tq / 2;*
    d = vi * tq - g * pow(tq, 2.0) / 2;

    printf("O deslocamento foi de %lf m.\n", d);*/

    /*//Exerc�cio 2
    double c;

    printf("Digite a temperatura em graus Celsius:\n");
    scanf("%lf", &c);

    double f = (1.8 * c) + 32;

    printf("A temperatura em grau Fahrenheit �: %lf\n", f);
    printf("A temperatura %.2lf em graus Celsius corresponde a %.2lf em graus Fahrenheit", c, f);*/

    /*//Exerc�cio 3
    float n1, n2, n3;
    float p1, p2, p3;

    printf("#Calculadora m�dia ponderada de 3 notas#\n");
    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Peso 1: ");
    scanf("%f", &p1);

    printf("Nota 2: ");
    scanf("%f", &n2);
    printf("Peso 2: ");
    scanf("%f", &p2);

    printf("Nota 3: ");
    scanf("%f", &n3);
    printf("Peso 3: ");
    scanf("%f", &p3);

    float m = ((n1*p1) + (n2*p2) + (n3*p3)) / (p1+p2+p3);

    printf("A m�dia das notas com pesos: %.2f", m);*/

    //Lista 1 - Exerc�cio 1
    double a, b, c;

    printf("Digite o cateto a: ");
    scanf("%lf", &a);

    printf("Digite o cateto b: ");
    scanf("%lf", &b);

    c = sqrt(pow(a,2.0) + pow(b,2.0));

    printf("A Hipotenusa: %lf", c);

    return 0;
}
