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
        head->InfoStudent.name = '1';
        head->InfoStudent.address = '1';
        head->InfoStudent.date_of_birth = '1';
        head->InfoStudent.phone_number = 1;
        head->next = NULL;
    }
    return head;
}

PlacesList BuildPlacesList() {
    PlacesList head = (PlacesList) malloc(sizeof(PlacesList));
    if (head != NULL) {
        head->InfoPlace.city = '1';
        head->InfoPlace.info = '1';
        head->InfoPlace.WorkingHours.start_hour = 1;
        head->InfoPlace.WorkingHours.end_hour = 1;
        head->InfoPlace.WorkingHours.end_minute = 1;
        head->InfoPlace.WorkingHours.end_minute = 1;
        head->next = NULL;
    }
    return head;
}

