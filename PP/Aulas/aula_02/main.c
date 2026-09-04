#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /*// Exerc�cio 1
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade < 30)
    {
        printf("vc ainda � jovem");
    } else {
        printf("vc � experiente!");
    }*/

    /*//Exerc�cio 2

    double numero, raiz;

    printf("Digite o n�mero para calcular a raiz quadrada: ");
    scanf("%lf", &numero);

    if (numero >= 0)
    {
        raiz = sqrt(numero);
        printf("O valor da raiz quadrada de %f �: %lf", numero, raiz);
    } else {
        raiz = sqrt (-numero);
        printf("O valor da raiz quadrade de %f �: %lf i", numero, raiz);
    }*/

    /*//Exerc�cio 3

    char tipoVeiculo;
    float horas, valorTotal;

    printf("Digite o tipo do veiculo: ");
    tipoVeiculo = getchar();

    printf("Digite as horas: ");
    scanf("%f", &horas);

    switch (tipoVeiculo){
        case 'c':
            valorTotal = horas * 2.00;
            printf("carro R$ %f a hora", valorTotal);
            break;
        case 'o':
            valorTotal = horas * 3.00;
            printf("onibus R$ %f a hora", valorTotal);
            break;
        case 't':
            valorTotal = horas * 4.00;
            printf("Caminhao R$ %f a hora", valorTotal);
            break;
        default:
            printf("Valor informado invalido");
    }*/

    //Exerc�cio 4
    int a, b, c;

    printf("Digite os lados a, b e c: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a < (b + c) && b < (a + c) && c < (a + b)) {
        if(a == b && b == c) {
            printf("O triangulo e equilatero");
        } else if(a == b || a == c || b == c) {
            printf("O triangulo e isosceles");
        } else {
            printf("O triangulo e escaleno");
        }
    } else {
        printf("Nao e triangulo");
    }


    return 0;
}
