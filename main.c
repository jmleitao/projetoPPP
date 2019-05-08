#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/StudentsList.h"


void WelcomeMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|          »»»  Bem-Vindo ao Gestor de Viagens!! «««         |\n");
    printf("\t\t\t\t\t\t\t\t\t|              by João Leitão and Pedro Rodrigues            |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    while ((clock() / CLOCKS_PER_SEC) != 2);
    ClearConsole();
}

void MainMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|             > Escolha uma das seguintes opções <           |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        1 - Alunos                          |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        2 - Viagens                         |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        0 - Sair                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                                                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        ==========                          |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    gotoxy(102, 6);
}

void StudentAccountsMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|                        > Pretende <                        |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 1 - Criar uma nova conta                   |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 2 - Alterar dados de uma conta             |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 3 - Eliminar uma conta                     |\n");
    printf("\t\t\t\t\t\t\t\t\t|                    0 - Menu Principal                      |\n");
    printf("\t\t\t\t\t\t\t\t\t|                                                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                         ==========                         |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    gotoxy(102, 6);
}

void StudentLoginMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t\t |           Alteração de dados da conta!         |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |      Insira o numero de telemovel da conta     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |          que vai ser sujeita a alteração.      |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |                                                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t | Numero de Telemovel:                           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    gotoxy(25, 13);
}

void removeStudentMenu(void){
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t\t |           Remoção de uma conta de um aluno     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |      Insira o numero de telemovel da conta     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |              que vai ser removida.             |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |                                                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t | Numero de Telemovel:                           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    gotoxy(25, 13);
}

void menu3(void) {
    system("clear");
    printf("\tPretende:\n\n");
    printf("\t1 - Mostrar os Places disponíveis\n");
}


int UserInterface(void) {
    int option1, option2;
    char *key;

    StudentsList students_head = BuildStudentsList();
    PlacesList places_head = BuildPlacesList();

    WelcomeMenu();

    do {

        MainMenu();
        scanf("%d", &option1);
        ClearBuffer();
        ClearConsole();

        switch (option1) {
            case 1:
                LoadStudentsList(students_head);
                do {

                    StudentAccountsMenu();
                    scanf("%d", &option2);

                    ClearBuffer();
                    ClearConsole();

                    switch (option2) {

                        case 1:
                            AddStudent(students_head);
                            ClearConsole();
                            ClearBuffer();
                            break;

                        case 2:
                            StudentLoginMenu();
                            readstring(&key, 9, 5);
                            ChangeStudentInfo(students_head, key);
                            ClearConsole();
                            ClearBuffer();
                            break;

                        case 3:
                            removeStudentMenu();
                            readstring(&key,9,5);
                            if(SearchStudent(students_head,key) != NULL) {
                                RemoveStudent(students_head, key);
                            }
                            else
                                printf("\t\t\t\t\t\t\t\t\t\tO Estudante com esse numero não se encontra registado\n");
                            ClearConsole();
                            ClearBuffer();
                            break;
                        case 0:
                            option2 = 0;
                            ClearBuffer();
                            ClearBuffer();
                            break;

                        default:
                            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t   Opção Invalida!!\n");
                            break;
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
                    }
                } while (option2 != 0);
                break;

            case 0:
                LoadStudentsFile(students_head);
                DeleteStudentsList(students_head);
                exit(0);

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
    /*PlacesList places_head= BuildPlacesList();
    LoadPlacesList(places_head);
    PlacesCount(places_head);
    AlphaSortPlacesAndPointsOfInterest(&places_head,PlacesCount(places_head));
    DeletePlacesList(places_head);4*/
    /*
    StudentsList head = BuildStudentsList();
    LoadStudentsList(head);
    AddStudent(head);
    LoadStudentsFile(head);
    DeleteStudentsList(head);*/
    return 0;
}


/*
 * printf("Insira o numero de telemovel do aluno a remover:\n");
                        scanf("%s", phone);
                        if (SearchStudent(students_head, phone) != NULL) {
                            RemoveStudent(students_head, phone);
                            printf("O aluno foi removido com sucesso!\n");
                        } else {

                            printf("O numero de telemovel do aluno que inseriu não existe\n");
                        }
 */