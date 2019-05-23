#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/StudentsList.h"
#include "Headers/PlacesList.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/Menus.h"

/*Maior parte das funções tem coportamento semelhante ás funções presentes no ficheiro PlacesList.c*/
/*As que são diferentes foram comentadas*/

int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }

// Função utilizada para dado um estudante recebido como parametro alterar um dos campos dos seus dados pessoais
// caso este estudante esteja registado claro
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
                    ClearConsole();
                    ClearBuffer();
                    printf("\nNome atual: %s\n", student->InfoStudent.name);
                    printf("Novo nome do aluno: ");
                    readstring(&student->InfoStudent.name, 30, 10);
                    ClearConsole();
                    break;
                case 2:
                    ClearConsole();
                    ClearBuffer();
                    printf("\nMorada Atual: %s\n", student->InfoStudent.address);
                    printf("Novo norada do aluno: ");
                    readstring(&student->InfoStudent.address, 30, 10);
                    ClearConsole();
                    break;
                case 3:
                    ClearConsole();
                    ClearBuffer();
                    printf("\nData de nascimento atual: %s\n", student->InfoStudent.date_of_birth);
                    printf("Novo data de nascimento do aluno: ");
                    getDateOfBirth(&student->InfoStudent.date_of_birth);
                    ClearConsole();
                    break;
                case 4:
                    ClearConsole();
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

// Função que apenas pede ao utlizador os dados para os guardar na estrutura que alberga os seus dados pessoais
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
// Adiciona um estudante á lista ligada de estudantes recebe por isso como parametro a cabeça da lista ligada de estudantes
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
    int i, answer = 0;
    for (i = 0; i < 3 && answer != 1; i++) {
        if (strcmp(student->InfoInterests.favorite_places[i], "Not Defined") == 0)
            answer = 1;
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

int PrintStudent(StudentsList student) {
    PointsOfInterestList current;
    int i;
    if (student != NULL) {
        printf("+------------------------------------------------------------+\n");
        printf("Nome: %s\n", student->InfoStudent.name);
        printf("Morada: %s\n", student->InfoStudent.address);
        printf("Data de nascimento: %s\n", student->InfoStudent.date_of_birth);
        printf("Numero de Telemovel: %s\n", student->InfoStudent.phone_number);
        printf("Os meus Locais favoritos:\n");
        for (i = 0; i < 3; i++) {
            if (strcmp(student->InfoInterests.favorite_places[i], "Not Defined") == 0)
                printf("\t »» -------\n");
            else
                printf("\t »» %s\n", student->InfoInterests.favorite_places[i]);
        }
        if (strncmp(student->InfoInterests.hot, "Not Defined",11) == 0)
            printf("O meu Ponto de Interesse Hot: -------\n");
        else
            printf("O meu Ponto de Interesse Hot: %s\n", student->InfoInterests.hot);
        current = student->InfoInterests.other_points_of_interest->next;
        if(current == NULL)
            printf("Outros Pontos de Interesse: --------\n");
        else
            printf("Outros Pontos de Interesse:\n");
        while (current != NULL) {
            printf("\t »» %s\n", current->name);
            current = current->next;
        }
    }
    justPause();
    printf("+------------------------------------------------------------+\n");
    ClearBuffer();
    getchar();
    ClearConsole();
    return 0;
}