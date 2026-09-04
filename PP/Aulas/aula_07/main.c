#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*FILE *fp;
    fp = fhttps://www.onlinegdb.com/?dest_fid=70758281#_editor_338791581open("saida.txt", "w");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    for (int i = 0; i <= 127; i++) {
        fprintf (fp, "%3d %c\n", i, i);
    }
    
    fclose(fp);*/
    
    char file[30];
    printf("Digite o nome do arquivo: ");
    scanf("%s", file);
    
    setbuf(stdin, NULL);
    
    FILE *fp;
    fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    char c = fgetc(stdin);
    while (c != '\n') {
        fputc(c, fp);
        c = fgetc(stdin);
    }
    
    fclose(fp);
    
    /*char file[30];
    printf("Digite o nome do arquivo: ");
    scanf("%s", file);
    
    setbuf(stdin, NULL);
    
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    char c = fgetc(fp);
    while(c != EOF) {
     printf("%c", c);
     c = fgetc(fp);
    }
    
    fclose(fp);*/
    
    /*FILE *fp;
    fp = fopen("tabuada.txt", "w");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            fprintf (fp, "%2d x %2d = %2d | ", i, j, i*j);
        }
        fputc('\n', fp);
    }
    
    fclose(fp);*/
    

    return 0;
}