#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Aluno {
        char nome[150];
        char matricula[15];
        char curso[50];
    };
    
    int qte;
    
    printf("Deseja fazer quantos cadastros: ");
    scanf("%d", &qte);
    
    setbuf(stdin, NULL);
    
    struct Aluno aluno[qte]; 
    
    for (int i = 0; i < qte; i++) {
        printf("\nDigite os dados do aluno %d: \n", i+1);
        printf("Nome: ");
        fgets(aluno[i].nome, 150, stdin);
        printf("Matricula: ");
        fgets(aluno[i].matricula, 15, stdin);
        printf("Curso: ");
        fgets(aluno[i].curso, 50, stdin);
    }
    
    FILE *fp;
    fp = fopen("alunos.txt", "w");
    if (fp == NULL) {
        printf("Erro");
        exit(1);
    }
    
    printf("\n# Lista de Alunos #\n\n");
    fprintf(fp, "\n# Lista de Alunos #\n\n");
    for (int i = 0; i < qte; i++) {
        printf("Nome %d: %s", i+1, aluno[i].nome);
        fprintf(fp, "Nome %d: %s", i+1, aluno[i].nome);
        printf("Matricula: %s", aluno[i].matricula);
        fprintf(fp, "Matricula: %s", aluno[i].matricula);
        printf("Endereco: %s\n", aluno[i].curso);
        fprintf(fp, "Endereco: %s\n", aluno[i].curso);
    }
    
    fclose(fp);

    return 0;
}
