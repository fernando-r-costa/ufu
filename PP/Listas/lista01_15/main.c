#include <stdio.h>

int main()
{
    float alt_degrau;
    float alt_subir;
    
    printf("Digite a altura dos degraus em metros: ");
    scanf("%f", &alt_degrau);
    printf("\nDigite a altura que deseja subir em metros: ");
    scanf("%f", &alt_subir);
    
    float qte_degraus = alt_subir / alt_degrau;
    
    printf("Você deverá subir: %.0f degraus", qte_degraus);

    return 0;
}
