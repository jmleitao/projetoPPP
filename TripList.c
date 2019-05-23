#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/structs.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"
#include "Headers/TripList.h"
#include "Headers/files.h"
#include "Headers/StudentsList.h"
#include "Headers/functions.h"

#define POINTS_OF_INTEREST_PER_PLACE 3

// Função que cria um node da lista ligada de viagens
PlacesList CreateNodeForTripList(PlacesList place) {
    PlacesList newPlace = (PlacesList) malloc(sizeof(Places_t));
    mallocFail(newPlace);
    newPlace->name = place->name;
    newPlace->Popularity = place->Popularity;
    newPlace->PointOfInterest = BuildPointsOfInterestList();
    newPlace->next = NULL;
    return newPlace;
}
// Função que constroi a viagem se todas as confições forem verificadas nomeadamente (Has3FavoritePlaces)
// o utilizador ter 3 locais favoritos
int BuildTrip(TripList trip_head, PlacesList places_head, StudentsList student) {
    PlacesList newPlace, place, current_place = trip_head->places;
    PointsOfInterestList newPointOfInterest, point_of_interest, current, aux;
    int i, num;

    for (i = 0; i < 3; i++) {
        num = POINTS_OF_INTEREST_PER_PLACE;
        if ((place = SearchPlace(places_head, student->InfoInterests.favorite_places[i])) != NULL) {

            newPlace = CreateNodeForTripList(place);
            current = newPlace->PointOfInterest;

            if ((newPointOfInterest = SearchPointOfInterest(place->PointOfInterest, student->InfoInterests.hot)) !=
                NULL) {
                AppendToPointsOfInterestList(current, newPointOfInterest);
                num--;
            }

            point_of_interest = student->InfoInterests.other_points_of_interest->next;
            while (point_of_interest != NULL && num != 0) {

                if ((newPointOfInterest = SearchPointOfInterest(place->PointOfInterest, point_of_interest->name)) !=
                    NULL) {
                    AppendToPointsOfInterestList(current, newPointOfInterest);
                    num--;
                }
                point_of_interest = point_of_interest->next;
            }

            aux = place->PointOfInterest->next;
            while (num != 0 && aux != NULL) {
                if ((SearchPointOfInterest(current, aux->name)) == NULL) {
                    newPointOfInterest = aux;
                    AppendToPointsOfInterestList(current, newPointOfInterest);
                    num--;
                }
                aux = aux->next;
            }
            newPlace->PointOfInterest = current;
            current_place->next = newPlace;
            current_place = current_place->next;
        }
    }
    return 0;
}
// ##############   Funções Utilizadas para calcular a popularidades da viagem  ################

double UsersWithOneFavPlaceInTrip(TripList trip_head, StudentsList students_head) {
    int i, found, num_students = StudentCount(students_head);
    double answer = 0;
    StudentsList current = students_head->next;
    PlacesList trip;
    while (current != NULL) {
        found = 0;
        trip = trip_head->places->next;
        for (i = 0; i < NUM_PLACES && found != 1; i++) {
            while (trip != NULL && found != 1) {
                if (strcmp(current->InfoInterests.favorite_places[i], trip->name) == 0) {
                    found = 1;
                    answer += 1;
                }
                trip = trip->next;
            }
        }
        current = current->next;
    }
    answer = (answer / num_students) * 100;
    return answer;
}

double UsersWithHotPointOfInterestInTrip(TripList trip_head, StudentsList students_head) {
    int found, num_students = StudentCount(students_head);
    double answer = 0;
    StudentsList current_student = students_head->next;
    PlacesList trip = trip_head->places;
    while (current_student != NULL) {
        found = 0;
        while (trip != NULL && found != 1) {
            if (SearchPointOfInterest(trip->PointOfInterest, current_student->InfoInterests.hot) != NULL) {
                found = 1;
                answer += 1;
            }
            trip = trip->next;
        }
        current_student = current_student->next;
    }
    answer = (answer / num_students) * 100;
    return answer;
}

double PointsOfInterestPreference(TripList trip_head, PlacesList places_head) {
    double total_popularity_points_count = 0, trip_popularity_points_count = 0;
    double answer = 0;
    PlacesList current_place = places_head->next;
    PointsOfInterestList current_point_of_interest;

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        while (current_point_of_interest != NULL) {
            total_popularity_points_count += current_point_of_interest->Popularity;

            current_point_of_interest = current_point_of_interest->next;
        }
        current_place = current_place->next;
    }

    current_place = trip_head->places->next;

    while (current_place != NULL) {
        current_point_of_interest = current_place->PointOfInterest->next;
        while (current_point_of_interest != NULL) {
            trip_popularity_points_count += current_point_of_interest->Popularity;

            current_point_of_interest = current_point_of_interest->next;
        }
        current_place = current_place->next;
    }
    answer = ((trip_popularity_points_count / total_popularity_points_count) * 100);
    return answer;
}

double EvaluateTrip(TripList trips_head, StudentsList students_head, PlacesList places_head) {
    double value1 = UsersWithOneFavPlaceInTrip(trips_head, students_head);
    double value2 = UsersWithHotPointOfInterestInTrip(trips_head, students_head);
    double value3 = PointsOfInterestPreference(trips_head, places_head);
    double average = (value1 + value2 + value3) / 3;
    return average;
}

int ResetPopularity(PlacesList head) {
    PlacesList current_place = head->next;
    PointsOfInterestList current_point_of_interest;

    while (current_place != NULL) {
        current_place->Popularity = 0;
        current_point_of_interest = current_place->PointOfInterest;
        while (current_point_of_interest != NULL) {
            current_point_of_interest->Popularity = 0;
            current_point_of_interest = current_point_of_interest->next;
        }
        current_place = current_place->next;
    }
    return 0;
}