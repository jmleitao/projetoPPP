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
