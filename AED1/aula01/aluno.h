#ifndef _aluno_h
#define _aluno_h

struct TipoAluno {
    char nome[50];
    float media;
};

float media(float p1, float p2, float participacao);

#endif