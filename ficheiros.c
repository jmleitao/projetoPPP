//
// Created by joao on 27-03-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "estruturas.h"
#include "ficheiros.h"


/*int carrega_lista_alunos(Lista_alunos *node)
{
    FILE *fp;
    fp = fopen("", "r");

    t_aluno *no = (t_aluno*) malloc(sizeof(t_aluno));

    while((fscanf(fp,"%s",no->DADOS_ALUNO.nome))!=EOF){

        fscanf(fp,"%s %p %d %d",&(no->DADOS_ALUNO.nome),&(no->DADOS_ALUNO.morada),&(no->DADOS_ALUNO.data),&(no->DADOS_ALUNO.telefone));

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
}*/
