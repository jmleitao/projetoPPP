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
    if (head != NULL) {
        sprintf(head->InfoStudent.name, "%d", -1);
        sprintf(head->InfoStudent.address, "%d", -1);
        sprintf(head->InfoStudent.date_of_birth, "%d", -1);
        head->InfoStudent.phone_number = -1;
        head->next = NULL;
    }
    return head;
}

PlacesList BuildPlacesList() {
    PlacesList head = (PlacesList) malloc(sizeof(PlacesList));
    if (head != NULL) {
        sprintf(head->InfoPlace.city, "%d", -1);
        sprintf(head->InfoPlace.info, "%d", -1);
        head->InfoPlace.WorkingHours.start_hour = -1;
        head->InfoPlace.WorkingHours.end_hour = -1;
        head->InfoPlace.WorkingHours.end_minute = -1;
        head->InfoPlace.WorkingHours.end_minute = -1;
        head->next = NULL;
    }
    return head;
}

