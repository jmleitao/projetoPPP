#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "estruturas.h"
#include "ficheiros.h"
#include "funcoes.h"

void menu(){
    printf("\tEscolha uma das seguintes opções:\n\n");
    printf("\t1 - Students\n");
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

    StudentsList *node_Students;
    node_Students = BuildStudentsList();

    PlacesList *node_local;
    node_local = BuildPlacesList();

    carrega_StudentsList(node_Students);

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
                    printf("\t1 - Criar Student\n");
                    printf("\t2 - Alterar data de Student\n");
                    printf("\t3 - Apagar Student\n");
                    ler_string(str,size);
                    fflush(stdin);
                    if(str[1] != '0')
                        opt2 = 'a';
                    else {
                        opt2 = str[0];
                        if (opt2 == '1') {
                            insere_Student(node_Students);
                            system("pause");
                        }
                        else if(opt2 == '2'){
                            system("pause");
                        }
                        else if(opt2 == '3'){
                            int n;
                            system("clear");
                            printf("Insira o phone_number do Student a remover:\n");
                            scanf("%d",&n);
                            if(verifica_Student(node_Students,n)){
                                remove_Student(node_Students,n);
                                printf("O Student foi removido com sucesso!\n");
                            } else{

                                printf("O phone_number de Student que inseriu não existe\n");
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
                    printf("\t1 - Mostrar os Places disponíveis\n");
                    ler_string(str,size);
                    fflush(stdin);
                    if(str[1] != '0')
                        opt2 = 'a';

                    else{
                        opt2=str[0];

                        if(opt2 == '1'){
                            system("clear");
                            listar_Places();
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
                carrega_ficheiro_Students(node_Students);
                libera_Students(node_Students);
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
