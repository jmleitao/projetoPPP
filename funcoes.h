//
// Created by joao on 11-04-2019.
//

#ifndef PROJETO_FUNCOES_H
#define PROJETO_FUNCOES_H


void RetiraEnter(char *str);

int lista_vazia_Students(StudentsList *li);
int lista_vazia_Places(PlacesList *li);

int verifica_Student(StudentsList node, int num);

int insere_Student(StudentsList node);
int remove_Student(StudentsList *node, int num);

int DeleteStudentsList(StudentsList node);

#endif //PROJETO_FUNCOES_H

