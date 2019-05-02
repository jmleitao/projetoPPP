#include <stdio.h>
#include <stdlib.h>
#include <locale.h>    /*setlocale(LC_ALL,"Portuguese");*/
#include <string.h>
#include "Headers/structs.h"

/* so funciona se estiver no main*/

/*Inicializei a head da lista(primeiro node) com valores para facilitar o debug
 * caso este seja necessário*/

StudentsList BuildStudentsList(void) {
    StudentsList head = (StudentsList) malloc(sizeof(Student_t));
    StudentData_t student_data;
    Student_Interests_t student_interests;

    student_data.name = "Name";
    student_data.date_of_birth = "Date of Birth";
    student_data.address = "Address";
    student_data.phone_number = "Phone Number";
    student_interests.hot = "Hot";
    student_interests.favorite_places[0] = "Place1";
    student_interests.favorite_places[1] = "Place2";
    student_interests.favorite_places[2] = "Place3";
    student_interests.other_points_of_interest[0] = "Hot";
    student_interests.other_points_of_interest[0] = "Other Points of Interest";
    student_interests.num_points = 2;

    if (head != NULL) {
        head->InfoStudent = student_data;
        head->InfoInterests = student_interests;
        head->StudentCount = -1;
        head->next = NULL;
    }
    return head;
}

PointsOfInterestList BuildPointsOfInterestList(void) {
    PointsOfInterestList head = (PointsOfInterestList) malloc(sizeof(PointsOfInterest_t));
    PointsOfInterest_t point_of_interest_data;
    Hour_t working_hours;

    point_of_interest_data.name = "Name";
    point_of_interest_data.info = "Info";
    point_of_interest_data.WorkingHours.OpeningHour = "Opening Hour";
    point_of_interest_data.WorkingHours.ClosingHour = "Closing Hour";


    if (head != NULL) {
        head->info = point_of_interest_data.info;
        head->name = point_of_interest_data.name;
        head->WorkingHours = point_of_interest_data.WorkingHours;
        head->next = NULL;

    }
    return head;
}

PlacesList BuildPlacesList(void) {
    PlacesList head = (PlacesList) malloc(sizeof(Places_t));
    Places_t place_data;

    place_data.name = "City Name";
    if (head != NULL) {
        head->PointOfInterest = BuildPointsOfInterestList();
        head->name = place_data.name;
        head->next = NULL;
    }
    return head;
}


