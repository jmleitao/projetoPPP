#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"


int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }

int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }


int getInfoStudent(StudentData_t *student_data) {

    system("clear");                                        /*name*/
    printf("Insira o nome do aluno: ");
    //student_data->name = readline();
    fgets(student_data->name, 60, stdin);
    removeEnter(student_data->name);
    fflush(stdin);

    system("clear");                                        /*address*/
    printf("Insira o seu endereço: ");
    //student_data->address = readline();
    fgets(student_data->address, 50, stdin);

    system("clear");                                        /*date of birth*/
    printf("Insira a sua data de nascimento: ");
    //student_data->date_of_birth = readline();
    fgets(student_data->date_of_birth, 50, stdin);

    system("clear");                                        /*phone_number*/
    printf("Insira o seu nº de Numero de Telemovel: ");
    scanf("%d", &student_data->phone_number);

    return 0;
}

int FindStudent(StudentsList head, StudentsList *before,  // Função que procura um aluno na lista ligada
                StudentsList *current, int key) {         // Eu uso esta função quando preciso de dar delete de um aluno
    *before = head;                                       // mas tu ja tens uma função para o fazer
    *current = head->next;

    while ((*current) != NULL && (*current)->InfoStudent.phone_number != key) {
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


int AppendStudent(StudentsList head) {
    StudentData_t student_data;
    StudentsList current = head;
    StudentsList newStudent = (StudentsList) malloc(sizeof(Student_t));

    getInfoStudent(&student_data);

    newStudent->InfoStudent = student_data;
    newStudent->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
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


int removeEnter(char *str) {
    int i = 0;
    while (*(str + i) != '\n')
        i++;
    *(str + i) = '\0';
    return 0;
}

char *readline() {
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
    return line;
}
