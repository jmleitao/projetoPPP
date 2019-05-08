#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/StudentsList.h"
#include "Headers/PlacesList.h"

int changeInfomenu() {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|             > Que parametro deseja alterar? <              |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 1 - Alterar o nome                         |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 2 - Alterar a morada                       |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 3 - Alterar a data de nascimento           |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 4 - Alterar o numero de Telemovel          |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    return 0;
}

int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }


int ChangeStudentInfo(StudentsList head, char *key) {
    StudentsList student;
    int option;
    student = SearchStudent(head, key);
    if (student != NULL) {
        do {
            changeInfomenu();
            ClearBuffer();
            scanf("%d", &option);
            switch (option) {
                case 1:
                    ClearBuffer();
                    printf("\t\t\t\t\t\t\t\t\t Nome atual: %s\n",student->InfoStudent.name);
                    printf("\t\t\t\t\t\t\t\t\t Novo nome do aluno: ");
                    readstring(&student->InfoStudent.name, 30, 10);
                    ClearConsole();
                    break;
                case 2:
                    ClearBuffer();
                    printf("\t\t\t\t\t\t\t\t\t Morada Atual: %s\n",student->InfoStudent.address);
                    printf("\t\t\t\t\t\t\t\t\t Novo norada do aluno: ");
                    readstring(&student->InfoStudent.address, 30, 10);
                    ClearConsole();
                    break;
                case 3:
                    ClearBuffer();
                    printf("\t\t\t\t\t\t\t\t\t Data de nascimento atual: %s\n",student->InfoStudent.date_of_birth);
                    printf("\t\t\t\t\t\t\t\t\t Novo data de nascimento do aluno: ");
                    getDateOfBirth(&student->InfoStudent.date_of_birth);
                    ClearConsole();
                    break;
                case 4:
                    ClearBuffer();
                    printf("\t\t\t\t\t\t\t\t\t Número de telemovel atual: %s\n",student->InfoStudent.phone_number);
                    printf("\t\t\t\t\t\t\t\t\t Novo número de telemovel: ");
                    getPhoneNumber(&student->InfoStudent.phone_number);
                    ClearConsole();
                    break;
                default:
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t Opção Invalida!\n");
                    ClearConsole();
                    option = -1;
                    break;
            }
        } while (option == -1);
    } else {
        printf("\t\t\t\t\t\t\t\t\t\tO Estudante com esse numero não se encontra registado\n");
    }
    return 0;
}


int getInfoStudent(StudentData_t *student_data) {
    //const int size = 60;
    printf("\t\t\t\t\t\t\t\t\t\t\t»»» Introduza os dados nos respetivos campos «««\n\n");
    ClearConsole();
    printf("\t\t\t\t\t\t\t\t\t Nome do aluno: ");
    readstring(&(student_data->name), 30, 10);
    ClearBuffer();

    ClearConsole();
    printf("\t\t\t\t\t\t\t\t\t Morada do aluno: ");
    readstring(&student_data->address, 30, 10);
    ClearBuffer();

    ClearConsole();
    printf("\t\t\t\t\t\t\t\t\t Data de nascimento do aluno: ");
    getDateOfBirth(&student_data->date_of_birth);
    ClearBuffer();

    ClearConsole();
    printf("\t\t\t\t\t\t\t\t\t Número de telemovel do aluno: ");
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
    head->StudentCount = counter;
    printf("Number of Students: %d\n", counter);
    return 0;
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
    PointsOfInterestList defaultPointOfInterest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    int i;

    defaultPointOfInterest->name = "Not Defined";
    defaultPointOfInterest->info= NULL;
    defaultPointOfInterest->WorkingHours = NULL;
    defaultPointOfInterest->next = NULL;

    getInfoStudent(&student_data);

    if (SearchStudent(head, student_data.phone_number) == NULL) {

        newStudent->InfoStudent = student_data;
        newStudent->next = NULL;
        newStudent->InfoInterests.hot = "Not Defined ";
        for (i = 0; i < 3; i++) {
            newStudent->InfoInterests.favorite_places[i] = "Not Defined";
        }
        newStudent->InfoInterests.other_points_of_interest = defaultPointOfInterest;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;

    } else {
        printf("\n\t\t\t\t\t\t\t\t\t O aluno com este número de telemovel já tem conta criada!\n");
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
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tO aluno foi removido com sucesso!\n");
    return 0;
}

int Has3FavoritePlaces(StudentsList student){
    int i,answer = 1;
    for(i = 0;i < 3 && answer != 0;i++){
        if(strcmp(student->InfoInterests.favorite_places[i],"Not defined") == 0)
            answer = 0;
    }
    return answer;
}


int DeleteStudentsList(StudentsList head) {
    Student_t *current;
    while (!isEmptyStudent(head)) {
        current = head;
        head = head->next;
        DeletePointsOfInterestList(current->InfoInterests.other_points_of_interest);
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