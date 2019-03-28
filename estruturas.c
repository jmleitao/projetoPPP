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

Lista_locais  * cria_lista_locais(){
    Lista_locais  *node_local= (Lista_locais*)malloc(sizeof(Lista_locais));
    if(node_local!=NULL)
        *node_local = NULL;
    return node_local;
}
