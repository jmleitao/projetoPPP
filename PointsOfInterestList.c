#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "Headers/structs.h"
#include "Headers/functions.h"
#include "Headers/PointsOfInterestList.h"
#include "Headers/PlacesList.h"



int getInfoPointOfInterest(PointsOfInterest_t *point_of_interest_data) {
    //const int size = 60;

    system("clear");
    printf("Insira o nome do Ponto de Interse:");
    //fgets(point_of_interest_data->name,size,stdin);
    readstring(&point_of_interest_data->name, 30, 20);
    ClearBuffer();

    system("clear");
    printf("Insira a sua descrição do Ponto de Interesse: ");
    //fgets(point_of_interest_data->info,size,stdin);
    readstring(&point_of_interest_data->info, 30, 20);
    ClearBuffer();

    system("clear");
    printf("Insira a sua Horario de Funcionamento do Ponto de Interesse: ");
    printf("Hora de Abertura\n\t\tno formato (hh:mm): ");
    readstring(&point_of_interest_data->WorkingHours.OpeningHour, 30, 20);
    ClearBuffer();
    printf("Hora de Fecho\n\t\tno formato (hh:mm): ");
    readstring(&point_of_interest_data->WorkingHours.OpeningHour, 30, 20);

    return 0;
}


int AddPointOfInterest(PlacesList head, PlacesList city) {
    PointsOfInterest_t point_of_interest_data;
    PlacesList current = head;
    PlacesList newPlace = (PlacesList) malloc(sizeof(Places_t));


    if (SearchPlace(head, city->name) == NULL) {

        getInfoPointOfInterest(&point_of_interest_data);

        newPlace->PointOfInterest->name = point_of_interest_data.name;
        newPlace->PointOfInterest->info = point_of_interest_data.info;
        newPlace->PointOfInterest->WorkingHours = point_of_interest_data.WorkingHours;
        newPlace->next = NULL;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPlace;

    } else {
        printf("O local já existe\n");
    }
    return 0;
}
