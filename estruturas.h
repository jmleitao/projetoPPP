//
// Created by joao on 27-03-2019.
//

#ifndef PROJETO_ESTUTURAS_H
#define PROJETO_ESTUTURAS_H

typedef struct aluno *Lista_alunos;
typedef struct locais *Lista_locais;

typedef struct dados_aluno{
    char nome[50];
    char morada[50];
    int data;
    int telefone;
}t_dados_alunos;

typedef struct aluno{
    struct dados_aluno DADOS_ALUNO;
    struct  aluno *prox;
}t_aluno;

typedef struct data
{
    int dia, mes, ano;
}Data;

typedef struct hora
{
    int hora_i, hora_f;
    int min_i, min_f;
}Hora;

typedef struct dados_locais{
    char nome_cidade[50];
}t_dados_locais;

typedef struct locais{
    struct dados_locais DADOS_LOCAIS;
    struct locais *prox;
}t_locais;

Lista_alunos * cria_lista_alunos();
Lista_locais * cria_lista_locais();

#endif //PROJETO_ESTUTURAS_H
