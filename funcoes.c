//
// Created by joao on 11-04-2019.
// and pedro
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"


void RetiraEnter(char *str) {
    int i = 0;
    while (str[i] != '\n')
        i++;
    str[i] = '\0';
}


int lista_vazia_Students(StudentsList *li) {
    if (li == NULL || *li == NULL) return 1;
    return 0;
}

int lista_vazia_Places(PlacesList *li) {
    if (li == NULL || *li == NULL) return 1;
    return 0;
}

int verifica_Student(StudentsList node, int num) {
    if (node == NULL) return 0;
    Student_t *no = node;
    while (no != NULL && no->InfoStudent.phone_number != num) {
        printf("entrou no while");
        no = no->next;
    }
    system("pause");
    if (no == NULL) return 0;

    return 1;
}


int insere_Student(StudentsList node) {
    StudentData_t aux;

    system("clear");                                        /*name*/
    printf("Insira o nome do aluno:\n");
    fgets(aux.name, 60, stdin);
    RetiraEnter(aux.name);
    fflush(stdin);

    system("clear");                                        /*address*/
    printf("Insira o seu endereço:\n");
    fgets(aux.address, 50, stdin);

    system("clear");                                        /*data de nascimento*/
    printf("Insira a sua data de nascimento:\n");
    fgets(aux.date_of_birth, 50, stdin);

    system("clear");                                        /*phone_number*/
    printf("Insira o seu nº de phone_number:\n");
    scanf("%d", &aux.phone_number);

    if (verifica_Student(node, aux.phone_number)) {
        printf("O Student já existe");
        return 0;
    }

    if (node == NULL) return 0;
    Student_t *no = (Student_t *) malloc(sizeof(Student_t));

    if (no == NULL) return 0;
    no->InfoStudent = aux;

    if (lista_vazia_Students(node)) {                   /*insere no inicio*/
        no->next = (*node);
        *node = no;
        return 1;
    } else {
        Student_t *ant, *atual = *node;
        while (atual != NULL && atual->InfoStudent.phone_number < aux.phone_number) {
            ant = atual;
            atual = atual->next;
        }
        if (atual == *node) {//insere inicio//
            no->next = (*node);
            *node = no;
        } else {
            no->next = ant->next;
            ant->next = no;
        }
        return 1;
    }
}

int remove_Student(StudentsList *node, int num) {
    if (node == NULL) return 0;
    Student_t *ant, *no = *node;
    while (no != NULL && no->InfoStudent.phone_number != num) {
        ant = no;
        no = no->next;
    }
    if (no == NULL) return 0;

    if (no == *node)//remover o primeiro?//
        *node = no->next;
    else
        ant->next = no->next;
    free(no);
    return 1;

}

int isEmptyStudent(struct Student *head) { return head->next == NULL ? 1 : 0; }


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
