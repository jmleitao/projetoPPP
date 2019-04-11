//
// Created by joao on 11-04-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"

void RetiraEnter(char *str){
    int i=0;
    while(str[i]!= '\n')
        i++;
    str[i]='\0';
}

int lista_vazia_alunos(Lista_alunos *li){
    if(li == NULL || *li==NULL) return 1;
    return 0;
}

int lista_vazia_locais(Lista_locais *li){
    if(li == NULL || *li==NULL) return 1;
    return 0;
}

int verifica_aluno(Lista_alunos *node, int num){
    if(node == NULL) return 0;
    t_aluno *no = *node;
    while(no != NULL && no->DADOS_ALUNO.telefone != num){
        printf("entrou no while");
        no = no->prox;
    }
    system("pause");
    if(no == NULL) return 0;

    return 1;
}


int insere_aluno(Lista_alunos*  node){
    struct dados_aluno aux;

    system("cls");/*nome*/
    printf("Insira o nome do aluno:\n");
    fgets(aux.nome,60,stdin);
    RetiraEnter(aux.nome);
    fflush(stdin);

    system("cls");/*morada*/
    printf("Insira a sua morada:\n");
    fgets(aux.morada, 50, stdin);

    system("cls");/*telefone*/
    printf("Insira o seu nº de telefone:\n");
    scanf("%d",&aux.telefone);

    if(verifica_aluno(node, aux.telefone)){
        printf("O aluno já existe");
        return 0;
    }
    if(node == NULL) return 0;
    t_aluno *no = (t_aluno*) malloc(sizeof(t_aluno));
    if(no == NULL) return 0;
    no->DADOS_ALUNO = aux;

    if(lista_vazia_alunos(node)){//insere no inicio//
        no->prox = (*node);
        *node= no;
        return 1;
    }
    else{
        t_aluno *ant, *atual = *node;
        while(atual != NULL && atual->DADOS_ALUNO.telefone < aux.telefone){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *node){//insere inicio//
            no->prox = (*node);
            *node = no;
        }
        else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_aluno(Lista_alunos *node, int num){
    if(node == NULL) return 0;
    t_aluno *ant, *no = *node;
    while(no != NULL && no->DADOS_ALUNO.telefone != num){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;

    if(no == *node)//remover o primeiro?//
        *node = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;

}

