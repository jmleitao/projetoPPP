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
#include "Headers/Menus.h"
#include "Headers/TripList.h"


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
        ClearBuffer();
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
                    if (scanf("%d", &option2) == 0)
                        option2 = -1;
                    ClearConsole();

                    switch (option2) {
                        case 1:
                            AlphaSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));
                            DisplayPlacesAndPointsOfInterest(places_head);
                            break;
                        case 2:
                            PrintPlaces(student, places_head);
                            whichPlaceMenu();
                            ClearBuffer();
                            readstring(&place, 15, 5);
                            strip(&place);
                            ClearConsole();
                            AddPlace(student, places_head, place);
                            break;
                        case 3:
                            RemovePlace(student);
                            break;
                        case 4:
                            PrintandCheckPointsOfInterestList(student, places_head);
                            whichPointOfInterestMenu();
                            ClearBuffer();
                            readstring(&point_of_interest, 15, 5);
                            ClearConsole();
                            AddPointOfInterest(student, places_head, point_of_interest);
                            break;
                        case 5:
                            PrintStudentPointsOfInterest(student);
                            whichPointOfInterestRemoveMenu();
                            ClearBuffer();
                            readstring(&point_of_interest, 15, 5);
                            strip(&point_of_interest);
                            ClearConsole();
                            RemovePointOfInterest(student, point_of_interest);
                            break;
                        case 6:
                            break;
                        case 7:
                            PrintStudent(student);
                            break;
                        case 0:
                            ClearConsole();
                            ClearBuffer();
                            option2 = 0;
                            break;
                        default:
                            printf("Opção Invalida!!\n");
                    }
                    place = NULL;
                    point_of_interest = NULL;
                }
                option2 = -1;
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
        option1 = -1;
    } while (option1 != 0);
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    UserInterface();

    // Falta proteger a data o CLS e fazer a função para adicionar e remover o pdi Hot -->> Amanhã
    // Depois é fazer menus e deixar a cena bonita;

    /*
         Teste das funcionalidades Individualmente
    StudentsList students_head = BuildStudentsList();
    PlacesList places_head = BuildPlacesList();
    TripList trip_head = BuildTripList();
    StudentsList student;


    LoadPlacesList(places_head);
    LoadStudentsList(students_head);
    student = students_head->next->next;

    PlacesPopularity(places_head, students_head);
    PointsOfInterestPopularity(places_head, students_head);
    HotPointOfInterestPopularity(places_head,students_head);

    PopSortPlacesAndPointsOfInterest(&places_head,PlacesCount(places_head));
    DisplayPlacesAndPointsOfInterestWithPopularity(places_head);

    BuildTrip(trip_head,places_head,student);
    DisplayPlacesAndPointsOfInterest(trip_head->places);
    printf("Taxa de Popularidade: %.2lf %%",EvaluateTrip(trip_head,students_head,places_head));

    DeleteStudentsList(students_head);
    DeletePlacesList(places_head);
    DeletePlacesList(trip_head->places);*/

    return 0;
}
