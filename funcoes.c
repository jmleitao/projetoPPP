#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio_ext.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"


int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }

int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }


int getInfoStudent(StudentData_t *student_data) {

    system("clear");                                        /*name*/
    printf("Insira o nome do aluno:");
    student_data->name = readlines();
    ClearBuffer();

    system("clear");                                        /*address*/
    printf("Insira o seu endereço: ");
    student_data->address = readlines();
    ClearBuffer();

    system("clear");                                        /*date of birth*/
    printf("Insira a sua data de nascimento: ");
    student_data->date_of_birth = readlines();
    ClearBuffer();

    system("clear");                                        /*phone_number*/
    printf("Insira o seu nº de Numero de Telemovel: ");
    scanf("%d", &student_data->phone_number);
    ClearBuffer();

    return 0;
}

int FindStudent(StudentsList head, StudentsList *before,  // Função que procura um aluno na lista ligada
                StudentsList *current, int key) {         // Eu uso esta função quando preciso de dar delete de um aluno
    *before = head;                                       // mas tu ja tens uma função para o fazer
    *current = head->next;

    while ((*current) != NULL && ((*current)->InfoStudent.phone_number) != key) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && (*current)->InfoStudent.phone_number != key) {
        *current = NULL;
    }
    return 0;
}

StudentsList SearchStudent(StudentsList head, int key) { // neste caso como não quero dar delete de um aluno so me
    StudentsList before;                                 // interessa saber onde é que ele está e não qual é o aluno
    StudentsList current;                                // anterior ao atual por isso retorno o current
    FindStudent(head, &before, &current,
                key);           // tambem tens uma função para dar search mas a minha seria assim
    return current;
}

int InsertStudent(StudentsList head, int key) {  // Insere um aluno a seguir ao aluno com o numero de telemovel (key)
    StudentData_t student_data;
    StudentsList student;
    StudentsList Newstudent = (StudentsList) malloc(sizeof(Student_t));

    student = SearchStudent(head, key);     // aluno com o numero de telemovel (key)

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

int RemoveStudent(StudentsList head, int key) {
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
    StudentsList current = head;
    while (current != NULL) {
        printf("--------------------\n");
        printf("Nome do Aluno: %s\n", current->InfoStudent.name);
        printf("Morada do Aluno: %s\n", current->InfoStudent.address);
        printf("Data de nascimento do Aluno: %s\n", current->InfoStudent.date_of_birth);
        printf("Numero de Telemovel do Aluno: %d\n", current->InfoStudent.phone_number);
        current = current->next;
    }
    return 0;
}



int getHourAndMinute(Hour_t *time, int option, char *string, char *delimiter) {
    char *token;
    int i = 0;
    token = strtok(string, delimiter);
    while (token != NULL) {
        if (i == 0) {
            if (option == 0)
                time->start_hour = atoi(token);
            else
                time->end_hour = atoi(token);
        } else {
            if (option == 0)
                time->start_minute = atoi(token);
            else
                time->end_minute = atoi(token);
        }
        i++;
        token = strtok(NULL, delimiter);
    }
    return 0;
}


int getInfoPDI(PDIs_t *pdi_data) {
    Hour_t hour;
    char *str,*delimiter = ":";

    system("clear");
    printf("Insira o nome do Ponto de Interse:");
    pdi_data->name = readlines();
    ClearBuffer();

    system("clear");
    printf("Insira a sua descrição do Ponto de Interesse: ");
    pdi_data->info = readlines();
    ClearBuffer();

    system("clear");
    printf("Insira a sua Horario de Funcionamento do Ponto de Interesse: ");
    printf("Hora de Abertura\n\t\tno formato (hh:mm): ");
    str = readlines();
    ClearBuffer();
    getHourAndMinute(&hour,0,str,delimiter);
    ClearBuffer();
    printf("Hora de Fecho\n\t\tno formato (hh:mm): ");
    str = readlines();
    ClearBuffer();
    getHourAndMinute(&hour,0,str,delimiter);
    ClearBuffer();
    pdi_data->WorkingHours = hour;

    return 0;
}


int FindPlace(PlacesList head, PlacesList *before,
              PlacesList *current, char *key) {
    *before = head;
    *current = head->next;

    while ((*current) != NULL && !strcmp((*current)->name, key)) {
        *before = *current;
        *current = (*current)->next;
    }
    if ((*current) != NULL && !strcmp((*current)->name, key)) {
        *current = NULL;
    }
    return 0;
}


PlacesList SearchPlace(PlacesList head, char *key) {
    PlacesList before;
    PlacesList current;
    FindPlace(head, &before, &current,
                key);
    return current;
}

int AddPDI(PlacesList head,PlacesList city) {
    PDIs_t pdi_data;
    PlacesList current = head;
    PlacesList newPlace= (PlacesList) malloc(sizeof(Places_t));


    if (SearchPlace(head, city->name) == NULL) {

        getInfoPDI(&pdi_data);

        newPlace->PointOfInterest->name = pdi_data.name;
        newPlace->PointOfInterest->info = pdi_data.info;
        newPlace->PointOfInterest->WorkingHours = pdi_data.WorkingHours;
        newPlace->next = NULL;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPlace;

    } else {
        printf("O local já existe\n");
    }
    return 0;
}


int RemovePlace(PlacesList head, char *key) {
    PlacesList current;
    PlacesList before;
    FindPlace(head, &before, &current, key);
    if (current != NULL) {
        before->next = current->next;
        free(current);
    }
    return 0;
}


int DeletePlacesList(PlacesList head) {
    Places_t *current;
    while (!isEmptyPlaces(head)) {
        current = head;
        head = head->next;
        free(current);
    }
    free(head);
    return 0;
}


int removeEnter(char *str) {
    int i = 0;
    while (*(str + i) != '\n')
        i++;
    *(str + i) = '\0';
    return 0;
}


int ler_string(char *string, int size) {
    int i;
    char c;

    for (i = 0; i < size; i++) {
        scanf("%c", &c);
        if (c == '\n') {
            string[i] = '\0';
            break;
        }

        string[i] = c;
    }
    string[i] = '\0';
    return 0;
}

char *readlines() {
    char chr, *line = NULL;
    int size = 0, i = 0;

    while ((chr = getc(stdin)) != '\n') {
        if (size <= i) {
            size += 5;
            line = realloc(line, size);
        }
        *(line + i) = chr;
        i++;
    }
    *(line + i) = '\0';
    return line;
}

