#include <stdio.h>
#include "tad.h"

int main() {
    
    No *listaAlunos;
    listaAlunos = criaListaVazia();
    
    int escolha;
    int c;
    
    do {
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1: {
                char nomeTemp[50];
                int npTemp, ntTemp;
                
                while ((c = getchar()) != '\n' && c != EOF); 
                scanf("%[^\n]", nomeTemp);
                
                scanf("%d", &npTemp);
                scanf("%d", &ntTemp);
                
                listaAlunos = inserirAluno(listaAlunos, nomeTemp, npTemp, ntTemp);
                break;
            }
            
            case 2: {
                char nomeTemp[50];
                
                while ((c = getchar()) != '\n' && c != EOF); 
                scanf("%[^\n]", nomeTemp);
                
                buscaAluno(listaAlunos, nomeTemp);
                break;
            }
                
            case 3:
                mediaSuperior(listaAlunos);
                break;
                
            case 4: {
                char nomeTemp[50];
                
                while ((c = getchar()) != '\n' && c != EOF); 
                scanf("%[^\n]", nomeTemp);
                
                listaAlunos = removerAluno(listaAlunos, nomeTemp);
                break;
            }
            
            case 5:
                imprimeLista(listaAlunos);
                break;
                
            case 0:
                break;
        }
        
    } while (escolha != 0);
    
    return 0;
}