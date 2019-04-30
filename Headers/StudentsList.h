//
// Created by pedro on 29-04-2019.
//

#ifndef PROJETO_STUDENTSLIST_H


int isEmptyStudent(StudentsList head);

int getInfoStudent(StudentData_t *student_data);

int FindStudent(StudentsList head, StudentsList *before,
                StudentsList *current, char *key);

StudentsList SearchStudent(StudentsList head, char *key);

int AddStudent(StudentsList node);

int RemoveStudent(StudentsList node, char *key);

int InsertStudent(StudentsList head, char *key);

int DeleteStudentsList(StudentsList node);

int PrintStudentsList(StudentsList head);

int PrintStudent(StudentsList student);

int StudentCount(StudentsList head);

#define PROJETO_STUDENTSLIST_H
#endif //PROJETO_STUDENTSLIST_H
