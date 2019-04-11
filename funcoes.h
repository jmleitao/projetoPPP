//
// Created by joao on 11-04-2019.
//

#ifndef PROJETO_FUNCOES_H
#define PROJETO_FUNCOES_H


void RetiraEnter(char *str);

int lista_vazia_alunos(Lista_alunos *li);
int lista_vazia_locais(Lista_locais *li);

int verifica_aluno(Lista_alunos *node, int num);

int insere_aluno(Lista_alunos*  node);
int remove_aluno(Lista_alunos *node, int num);

int libera_alunos(Lista_alunos *node);

#endif //PROJETO_FUNCOES_H
