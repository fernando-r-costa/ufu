#include <stdio.h>
#include <string.h>
#include "lista.h"

int main() {
    //Cria a lista
    Lista* controleProdutos = criarLista(50); //Passagem por valor do número 50
    
    if (controleProdutos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    //Lê o arquivo com produtos para teste
    FILE *file = fopen("produtos.txt", "r");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    
    //Iterage com o arquivo para montar a lista
    struct produto produtoTemp;
    int contador = 0;
    while (fscanf(file, "%d", &produtoTemp.codProd) != EOF) {
        fscanf(file, "%s", produtoTemp.nomeProd);
        fscanf(file, "%f", &produtoTemp.valor);
        fscanf(file, "%d", &produtoTemp.qtdeEstoque);
    
        inserirProduto(controleProdutos, produtoTemp); //controleProdutos: passagem por referência | produtoTemp: passagem por valor
        contador ++;
    }
    
    //Fecha o arquivo
    fclose(file);
    printf("%d produtos em estoque.\n\n", contador);

    //Inserção de produto
    struct produto Novo;
    Novo.codProd = 111;
    strcpy(Novo.nomeProd, "Mousepad");
    Novo.valor = 26.90;
    Novo.qtdeEstoque = 30;
    
    inserirProduto(controleProdutos, Novo); //controleProdutos: passagem por referência | Novo: passagem por valor
    printf("Nome do produto inserido: %s - Codigo: %d - Valor: R$ %.2f - Estoque: %d\n\n", Novo.nomeProd, Novo.codProd, Novo.valor, Novo.qtdeEstoque);
    
    //Mais barato
    struct produto maisBarato = buscaPrecoMenor(controleProdutos); //controleProdutos: passagem por referência
    printf("O produto mais barato é: %s com valor de %.2f\n\n", maisBarato.nomeProd, maisBarato.valor);
    
    //Venda
    venda(controleProdutos, 101, 5); //controleProdutos: passagem por referência | números: passagem por valor
    printf("\n");
    venda(controleProdutos, 111, 100); //controleProdutos: passagem por referência | números: passagem por valor
    printf("\n");
    venda(controleProdutos, 999, 2); //controleProdutos: passagem por referência | números: passagem por valor

    return 0;
}