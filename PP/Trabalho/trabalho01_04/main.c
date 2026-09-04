#include <stdio.h>
#include <math.h>

int main()
{
    float altura;
    float raio;
    float pi = 3.141592;
    
    scanf("%f", &altura);
    scanf("%f", &raio);
    
    float volume = pi * pow(raio,2) * altura;
    
    printf("%.6f", volume);
    
    return 0;
}