#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/StudentsList.h"

int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }


int ChangeStudentInfo(StudentsList head, char *key) {
    StudentsList student;
    int option;
    printf("Insira o numero de Telemovel\n");
    student = SearchStudent(head, key);
    if (student != NULL) {
        do {
            printf("Que parametro deseja alterar?\n");
            printf("\tPretende:\n\n");
            printf("\t1 - Alterar o nome\n");
            printf("\t2 - Alterar a morada\n");
            printf("\t3 - Alterar a data de nascimento\n");
            printf("\t3 - Alterar o numero de Telemovel\n");
            ClearBuffer();
            scanf("%d", &option);
            switch (option) {
                case 1:
                    ClearConsole();
                    printf("Insira o nome do aluno: ");
                    readstring(&(student->InfoStudent.name), 30, 20);
                    break;
                case 2:
                    ClearConsole();
                    printf("Insira o seu endereço: ");
                    readstring(&student->InfoStudent.address, 30, 20);

                    break;
                case 3:
                    ClearConsole();
                    printf("Insira a sua data de nascimento: ");
                    readstring(&student->InfoStudent.date_of_birth, 30, 20);
                    break;
                case 4:
                    ClearConsole();
                    getPhoneNumber(&student->InfoStudent.phone_number);
                    break;
                default:
                    printf("Invalid Key!\n");
                    option = -1;
                    break;
            }
        } while (option < 1 || option > 4);
    } else {
        printf("O Estudante com esse numero não está registado\n");
    }
    return 0;
}


int getInfoStudent(StudentData_t *student_data) {
    //const int size = 60;

    system("clear");                                        /*name*/
    printf("Insira o nome do aluno: ");
    readstring(&(student_data->name), 30, 20);
    ClearBuffer();

    system("clear");                                        /*address*/
    printf("Insira o seu endereço: ");
    readstring(&student_data->address, 30, 20);
    ClearBuffer();

    system("clear");                                        /*date of birth*/
    printf("Insira a sua data de nascimento: ");
    readstring(&student_data->date_of_birth, 30, 20);
    ClearBuffer();

    system("clear");                                        /*phone_number*/
    getPhoneNumber(&student_data->phone_number);
    ClearBuffer();

    return 0;
}

int StudentCount(StudentsList head) {
    int counter = 0;
    StudentsList current = head->next;
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    return counter;
}

int FindStudent(StudentsList head, StudentsList *before,
                StudentsList *current,
                char *key) {
    *before = head;
    *current = head->next;

    while ((*current) != NULL && (strcmp((*current)->InfoStudent.phone_number, key) != 0)) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && (strcmp((*current)->InfoStudent.phone_number, key) != 0)) {
        *current = NULL;
    }
    return 0;
}

StudentsList SearchStudent(StudentsList head, char *key) {
    StudentsList before;
    StudentsList current;
    FindStudent(head, &before, &current, key);
    return current;
}

int InsertStudent(StudentsList head, char *key) {
    StudentData_t student_data;
    StudentsList student;
    StudentsList Newstudent = (StudentsList) malloc(sizeof(Student_t));

    student = SearchStudent(head, key);

    if (Newstudent != NULL && student != NULL) {
        getInfoStudent(&student_data);
        Newstudent->InfoStudent = student_data;

        Newstudent->next = student->next;
        student->next = Newstudent;
    }
    return 0;
}

int AddStudent(StudentsList head) {
    StudentData_t student_data;
    StudentsList current = head;
    StudentsList newStudent = (StudentsList) malloc(sizeof(Student_t));

    getInfoStudent(&student_data);

    if (SearchStudent(head, student_data.phone_number) == NULL) {

        newStudent->InfoStudent = student_data;
        newStudent->next = NULL;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;

    } else {
        printf("Estudante já tem conta criada!\n");
    }
    return 0;
}

int RemoveStudent(StudentsList head, char *key) {
    StudentsList current;
    StudentsList before;
    FindStudent(head, &before, &current, key);
    if (current != NULL) {
        before->next = current->next;
        free(current);
    }
    return 0;
}


int DeleteStudentsList(StudentsList head) {
    Student_t *current;
    while (!isEmptyStudent(head)) {
        current = head;
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}

int PrintStudentsList(StudentsList head) {
    StudentsList current = head->next;
    while (current != NULL) {
        printf("--------------------\n");
        printf("Nome do Aluno: %s\n", current->InfoStudent.name);
        printf("Morada do Aluno: %s\n", current->InfoStudent.address);
        printf("Data de nascimento do Aluno: %s\n", current->InfoStudent.date_of_birth);
        printf("Numero de Telemovel do Aluno: %s\n", current->InfoStudent.phone_number);
        current = current->next;
    }
    return 0;
}

int PrintStudent(StudentsList student) {
    if (student != NULL) {
        printf("--------------------\n");
        printf("Nome do Aluno: %s\n", student->InfoStudent.name);
        printf("Morada do Aluno: %s\n", student->InfoStudent.address);
        printf("Data de nascimento do Aluno: %s\n", student->InfoStudent.date_of_birth);
        printf("Numero de Telemovel do Aluno: %s\n", student->InfoStudent.phone_number);
    }
    return 0;
}