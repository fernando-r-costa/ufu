#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main(){
    int tamanho = 1024;
    Hash *tabela = criaHash(tamanho);


    /*struct aluno al, a[4] = {{12352,"Andre",9.5,7.8,8.5},//64
                         {7894,"Ricardo",7.5,8.7,6.8},//726
                         {3451,"Bianca",9.7,6.7,8.4},//379
                         {5293,"Ana",5.7,6.1,7.4}};//173*/

    struct aluno al, a[4] = {{100,"Andre",9.5,7.8,8.5},
                             {1124,"Ricardo",7.5,8.7,6.8},
                             {2148,"Bianca",9.7,6.7,8.4},
                             {250,"Ana",5.7,6.1,7.4}};

    int total_colisoes = 0; // Inicia o contador zerado
    int i;
    for(i=0; i < 4; i++){
        // Passamos o endereço da variável para a função poder alterá-la
        insereHash_Contando(tabela, a[i], &total_colisoes);
    }

    printf("Total de colisoes durante a insercao: %d\n", total_colisoes);
    printf("------------\n\n");

    /*buscaHash_SemColisao(tabela, 12352, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 3451, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_SemColisao(tabela, 5293, &al);
    printf("%s, %d\n",al.nome,al.matricula);*/

    buscaHash_EnderAberto(tabela, 100, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_EnderAberto(tabela, 1124, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    buscaHash_EnderAberto(tabela, 2148, &al);
    printf("%s, %d\n",al.nome,al.matricula);

    printf("Removendo o Ricardo (1124)...\n");
    removeHash_EnderAberto(tabela, 1124);

    printf("Buscando a Bianca (2148) depois de remover o Ricardo:\n");
    if (buscaHash_EnderAberto(tabela, 2148, &al)) {
        printf("Encontrada: %s, %d\n", al.nome, al.matricula);
    } else {
        printf("Bianca não foi encontrada!\n");
    }

    liberaHash(tabela);

    return 0;
}
