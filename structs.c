#include <stdio.h>
#include <stdlib.h>
#include <locale.h>    /*setlocale(LC_ALL,"Portuguese");*/
#include <string.h>
#include "Headers/structs.h"

/* so funciona se estiver no main*/

/*Inicializei a head da lista(primeiro node) com valores para facilitar o debug
 * caso este seja necessário*/

StudentsList BuildStudentsList(void) {
    StudentsList head = (StudentsList) malloc(sizeof(StudentsList));
    StudentData_t student_data;

    student_data.name = "Name";
    student_data.date_of_birth = "Date of Birth";
    student_data.address = "Address";
    student_data.phone_number = "Phone Number";

    if (head != NULL) {
        head->InfoStudent = student_data;
        head->next = NULL;
    }
    return head;
}

PlacesList BuildPlacesList(void) {
    PlacesList head = (PlacesList) malloc(sizeof(PlacesList));
    Places_t place_data;

    place_data.name = "City Name";

    if (head != NULL) {
        head->name = place_data.name;
        head->next = NULL;
    }
    return head;
}

PointsOfInterestList BuildPointsOfInterestList(void){
    PointsOfInterestList head = (PointsOfInterestList) malloc(sizeof(PointsOfInterestList));
    PointsOfInterest_t point_of_interest_data;

    point_of_interest_data.name = "Name";
    point_of_interest_data.info = "Info";
    point_of_interest_data.WorkingHours.start_hour = -1;
    point_of_interest_data.WorkingHours.end_hour = -1;          // same here ¯\_(ツ)_/¯
    point_of_interest_data.WorkingHours.start_minute = -1;
    point_of_interest_data.WorkingHours.end_minute = -1;

    if(head != NULL){
        head->info = point_of_interest_data.info;
        head->name = point_of_interest_data.name;
        head->WorkingHours = point_of_interest_data.WorkingHours;
        head->next = NULL;

    }
    return head;
}

