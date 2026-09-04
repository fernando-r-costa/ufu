#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Horario {
        int hr;
        int min;
    };
    
    struct Data {
        int d;
        int m;
        int a;
    };
    
    struct Compromisso {
        struct Horario horario;
        struct Data data;
        char descricao[150];
    };
    
    int qte;
    
    printf("Deseja cadastrar quantos compromissos: ");
    scanf("%d", &qte);
    
    setbuf(stdin, NULL);
    
    struct Compromisso compromisso[qte]; 
    
    for (int i = 0; i < qte; i++) {
        printf("\nDigite os dados do compromisso %d: \n", i+1);
        printf("Descrição: ");
        setbuf(stdin, NULL);
        fgets(compromisso[i].descricao, 150, stdin);
        printf("Data: ");
        scanf("%d %d %d", &compromisso[i].data.d, &compromisso[i].data.m, &compromisso[i].data.a);
        printf("Horario: ");
        scanf("%d %d", &compromisso[i].horario.hr, &compromisso[i].horario.min);
    }
    
    FILE *fp;
    fp = fopen("compromissos.txt", "w");
    if (fp == NULL) {
        printf("Erro");
        exit(1);
    }
    
    printf("\n# Lista de compromissos #\n\n");
    fprintf(fp, "\n# Lista de compromissos #\n\n");
    for (int i = 0; i < qte; i++) {
        printf("Descrição %d: %s", i+1, compromisso[i].descricao);
        fprintf(fp, "Descrição %d: %s", i+1, compromisso[i].descricao);
        printf("Data: %d/%d/%d - ", compromisso[i].data.d, compromisso[i].data.m, compromisso[i].data.a);
        fprintf(fp, "Data: %d/%d/%d - ", compromisso[i].data.d, compromisso[i].data.m, compromisso[i].data.a);
        printf("Horário: %d:%d\n", compromisso[i].horario.hr, compromisso[i].horario.min);
        fprintf(fp, "Horário: %d:%d\n", compromisso[i].horario.hr, compromisso[i].horario.min);
    }
    
    fclose(fp);

    return 0;
}
