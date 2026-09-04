#include <stdio.h>

int main()
{
    float dist_km;
    float dist_milha;
    float relation = 0.621371;
    
    scanf("%f", &dist_km);
    
    dist_milha = dist_km * relation;
    
    printf("%f", dist_milha);

    return 0;
}
