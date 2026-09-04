#include <stdio.h>
#include "tad.h"

int main() {
    
    No *listaAlunos;
    
    listaAlunos = criaListaVazia();
    
    verificaListaVazia(listaAlunos);
    
    int escolha;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Buscar aluno\n");
        printf("3 - Retornar alunos com media superior a 70\n");
        printf("4 - Remover aluno\n");
        printf("5 - Imprime a lista\n");
        printf("0 - Sair\n");
        printf("-> ");
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1: {
                char nomeTemp[50];
                int npTemp, ntTemp;
                
                printf("\n\n-- Inserir Aluno: -- \n");
                printf("-> Digite o nome: ");
                scanf(" %[^\n]", nomeTemp);
                
                do{
                    int num;
                    
                    printf("-> Nota Pratica: ");
                    num = scanf("%d", &npTemp);
                    
                    if(num == 0) {
                        printf("# Erro: caractere inválido\n");
                        
                        while (getchar() != '\n');
                        
                        npTemp = -1;
                        
                    } else if(npTemp < 0 || npTemp > 50) {
                        printf("# Erro: o valor deve ser entre 0 e 50\n");
                    }
                } while (npTemp < 0 || npTemp > 50);
                
                do{
                    int num;
                    
                    printf("-> Nota Teórica: ");
                    num = scanf("%d", &ntTemp);
                    
                    if(num == 0) {
                        printf("# Erro: caractere inválido\n");
                        
                        while (getchar() != '\n');
                        
                        ntTemp = -1;
                        
                    } else if(ntTemp < 0 || ntTemp > 50) {
                        printf("# Erro: o valor deve ser entre 0 e 50\n");
                    }
                } while (ntTemp < 0 || ntTemp > 50);
                
                listaAlunos = inserirAluno(listaAlunos, nomeTemp, npTemp, ntTemp);
                printf("** Aluno inserido com sucesso! **\n\n");
                break;
            }
            
            case 2:{
                char nomeTemp[50];
                
                printf("\n\n--Digite o nome para a busca: ");
                scanf(" %[^\n]", nomeTemp);
                
                buscaAluno(listaAlunos, nomeTemp);
                
                break;
            }
                
            case 3:
                mediaSuperior(listaAlunos);
                
                break;
                
            case 4:{
                char nomeTemp[50];
                
                printf("\n\n--Digite o nome do aluno a ser removido: ");
                scanf(" %[^\n]", nomeTemp);
                
                listaAlunos = removerAluno(listaAlunos, nomeTemp);
                
                break;
            }
            
            case 5:
                imprimeLista(listaAlunos);
                
                break;
                
            case 0:
                printf("\n\nSaindo...\n");
                break;
                
            default:
                printf("# Erro: Opcao invalida!\n");
                break;
        }
        
    } while (escolha != 0);
    
    return 0;
}