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
    int lines, option1 = -1, option2 = -1, option3 = -1;
    double popularity;
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
                            break;

                        default:
                            ClearConsole();
                            invalidOption();
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

                    ResetPopularity(places_head);

                    PlacesPopularity(places_head, students_head);
                    PointsOfInterestPopularity(places_head, students_head);
                    HotPointOfInterestPopularity(places_head, students_head);

                    tripsMenu();

                    ClearBuffer();
                    if (scanf("%d", &option2) == 0)
                        option2 = -1;
                    ClearConsole();

                    switch (option2) {

                        case 1:
                            while (option3 != 0) {

                                whichListingMenu();

                                ClearBuffer();
                                if (scanf("%d", &option3) == 0)
                                    option3 = -1;
                                ClearConsole();

                                switch (option3) {
                                    case 1:
                                        AlphaSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));
                                        DisplayPlacesAndPointsOfInterest(places_head);
                                        break;
                                    case 2:
                                        PopSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));
                                        DisplayPlacesAndPointsOfInterestWithPopularity(places_head);
                                        break;
                                    case 0:
                                        ClearBuffer();
                                        option3 = 0;
                                        break;
                                    default:
                                        ClearConsole();
                                        invalidOption();
                                        break;
                                }
                            }
                            option3 = -1;
                            break;

                        case 2:
                            while (option3 != 0) {

                                whichPlaceMenu();

                                ClearBuffer();
                                if (scanf("%d", &option3) == 0)
                                    option3 = -1;
                                ClearConsole();

                                switch (option3) {
                                    case 1:
                                        lines = PrintPlaces(student, places_head);
                                        addPlaceMenu(lines);
                                        ClearBuffer();
                                        readstring(&place, 15, 5);
                                        strip(&place);
                                        ClearConsole();
                                        AddPlace(student, places_head, place);
                                        break;
                                    case 2:
                                        RemovePlace(student);
                                        break;
                                    case 0:
                                        ClearBuffer();
                                        option3 = 0;
                                        break;
                                    default:
                                        ClearConsole();
                                        invalidOption();
                                        break;
                                }
                            }
                            option3 = -1;
                            break;

                        case 3:

                            while (option3 != 0) {

                                whichPointOfInterestMenu();

                                ClearBuffer();
                                if (scanf("%d", &option3) == 0)
                                    option3 = -1;
                                ClearConsole();

                                switch (option3) {
                                    case 1:
                                        PrintandCheckPointsOfInterestList(student, places_head);
                                        addPointOfInterestMenu();
                                        ClearBuffer();
                                        readstring(&point_of_interest, 15, 5);
                                        ClearConsole();
                                        AddPointOfInterest(student, places_head, point_of_interest);
                                        break;
                                    case 2:
                                        PrintandCheckPointsOfInterestList(student, places_head);
                                        addPointOfInterestMenu();
                                        ClearBuffer();
                                        readstring(&point_of_interest, 15, 5);
                                        ClearConsole();
                                        AddHotPointOfInterest(student, point_of_interest);
                                        break;
                                    case 3:
                                        RemoveHotPointOfInterest(student);
                                        break;
                                    case 4:
                                        lines = PrintStudentPointsOfInterest(student);
                                        removePointOfInterestMenu(lines);
                                        ClearBuffer();
                                        readstring(&point_of_interest, 15, 5);
                                        strip(&point_of_interest);
                                        ClearConsole();
                                        RemovePointOfInterest(student, point_of_interest);
                                        break;
                                    case 0:
                                        ClearBuffer();
                                        option3 = 0;
                                        break;
                                    default:
                                        ClearConsole();
                                        invalidOption();
                                        break;
                                }
                            }
                            option3 = -1;
                            break;

                        case 4:
                            if (Has3FavoritePlaces(student))
                                morePlacesNeeded();
                            else {
                                TripList trip_head = BuildTripList();
                                PopSortPlacesAndPointsOfInterest(&places_head, PlacesCount(places_head));

                                while (option3 != 0) {

                                    TripMenu();

                                    ClearBuffer();
                                    if (scanf("%d", &option3) == 0)
                                        option3 = -1;
                                    ClearConsole();

                                    switch (option3) {
                                        case 1:
                                            BuildTrip(trip_head, places_head, student);
                                            successBuildTrip();
                                            break;
                                        case 2:
                                            if (isEmptyPlaces(trip_head->places))
                                                buildTripFirst();
                                            else {
                                                myTrip();
                                                DisplayPlacesAndPointsOfInterest(trip_head->places);
                                                justPause();
                                                ClearConsole();
                                            }
                                            break;
                                        case 3:
                                            if (isEmptyPlaces(trip_head->places))
                                                buildTripFirst();
                                            else {
                                                popularity = EvaluateTrip(trip_head, students_head, places_head);
                                                popularityDisplay(popularity);
                                                justPause();
                                                ClearBuffer();
                                                getchar();
                                                ClearConsole();
                                            }break;
                                        case 0:
                                            ClearBuffer();
                                            option3 = 0;
                                            break;
                                        default:
                                            ClearConsole();
                                            invalidOption();
                                            break;
                                    }
                                }
                                DeletePlacesList(trip_head->places);
                                option3 = -1;
                                break;
                            }
                            break;
                        case 5:
                            PrintStudent(student);
                            break;
                        case 0:
                            ClearConsole();
                            ClearBuffer();
                            option2 = 0;
                            break;
                        default:
                            ClearConsole();
                            invalidOption();
                            break;
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
                free(point_of_interest);
                option1 = 0;
                break;
            default:
                ClearConsole();
                invalidOption();
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
