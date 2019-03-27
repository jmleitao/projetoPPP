//
// Created by joao on 27-03-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>    /*setlocale(LC_ALL,"Portuguese");*/
#include <string.h>
#include "estruturas.h"

Lista_alunos * cria_lista_alunos()/* so funciona se estiver no main*/
{
    Lista_alunos *node =(Lista_alunos*)malloc(sizeof(Lista_alunos));
    if(node!=NULL)
        *node=NULL;
    return node;
}

Lista_viagens  * cria_lista_viagens(){
    Lista_viagens  *node_viagem= (Lista_viagens*)malloc(sizeof(Lista_viagens));
    if(node_viagem!=NULL)
        *node_viagem = NULL;
    return node_viagem;
}
