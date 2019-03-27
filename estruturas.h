//
// Created by joao on 27-03-2019.
//

#ifndef PROJETO_ESTUTURAS_H
#define PROJETO_ESTUTURAS_H

typedef struct aluno *Lista_alunos;
typedef struct viagens *Lista_viagens;

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

typedef struct dados_viagens{
    char nome_cidade[50];
}t_dados_viagens;

typedef struct viagens{
    struct dados_viagens DADOS_VIAGENS;
    struct viagens *prox;
}t_viagens;

Lista_alunos * cria_lista_alunos();
Lista_viagens * cria_lista_viagens();

#endif //PROJETO_ESTUTURAS_H
