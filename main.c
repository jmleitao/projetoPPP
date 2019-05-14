#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <time.h>

#include "Headers/structs.h"
#include "Headers/files.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/StudentsList.h"


void WelcomeMenu(void) {
    printf("+----------------------------------------------------------+\n");
    printf("|          »»»  Bem-Vindo ao Gestor de Viagens!! «««       |\n");
    printf("|                      -------------                       |\n");
    printf("|             by João Leitão and Pedro Rodrigues           |\n");
    printf("+----------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

void ByeByeMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|####################### Boa Viagem!! #######################|\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

void MainMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|            > Escolha uma das seguintes opções <            |\n");
    printf("|                                                            |\n");
    printf("|                1 - Contas de Alunos                        |\n");
    printf("|                                                            |\n");
    printf("|                2 - Viagens e Pontos de Interesse           |\n");
    printf("|                                                            |\n");
    printf("|                        0 - Sair                            |\n");
    printf("|                                                            |\n");
    printf("|                       ___________                          |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(30, 10);
}

void StudentAccountsMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|                        > Pretende <                        |\n");
    printf("|                                                            |\n");
    printf("|                 1 - Criar uma nova conta                   |\n");
    printf("|                                                            |\n");
    printf("|                 2 - Alterar dados de uma conta             |\n");
    printf("|                                                            |\n");
    printf("|                 3 - Eliminar uma conta                     |\n");
    printf("|                                                            |\n");
    printf("|                    0 - Menu Principal                      |\n");
    printf("|                                                            |\n");
    printf("|                        ___________                         |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(31, 12);
}

void StudentLoginMenu(void) {
    printf("+------------------------------------------------+\n");
    printf("|           Alteração de dados da conta!         |\n");
    printf("|      Insira o numero de telemovel da conta     |\n");
    printf("|          que vai ser sujeita a alteração.      |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 6);
}

void removeStudentMenu(void) {
    printf("+------------------------------------------------+\n");
    printf("|           Remoção de uma conta de um aluno     |\n");
    printf("|      Insira o numero de telemovel da conta     |\n");
    printf("|              que vai ser removida.             |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 6);
}

void login(void) {
    printf("+------------------------------------------------+\n");
    printf("|                >>>   LOGIN  <<<                |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 4);
}

void whichPlaceMenu(void) {
    printf("+-----------------------------------------------------+\n");
    printf("|  > Insira o nome do local que prentede adicionar <  |\n");
    printf("|                                                     |\n");
    printf("| Nome do local:                                      |\n");
    printf("+-----------------------------------------------------+\n");
    gotoxy(18, 4);
}

void whichPointOfInterestMenu(void) {
    printf("+------------------------------------------------------------------+\n");
    printf("|  > Insira o nome do ponto de interesse que prentede adicionar <  |\n");
    printf("|                                                                  |\n");
    printf("| Nome do ponto de interesse:                                      |\n");
    printf("+------------------------------------------------------------------+\n");
    gotoxy(31, 4);
}

void whichPointOfInterestRemoveMenu(void) {
    printf("+------------------------------------------------------------------+\n");
    printf("|  > Insira o nome do ponto de interesse que prentede remover <    |\n");
    printf("|                                                                  |\n");
    printf("| Nome do ponto de interesse:                                      |\n");
    printf("+------------------------------------------------------------------+\n");
    gotoxy(31, 4);
}


void tripsMenu(void) {
    printf("+----------------------------------------------------------------------+\n");
    printf("|                             > Pretende <                             |\n");
    printf("|                                                                      |\n");
    printf("|      1 - Listar Locais e Pontos de Interesse disponiveis             |\n");
    printf("|                                                                      |\n");
    printf("|      2 - Adicionar um Local                                          |\n");
    printf("|                                                                      |\n");
    printf("|      3 - Remover um Local                                            |\n");
    printf("|                                                                      |\n");
    printf("|      4 - Adicionar um Ponto de Interesse                             |\n");
    printf("|                                                                      |\n");
    printf("|      5 - Remover um Ponto de Interesse                               |\n");
    printf("|                                                                      |\n");
    printf("|      6 - Construir uma Viagem (Necessário ter 3 Locais favoritos!)   |\n");
    printf("|                                                                      |\n");
    printf("|                                                                      |\n");
    printf("|                          0 - Menu Principal                          |\n");
    printf("|                               (LOGOUT)                               |\n");
    printf("|                                                                      |\n");
    printf("|                              ___________                             |\n");
    printf("+----------------------------------------------------------------------+\n");
    gotoxy(37, 20);
}


int UserInterface(void) {
    int option1 = -1, option2 = -1, option3 = -1;
    char *phone = NULL, *key = NULL, *place = NULL, *point_of_interest = NULL;
    StudentsList student = NULL;

    StudentsList students_head = BuildStudentsList();
    PlacesList places_head = BuildPlacesList();

    LoadStudentsList(students_head);
    LoadPlacesList(places_head);

    WelcomeMenu();

    do {

        MainMenu();
        scanf("%d", &option1);
        ClearBuffer();
        ClearConsole();

        switch (option1) {
            case 1:
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
                            do {
                                ClearConsole();
                                ClearBuffer();
                                ChangeStudentInfo(students_head, key, &option3);
                            } while (option3 != 0);
                            option3 = -1;
                            ClearConsole();
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
                            printf("Opção Invalida!!\n");
                            break;
                    }
                } while (option2 != 0);
                option2 = -1;
                break;

            case 2:

                login();
                ClearBuffer();
                readstring(&phone, 9, 5);
                ClearConsole();

                student = SearchStudent(students_head, phone);
                if (student == NULL) {
                    noAccount();
                    ClearConsole();
                    option2 = 0;
                }

                phone = NULL;
                ClearBuffer();

                while (option2 != 0) {

                    tripsMenu();

                    ClearBuffer();
                    scanf("%d", &option2);

                    ClearConsole();

                    switch (option2) {
                        case 1:
                            AlphaSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));
                            DisplayPlacesAndPointsOfInterest(places_head);
                            break;
                        case 2:
                            whichPlaceMenu();
                            readstring(&place, 15, 5);
                            strip(&place);
                            ClearConsole();
                            AddPlace(student, places_head, place);
                            break;
                        case 3:
                            RemovePlace(student);
                            break;
                        case 4:
                            whichPointOfInterestMenu();
                            readstring(&point_of_interest, 15, 5);
                            strip(&point_of_interest);
                            ClearConsole();
                            AddPointOfInterest(student, places_head, point_of_interest);
                            break;
                        case 5:
                            whichPointOfInterestRemoveMenu();
                            ClearBuffer();
                            readstring(&point_of_interest, 15, 5);
                            strip(&point_of_interest);
                            ClearConsole();
                            RemovePointOfInterest(student, point_of_interest);
                            break;
                        case 6:
                            break;
                        case 0:
                            ClearConsole();
                            ClearBuffer();
                            break;
                        default:
                            printf("Opção Invalida!!\n");
                    }
                    option2 = -1;
                }
                break;


            case 0:
                LoadStudentsFile(students_head);
                LoadPlacesFile(places_head);
                DeleteStudentsList(students_head);
                DeletePlacesList(places_head);
                ByeByeMenu();
                free(key);
                free(place);
                free(phone);
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
