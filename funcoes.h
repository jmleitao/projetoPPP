//
// Created by joao on 11-04-2019.
//

#ifndef PROJECT_FUNCTIONS_H
#define PROJECT_FUNCTIONS_H

#define ClearBuffer() __fpurge(stdin)
#define ClearConsole() system("clear")

int removeEnter(char *str);

int isEmptyStudent(StudentsList head);

int isEmptyPlaces(PlacesList head);

int getInfoStudent(StudentData_t *student_data);

int FindStudent(StudentsList head, StudentsList *before,
                StudentsList *current, int key);

int AddStudent(StudentsList node);

int RemoveStudent(StudentsList node, int key);

int InsertStudent(StudentsList head, int key);

int DeleteStudentsList(StudentsList node);

int ler_string(char *string, int size);

StudentsList SearchStudent(StudentsList head, int key);

char *readline(void);

int PrintStudentsList(StudentsList head);

int PrintStudent(StudentsList student);

#endif //PROJECT_FUNCTIONS_H

