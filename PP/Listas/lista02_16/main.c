#include <stdio.h>

int funcao (int a, int b) {
    return ((a*(b+3))/(a-b));
}

int main()
{
    int res = funcao(2, 3);
    printf("Retorno da função: %d", res);

    return 0;
}
