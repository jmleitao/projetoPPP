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

void ByeByeMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|####################### Boa Viagem!! #######################|\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    ClearConsole();
}

void MainMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|             > Escolha uma das seguintes opções <           |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        1 - Contas de Utilizadores          |\n");
    printf("\t\t\t\t\t\t\t\t\t|                        2 - Viagens e Pontos de Interesse   |\n");
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

void removeStudentMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t\t |           Remoção de uma conta de um aluno     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |      Insira o numero de telemovel da conta     |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |              que vai ser removida.             |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |                                                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t | Numero de Telemovel:                           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    gotoxy(25, 13);
}

void login(void) {
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t\t |                >>>   LOGIN  <<<                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t |                                                |\n");
    printf("\t\t\t\t\t\t\t\t\t\t | Numero de Telemovel:                           |\n");
    printf("\t\t\t\t\t\t\t\t\t\t +------------------------------------------------+\n");
    gotoxy(25, 13);
}

void tripsMenu(void) {
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    printf("\t\t\t\t\t\t\t\t\t|                        > Pretende <                        |\n");
    printf("\t\t\t\t\t\t\t\t\t|      1 - Listar Locais e Pontos de Interesse disponiveis   |\n");
    printf("\t\t\t\t\t\t\t\t\t|                 2 - Adicionar um Local                     |\n");
    printf("\t\t\t\t\t\t\t\t\t|             3 - Adicionar um Ponto de Interesse            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                4 - Construir uma Viagem                    |\n");
    printf("\t\t\t\t\t\t\t\t\t|              (Necessário ter 3 Locais favoritos!)          |\n");
    printf("\t\t\t\t\t\t\t\t\t|                                                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                    0 - Menu Principal                      |\n");
    printf("\t\t\t\t\t\t\t\t\t|                          (LOGOUT)                          |\n");
    printf("\t\t\t\t\t\t\t\t\t|                                                            |\n");
    printf("\t\t\t\t\t\t\t\t\t|                         ==========                         |\n");
    printf("\t\t\t\t\t\t\t\t\t+------------------------------------------------------------+\n");
    gotoxy(102, 6);
}


int UserInterface(void) {
    int option1 = -1, option2 = -1;
    char *phone = NULL, *key = NULL;
    StudentsList student = NULL;

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
                if(students_head->next == NULL)
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
                            readstring(&key, 9, 5);
                            RemoveStudent(students_head, key);
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
                if(students_head->next == NULL)
                    LoadStudentsList(students_head);
                if(places_head->next == NULL)
                    LoadPlacesList(places_head);

                login();
                readstring(&phone, 9, 5);

                student = SearchStudent(students_head, phone);
                phone = NULL;

                ClearBuffer();
                ClearConsole();

                while (option2 != 0) {

                    tripsMenu();
                    scanf("%d", &option2);

                    ClearConsole();
                    ClearBuffer();

                    switch (option2) {
                        case 1:
                            AlphaSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));
                            DisplayPlacesAndPointsOfInterest(places_head);
                            break;
                        case 2:
                            AddPlace(student,"Porto");
                            break;
                        case 0:
                            break;
                        default:
                            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t   Opção Invalida!!\n");
                    }
                }
                break;

            case 0:
                LoadStudentsFile(students_head);
                //LoadPlacesFile(places_head);
                DeleteStudentsList(students_head);
                DeletePlacesList(places_head);
                ByeByeMenu();
                free(key);
                free(phone);
                free(student);
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
    return 0;
}
