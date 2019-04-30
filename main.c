#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio_ext.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/StudentsList.h"


void menu1(void) {
    printf("\tEscolha uma das seguintes opções:\n\n");
    printf("\t1 - Alunos\n");
    printf("\t2 - Viagens\n");
    printf("\t0 - Sair\n");
}

void menu2(void) {
    printf("\tPretende:\n\n");
    printf("\t1 - Criar Student\n");
    printf("\t2 - Alterar data de Student\n");
    printf("\t3 - Apagar Student\n");
    printf("\t0 - Menu Principal\n");
}

void menu3(void) {
    system("clear");
    printf("\tPretende:\n\n");
    printf("\t1 - Mostrar os Places disponíveis\n");
}


int UserInterface(void) {
    int option1, option2;
    char * phone;
    StudentsList students_head = BuildStudentsList();
    PlacesList places_head = BuildPlacesList();
    //PointsOfInterestList pdi_head = BuildPointsOfInterestList();

    do {

        menu1();
        scanf("%d", &option1);
        ClearBuffer();

        switch (option1) {

            case 1:
                do {
                    LoadStudentsList(students_head);
                    menu2();
                    scanf("%d", &option2);
                    ClearBuffer();
                    ClearConsole();

                    if (option2 == 1) {
                        AddStudent(students_head);
                        system("pause");

                    } else if (option2 == 2) {
                        printf("Mudar a data!\n");
                        system("pause");

                    } else if (option2 == 3) {
                        ClearConsole();
                        printf("Insira o numero de telemovel do aluno a remover:\n");
                        scanf("%s", phone);
                        if (SearchStudent(students_head, phone) != NULL) {
                            RemoveStudent(students_head, phone);
                            printf("O aluno foi removido com sucesso!\n");
                        } else {

                            printf("O numero de telemovel do aluno que inseriu não existe\n");
                            system("pause");
                        }
                        system("pause");
                    } else {

                        printf("entrou no else");
                        ClearBuffer();
                        system("pause");
                    }
                } while (option2 != 0);
                break;

            case 2:
                do {
                    menu3();
                    scanf("%d", &option2);
                    ClearBuffer();

                    if (option2 == 1) {
                        ClearBuffer();
                        PrintPlaces(places_head);
                        system("pause");
                    } else if (option2 == 2) {
                        system("pause");
                    } else {
                        option2 = '0';
                        ClearBuffer();
                        printf("entrou no else");
                        system("pause");
                    }
                } while (option2 != 0);
                break;

            case 0:
                LoadStudentsFile(students_head);
                DeleteStudentsList(students_head);
                //exit(1);
                break;

            default:
                ClearConsole();
                break;
        }
    } while (option1 != 0);
    return 0;
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    UserInterface();
    return 0;
}