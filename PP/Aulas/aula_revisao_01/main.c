#include <stdio.h>

int main()
{
    /*for(int i = 0; i < 128; i++) {
        printf("%3d\t %c\n", i, i);    
    };*/
    
    /*int i = 0;
    while(i < 128) {
        printf("%3d\t %c\n", i, i);
        i++;
    };*/
    
    /*int qte;
    int notas[qte];
    
    printf("Informe a qte de alunos: ");
    scanf("%d", &qte);
    
    for(int i=0; i<qte; i++) {
        printf("Informe a nota do aluno %d: ", i+1);
        scanf("%d", &notas[i]);
    }
    
    int soma = 0;
    
    for(int j=0; j<qte; j++) {
        soma = soma + notas[j];
    }
    
    float media = soma/(float) qte;
    
    printf("A soma das notas foi: %d\n", soma);
    printf("A média das notas foi: %.2f", media);*/
    
    /*int linhas, colunas;
    
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);
    
    float matriz[linhas][colunas];
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }*/
    
    /*int linhas, colunas;
    
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);
    
    float matriz[linhas][colunas];
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            if(i==j){
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
    
    for(int i=0; i<linhas; i++) {
        for(int j=0; j<colunas; j++) {
            printf("%.0f ", matriz[i][j]);
        }
        printf("\n");
    }*/
    
    int alunos;
    int provas;
    
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &alunos);
    printf("Digite a quantidade de provas: ");
    scanf("%d", &provas);
    
    float notas[alunos][provas];
    
    for(int i=0; i<alunos; i++) {
        printf("Digite as notas do aluno %d\n", i+1);
        for(int j=0; j<provas; j++) {
            printf("Prova %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
    
    printf("\n>>> NOTAS DOS ALUNOS <<<\n");
    printf(" ALUNO | PROVAS\n");
    for(int i=0; i<alunos; i++) {
        printf("   %d   ", i+1);
        for(int j=0; j<provas; j++) {
            printf("| %.2f ", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}
