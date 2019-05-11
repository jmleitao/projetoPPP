#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/StudentsList.h"
#include "Headers/PlacesList.h"

int changeInfomenu() {
    printf("+------------------------------------------------------------+\n");
    printf("|             > Que parametro deseja alterar? <              |\n");
    printf("|                 1 - Alterar o nome                         |\n");
    printf("|                                                            |\n");
    printf("|                 2 - Alterar a morada                       |\n");
    printf("|                                                            |\n");
    printf("|                 3 - Alterar a data de nascimento           |\n");
    printf("|                                                            |\n");
    printf("|                 4 - Alterar o numero de Telemovel          |\n");
    printf("|                                                            |\n");
    printf("|                         0 - Voltar                         |\n");
    printf("|                                                            |\n");
    printf("|                        ____________                        |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(33, 13);
    return 0;
}

void added(void) {
    ClearConsole();
    printf("+------------------------------------------------------------+\n");
    printf("|            A conta foi criada com sucesso!!                |\n");
    printf("|            Carregue no Enter para continuar...             |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause();
}

void removed(void) {
    ClearConsole();
    printf("+------------------------------------------------------------+\n");
    printf("|           A conta foi removida com sucesso!!               |\n");
    printf("|            Carregue no Enter para continuar...             |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause();
}

void noAccount(void) {
    printf("+------------------------------------------------------------+\n");
    printf("| O aluno com este número de telemovel não tem conta criada! |\n");
    printf("|            Carregue no Enter para continuar...             |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause();
}

void hasAccount(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("| O aluno com este número de telemovel já tem conta criada! |\n");
    printf("|            Carregue no Enter para continuar...            |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause();
}


int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }


int ChangeStudentInfo(StudentsList head, char *key, int *option3) {
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
                    printf("\nNome atual: %s\n", student->InfoStudent.name);
                    printf("Novo nome do aluno: ");
                    readstring(&student->InfoStudent.name, 30, 10);
                    ClearConsole();
                    break;
                case 2:
                    ClearBuffer();
                    printf("\nMorada Atual: %s\n", student->InfoStudent.address);
                    printf("Novo norada do aluno: ");
                    readstring(&student->InfoStudent.address, 30, 10);
                    ClearConsole();
                    break;
                case 3:
                    ClearBuffer();
                    printf("\nData de nascimento atual: %s\n", student->InfoStudent.date_of_birth);
                    printf("Novo data de nascimento do aluno: ");
                    getDateOfBirth(&student->InfoStudent.date_of_birth);
                    ClearConsole();
                    break;
                case 4:
                    ClearBuffer();
                    printf("\nNúmero de telemovel atual: %s\n", student->InfoStudent.phone_number);
                    printf("Novo número de telemovel: ");
                    getPhoneNumber(&student->InfoStudent.phone_number);
                    ClearConsole();
                    break;
                case 0:
                    *option3 = 0;
                    break;
                default:
                    printf("\nOpção Invalida!\n");
                    ClearConsole();
                    option = -1;
                    break;
            }
        } while (option == -1);
    } else {
        *option3 = 0;
        noAccount();
    }
    return 0;
}


int getInfoStudent(StudentData_t *student_data) {
    //const int size = 60;
    printf("»»» Introduza os dados nos respetivos campos «««\n\n");
    printf("Nome do aluno: ");
    readstring(&(student_data->name), 30, 10);
    ClearBuffer();

    printf("Morada do aluno: ");
    readstring(&student_data->address, 30, 10);
    ClearBuffer();

    printf("Data de nascimento do aluno (dd/mm/yyyy): ");
    getDateOfBirth(&student_data->date_of_birth);
    ClearBuffer();

    printf("Número de telemovel do aluno: ");
    getPhoneNumber(&student_data->phone_number);
    ClearBuffer();
    ClearConsole();
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
    PointsOfInterestList defaultPointOfInterest = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    int i;

    defaultPointOfInterest->name = "Not Defined";
    defaultPointOfInterest->info = NULL;
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

        added();
    } else {
        hasAccount();
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
        ClearConsole();
        removed();
    } else {
        ClearConsole();
        noAccount();
    }
    return 0;
}

int Has3FavoritePlaces(StudentsList student) {
    int i, answer = 1;
    for (i = 0; i < 3 && answer != 0; i++) {
        if (strcmp(student->InfoInterests.favorite_places[i], "Not defined") == 0)
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