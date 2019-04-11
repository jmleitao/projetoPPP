//
// Created by joao on 27-03-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estruturas.h"
#include "ficheiros.h"


int listar_locais(){
    FILE *fp;
    fp  = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/locais.txt","r");

    char linha[256];
    while ((fgets(linha, sizeof(linha),fp) != NULL)){
        printf("%s",linha);
    }
    fclose(fp);
}

int carrega_lista_alunos(Lista_alunos *node){
    FILE *fp;
    fp = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/alunos", "r");

    t_aluno *no = (t_aluno*) malloc(sizeof(t_aluno));

    while((fscanf(fp,"%s",no->DADOS_ALUNO.nome))!=EOF){

        fscanf(fp,"%d %s %s",&(no->DADOS_ALUNO.telefone),(no->DADOS_ALUNO.data_nasc),(no->DADOS_ALUNO.morada));

        if((*node)== NULL ){
            no->prox = (*node);
            *node = no;
        }
        else{
            t_aluno *aux = *node;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = no;
        }

        t_aluno *no = (t_aluno*) malloc(sizeof(t_aluno));

    }
    return 1;

    fclose(fp);
}

int carrega_ficheiro_alunos(Lista_alunos *node){
    FILE *fp;
    fp = fopen("/home/joao/Desktop/Curso/3ºAno/2ºSemestre/PPP/Projeto/alunos", "w");

    if(node == NULL) return 0;
    t_aluno *copia= *node;

    while(copia != NULL){

        fprintf(fp,"%s ",copia->DADOS_ALUNO.nome);
        fprintf(fp,"%d",copia->DADOS_ALUNO.telefone);
        fprintf(fp," %s",copia->DADOS_ALUNO.data_nasc);
        fprintf(fp," %s",copia->DADOS_ALUNO.morada);
        copia=copia->prox;
    }
    fclose(fp);
    return 1;
}