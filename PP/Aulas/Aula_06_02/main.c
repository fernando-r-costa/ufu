#include <stdio.h>

int main() {
    
    typedef struct Horario {
        int hora;
        int minuto;
    } horario;
    
    typedef struct Data {
        int dia;
        int mes;
        int ano;
    } data;
    
    typedef struct Compromisso {
        data d;
        horario h;
        char descricao[30];
    } compromisso;
    
    compromisso c;
    
    printf("Digite a data: ");
    setbuf(stdin, NULL);
    scanf("%d %d %d", &c.d.dia, &c.d.mes, &c.d.ano);
    printf("Digite o horário: ");
    setbuf(stdin, NULL);
    scanf("%d %d", &c.h.hora, &c.h.minuto);
    printf("Digite a descrição: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", c.descricao);
    
    printf("\nCompromisso salvo!: \n");
    printf("Descrição: %s\n", c.descricao);
    printf("Data: %02d/%02d/%4d\n", c.d.dia, c.d.mes, c.d.ano);
    printf("Horário: %02d:%02d", c.h.hora, c.h.minuto);

    return 0;
}