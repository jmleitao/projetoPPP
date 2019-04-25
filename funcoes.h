//
// Created by joao on 11-04-2019.
//

#ifndef PROJETO_FUNCOES_H
#define PROJETO_FUNCOES_H


int removeEnter(char *str);

int isEmptyStudent(StudentsList head);
int isEmptyPlaces(PlacesList head);

int searchStudent(StudentsList node, int key);

int InsertStudent(StudentsList node);
int RemoveStudent(StudentsList *node, int key);

int DeleteStudentsList(StudentsList node);

#endif //PROJETO_FUNCOES_H

