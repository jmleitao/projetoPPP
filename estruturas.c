#include <stdio.h>
#include <stdlib.h>
#include <locale.h>    /*setlocale(LC_ALL,"Portuguese");*/
#include <string.h>
#include "estruturas.h"

/* so funciona se estiver no main*/

/*Inicializei a head da lista(primeiro node) com valores para facilitar o debug
 * caso este seja necessário*/

StudentsList BuildStudentsList() {
    StudentsList head = (StudentsList) malloc(sizeof(StudentsList));
    StudentData_t student_data;
    if (head != NULL) {
        student_data.name = "Name";
        student_data.date_of_birth = "Date of Birth";
        student_data.address = "Address";
        student_data.phone_number = -1;
        head->InfoStudent = student_data;
        head->next = NULL;
    }
    return head;
}

PlacesList BuildPlacesList() {
    PlacesList head = (PlacesList) malloc(sizeof(PlacesList));
    if (head != NULL) {
        sprintf(head->name, "%d", -1);
        sprintf(head->PointOfInterest->name, "%d", -1);
        head->PointOfInterest->WorkingHours.start_hour = -1;
        head->PointOfInterest->WorkingHours.end_hour = -1;
        head->PointOfInterest->WorkingHours.end_minute = -1;
        head->PointOfInterest->WorkingHours.end_minute = -1;
        head->next = NULL;
    }
    return head;
}

