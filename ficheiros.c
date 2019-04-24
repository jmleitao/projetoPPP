//
// Created by joao on 27-03-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estruturas.h"
#include "ficheiros.h"


int listar_Places(){
    FILE *fp;
    fp  = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/Places.txt","r");

    char linha[256];
    while ((fgets(linha, sizeof(linha),fp) != NULL)){
        printf("%s",linha);
    }
    fclose(fp);
}

int carrega_StudentsList(StudentsList *node){
    FILE *fp;
    fp = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/Students", "r");

    Student_t *no = (Student_t*) malloc(sizeof(Student_t));

    while((fscanf(fp,"%s",no->InfoStudent.name))!=EOF){

        fscanf(fp,"%d %s %s",&(no->InfoStudent.phone_number),(no->InfoStudent.date_of_birth),(no->InfoStudent.address));

        if((*node)== NULL ){
            no->next = (*node);
            *node = no;
        }
        else{
            Student_t *aux = *node;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = no;
        }

        Student_t *no = (Student_t*) malloc(sizeof(Student_t));

    }
    return 1;

    fclose(fp);
}

int carrega_ficheiro_Students(StudentsList *node){
    FILE *fp;
    fp = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/Students", "w");

    if(node == NULL) return 0;
    Student_t *copia= *node;

    while(copia != NULL){

        fprintf(fp,"%s ",copia->InfoStudent.name);
        fprintf(fp,"%d",copia->InfoStudent.phone_number);
        fprintf(fp," %s",copia->InfoStudent.date_of_birth);
        fprintf(fp," %s",copia->InfoStudent.address);
        copia=copia->next;
    }
    fclose(fp);
    return 1;
}