//
// Created by joao on 11-04-2019.
//

#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H


int removeEnter(char *str);

int isEmptyStudent(StudentsList head);

int isEmptyPlaces(PlacesList head);

int getInfoStudent(StudentData_t *student_data);

int FindStudent(StudentsList head, StudentsList *before,
                StudentsList *current, int key);

int AppendStudent(StudentsList node);

int RemoveStudent(StudentsList node, int key);

int InsertStudent(StudentsList head, int key);

int DeleteStudentsList(StudentsList node);

char *readline();

StudentsList SearchStudent(StudentsList head, int key);


#endif //PROJECT_FUNCTIONS_H

