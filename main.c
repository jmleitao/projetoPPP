#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"

void menu(){
    printf("\tEscolha uma das seguintes opções:\n\n");
    printf("\t1 - Alunos\n");
    printf("\t2 - Viagens\n");
    printf("\t0 - Sair\n");
}

void ler_string(char string[],int size){
    int i;
    char c;

    for(i=0;i<size;i++){
        scanf("%c",&c);
        if(c=='\n'){
            string[i]='\0';
            break;
        }

        string[i]=c;
    }
    string[i]='\0';
}

void escolher_opt(char *opt){

    Lista_alunos *node_alunos;
    node_alunos = cria_lista_alunos();

    Lista_locais *node_local;
    node_local = cria_lista_locais();

    //carrega_lista_alunos(node_alunos);

    while (1){
        menu();
        int size=2;
        char opt2='0';
        char str[size];
        ler_string(str,size);
        fflush(stdin);
        if(str[1]!='\0') *opt = 'a';
        else
            *opt= str[0];
        switch(*opt){
            case '1':
                while(opt2=='0'){
                    system("CLS");
                    printf("\tPretende:\n\n");
                    printf("\t1 - Criar Aluno\n");
                    printf("\t2 - Alterar dados de Aluno\n");
                    printf("\t3 - Apagar Aluno\n");
                    ler_string(str,size);
                    fflush(stdin);
                    if(str[1] != '0')
                        opt2 = 'a';
                    else {
                        opt2 = str[0];
                        if (opt2 == '1') {
                            insere_aluno(node_alunos);
                            system("pause");
                        }
                        else if(opt2 == '2'){
                            system("pause");
                        }
                        else if(opt2 == '3'){
                            system("pause");
                        }
                    }
                }
                break;
            case '2':
                while (opt2=='0'){
                    system("CLS");
                }
                break;
            case '0':
                exit(1);
                break;
            default:
                system("CLS");
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opt;
    escolher_opt(&opt);
    return 1;
}