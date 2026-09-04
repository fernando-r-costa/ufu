#include <stdio.h>

//1
// void trocaA(int x, int y) {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// void trocaB(int *x, int *y) {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int main() {
    
//     int a = 5, b = 10;
    
//     printf("Antes da trocaA: a = %d, b = %d\n", a, b);
//     trocaA(a, b);
//     printf("Depois da trocaA: a = %d, b = %d\n", a, b);
    
//     printf("Antes da trocaB: a = %d, b = %d\n", a, b);
//     trocaB(&a, &b);
//     printf("Depois da trocaA: a = %d, b = %d\n", a, b);
    
//     return 0;
// }

// //Resposta 
// //Antes da trocaA: a = 5, b = 10
// //Depois da trocaA: a = 5, b = 10
// //Antes da trocaB: a = 5, b = 10
// //Depois da trocaA: a = 10, b = 5
// //trocaA passa por cópia, por isso não modifica os valores das variáveis no main.
// //trocaB passa por referência, ou seja, passa o endereço, por isso ao final da operação os valores são tracados.

//2
// void f(int *j) {
//     (*j)++;
// }

// int main() {
//     int i = 20;
//     int *p = &i;
//     f(p);
    
//     printf("i = %d\n", i);
//     return 0;
    
// }

// //Resposta
// //A saída é 21, pois o ponteiro p armazena o endereço de i, e quando passa para a função ela incrementa 1 no valor dentro do endereço, por isso 20 -> 21.


//3
// int a = 0;
// void p(int b, int c);

// void main() {
//     int a = 1;
//     p(a, a);
//     printf("%d", a);
// }

// void p(int b, int c) {
//     a = a+1;
//     b = b+1;
//     c = c+1;
//     printf("%d\n", a+b+c);
// }

int a = 0;
void p(int *b, int *c);

void main() {
    int a = 1;
    p(&a, &a);
    printf("%d", a);
}

void p(int *b, int *c) {
    a = a+1;
    *b = *b+1;
    *c = *c+1;
    printf("%d\n", a+*b+*c);
}

//Resposta letra a 5 (a(global)=0, a=1, b=2 e c=2)
//Resposta letra b 7 (a(global)=0, a=1, b=2 e c=b=3(x2))

