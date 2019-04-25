#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"


int isEmptyStudent(Student_t *head) { return head->next == NULL ? 1 : 0; }

int isEmptyPlaces(Places_t *head) { return head->next == NULL ? 1 : 0; }

int removeEnter(char *str) {
    int i = 0;
    while (*(str + i) != '\n')
        i++;
    *(str + i) = '\0';
    return 0;
}

int searchStudent(StudentsList node, int key) {
    int found = 1;
    Student_t *student = node;

    if (node == NULL)
        found = 0;
    while (student != NULL && student->InfoStudent.phone_number != key) {
        printf("entrou no while");
        student = student->next;
    }
    system("pause");
    if (student == NULL)
        found = 0;

    free(student);
    return found;
}

int getInfo(StudentData_t *student_data) {

    system("clear");                                        /*name*/
    printf("Insira o nome do aluno:\n");
    fgets(student_data->name, 60, stdin);
    removeEnter(student_data->name);
    fflush(stdin);

    system("clear");                                        /*address*/
    printf("Insira o seu endereço:\n");
    fgets(student_data->address, 50, stdin);

    system("clear");                                        /*date of birth*/
    printf("Insira a sua data de nascimento:\n");
    fgets(student_data->date_of_birth, 50, stdin);

    system("clear");                                        /*phone_number*/
    printf("Insira o seu nº de phone_number:\n");
    scanf("%d", &student_data->phone_number);

    return 0;
}

int InsertStudent(StudentsList head) {
    StudentData_t student_data;
    Student_t *before, *current = head;
    Student_t *no;


    getInfo(&student_data);

    if (searchStudent(head, student_data.phone_number)) {
        printf("O aluno já existe");
        return 0;
    }

    if (head == NULL) return 0;


    no = (Student_t *) malloc(sizeof(Student_t));

    if (no == NULL) return 0;


    no->InfoStudent = student_data;

    if (isEmptyStudent(head)) {                   /*insere no inicio*/
        no->next = head;
        // head = no; ??
        return 1;
    } else {
        
        while (current != NULL && current->InfoStudent.phone_number < student_data.phone_number) {
            before = current;
            current = current->next;
        }
        if (current == head) {                  //insere inicio//
            no->next = head;
            // head = no; ??
        } else {
            no->next = before->next;
            before->next = no;
        }
        return 1;
    }
}

int RemoveStudent(StudentsList *node, int num) {
    if (node == NULL) return 0;
    Student_t *before, *no = *node;
    while (no != NULL && no->InfoStudent.phone_number != num) {
        before = no;
        no = no->next;
    }
    if (no == NULL) return 0;

    if (no == *node)//remover o primeiro?//
        *node = no->next;
    else
        before->next = no->next;
    free(no);
    return 1;

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
