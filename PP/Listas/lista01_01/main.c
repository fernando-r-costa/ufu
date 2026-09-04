/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num_int;
    float num_real;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num_int);
    
    printf("Digite um número real: ");
    scanf("%f", &num_real);
    
    printf("O número real foi: %d\n", num_int);
    printf("O número real foi: %f", num_real);

    return 0;
}