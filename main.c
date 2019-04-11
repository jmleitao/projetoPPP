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

    carrega_lista_alunos(node_alunos);

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
                    system("clear");
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
                            int n;
                            system("clear");
                            printf("Insira o telefone do aluno a remover:\n");
                            scanf("%d",&n);
                            if(verifica_aluno(node_alunos,n)){
                                remove_aluno(node_alunos,n);
                                printf("O aluno foi removido com sucesso!\n");
                            } else{

                                printf("O telefone de aluno que inseriu não existe\n");
                                system("pause");
                            }
                            system("pause");
                        } else{

                            printf("entrou no else");
                            fflush(stdin);
                            system("pause");
                        }
                    }
                }
                break;
            case '2':
                while (opt2=='0'){
                    system("clear");
                    printf("\tPretende:\n\n");
                    printf("\t1 - Mostrar os Locais disponíveis\n");
                    ler_string(str,size);
                    fflush(stdin);
                    if(str[1] != '0')
                        opt2 = 'a';

                    else{
                        opt2=str[0];

                        if(opt2 == '1'){
                            system("clear");
                            listar_locais();
                            system("pause");
                        }
                        else if(opt2 == '2'){
                            system("pause");
                        }
                        else{
                            opt2='0';
                            system("clear");
                            printf("entrou no else");
                            system("pause");
                        }
                    }
                }
                break;
            case '0':
                carrega_ficheiro_alunos(node_alunos);
                libera_alunos(node_alunos);
                exit(1);
                break;
            default:
                system("clear");
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